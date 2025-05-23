#include "constant.hpp"
#include "structs.hpp"
#include "menu.hpp"
#include "utils.hpp"
#include <thread>
#include <chrono>

void d_PilihObat(antrian *temp)
{
    string input_obat;
    int input_pembelian, index_obat;

    clearTerminal();
    cout << "-------------------------------------------------------------" << endl;
    cout << "Obat yang dibeli:                                          |" << endl;
    for(int i = 0; i < temp ->banyak_resep; i++){
        if(temp -> resep_obat[i]){
            cout << "   " << i + 1 << ". " << temp->resep_obat[i][0] << "(" << temp->resep_obat[i][1] << ")         Rp. " << temp -> resep_obat[i][2] << endl;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
    //info obat berdasarkan nama
    bool obatFinded = false;
    while (!obatFinded)
    {
        cout << "Masukkan Nama Obat? "; getline(cin, input_obat);
        for (char& c : input_obat) {
            c = tolower(c);
        }
        input_obat[0] = toupper(input_obat[0]);
        index_obat = cariObat(input_obat);
        if(index_obat >= 0){ obatFinded = true;
        } else clearOneLine();
    }
    
    cout << "\nNama Obat: " << input_obat << endl;
    cout << "Stok Obat: " << stok[index_obat] << endl;
    cout << "Harga Obat: " << harga[index_obat] << endl << endl;

    bool outOfStock = true;
    while (outOfStock) {
        cout << "Banyak Pembelian? "; cin >> input_pembelian;
        if (stok[index_obat] - input_pembelian < 0) { // mengecek untuk pembelian obat yang melebihi stok obat
            cout << "Obat tidak punya stok sebanyak itu."; 
            clearOneLine();
        } else if (input_pembelian == 0) { // jika input-nya 0, CLI akan kembali ke menu pilih obat
            d_PilihObat(temp); 
            break;
        } else { outOfStock = false; }
    }

    // cout << "Banyak Pembelian? "; cin >> input_pembelian;

    int total_harga = input_pembelian * harga[index_obat];
    cout << "\nTotal Harga: " << total_harga << endl;
    temp -> resep_obat[temp -> banyak_resep][0] = input_obat;
    temp -> resep_obat[temp -> banyak_resep][1] = to_string(input_pembelian);
    temp -> resep_obat[temp -> banyak_resep][2] = to_string(total_harga);
    temp -> banyak_resep++;

    stok[index_obat] -= input_pembelian;
    saveData("src/var/obat.csv", obat, harga, stok);

    while (true){
        cout << "\nLanjut Mengisi? (Y/n): "; string konfirmasi; cin >> konfirmasi;
        if (konfirmasi == "Y" || konfirmasi == "y"){
            d_PilihObat(temp);
            break;
        } else if (konfirmasi == "N" || konfirmasi == "n") {
            d_LayaniAntrian();
            return;
        } else {
            cout << "Tolong masukkan input yang valid.";
            clearOneLine();
            clearOneLine();
        }
    }
}