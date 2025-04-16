#include "constant.hpp"
#include "structs.hpp"
#include "menu.hpp"

void d_PilihObat(antrian *temp)
{
    string input_obat;
    int input_pembelian, index_obat;

    cout << "-------------------------------------------------------------" << endl;
    cout << "Obat yang dibeli:                                          |" << endl;
    for(int i = 0; i < 10; i++){
        if(temp -> resep_obat[i]){
            cout << "   " << i << ". " << temp->resep_obat[i][1] << "(" << temp->resep_obat[i][2] << ")         Rp. " << temp -> resep_obat[i][3] << endl;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
    //info obat berdasarkan nama
    bool obatFinded = false;
    while (!obatFinded)
    {
        cout << "Masukkan Nama Obat? "; cin >> input_obat;
        index_obat = cariObat(input_obat);
        if(index_obat >= 0) obatFinded = true;
    }
    
    cout << "Nama Obat: " << input_obat << endl;
    cout << "Stok Obat: " << stok[index_obat] << endl;
    cout << "Harga Obat: " << harga[index_obat] << endl;

    cout << "Banyak Pembelian? "; cin >> input_pembelian;
    double total_harga = input_pembelian * harga[index_obat];
    cout << "Total Harga: " << total_harga << endl;
    temp -> resep_obat[temp -> banyak_resep][0] = obat[index_obat];
    temp -> resep_obat[temp -> banyak_resep][1] = stok[index_obat];
    temp -> resep_obat[temp -> banyak_resep][2] = harga[index_obat];
    temp -> banyak_resep++;

    cout << "Lanjut (y/n): "; string konfirmasi; cin >> konfirmasi;
    if (konfirmasi == "y"){
        d_PilihObat(temp);
    }else{
        d_LayaniAntrian();
    }
}