#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"
#include <string>

void d_LayaniAntrian()
{
    antrian *temp  = new antrian(); // Alokasi memori untuk pointer antrian baru
    temp = findLastAntrian();  // Mendapatkan pointer ke antrian terakhir

    cout << "-----------------------------------------------------------------" << endl;
    cout << "                       Layani Antrian ke-" << temp->no_antrian << endl;
    cout << "   Nama      : "; if (temp->nama_pasien != ""){ 
        cout << temp->nama_pasien << endl; 
    } else cin >> temp -> nama_pasien; 

    cout << "   Keluhan   : "; if (temp->keluhan != ""){ 
        cout << temp->keluhan << endl; 
    } else cin >> temp->keluhan;

    cout << "   Resep     : \n";
<<<<<<< HEAD
   
    // Cek apakah array resep_obat kosong atau tidak
    if((sizeof(temp->resep_obat) / sizeof(temp->resep_obat[0])) < 1){
        d_PilihObat(temp); // Kalau kosong, panggil fungsi untuk memilih obat
    } else {
        for (int i = 0; i < temp->banyak_resep; i++) // Kalau sudah ada, tampilkan semua resep yang telah dipilih
        cout << "   " << i + 1 << ". " << temp->resep_obat[i][0] 
             << "(" << temp->resep_obat[i][1] << ")         
             Rp. " << temp->resep_obat[i][2] << endl;
    } 
    cout << "   ";
    cout << "                            " << (temp->is_bpjs ? "   BPJS  " : "Prioritas") << "                           " << endl;
    cout << "└───────────────────────────────────────────────────────────────┘";
=======
    if(temp->banyak_resep < 1){
        d_PilihObat(temp);
    } else {
        for(int i = 0; i < temp ->banyak_resep; i++){
            if(temp -> resep_obat[i]){
                cout << "   " << i + 1 << ". " << temp->resep_obat[i][0] << "(" << temp->resep_obat[i][1] << ")         Rp. " << temp -> resep_obat[i][2] << endl;
            }
        }
    }
    cout << "\n\n";
    cout << "                       " << (temp->is_bpjs ? "   BPJS  " : "Prioritas") << "                           " << endl;
    cout << "----------------------------------------------------------------";

    backupAntrian(temp);

    cout << "\n\n----------------------------------------------------------------" << endl;
    cout << "                       Klik 1 untuk Kembali                     " << endl;
    cout << "-------------------------------------------------------- Ketik: "; int c; cin >> c; c ? d_MenuUtama() : d_MenuUtama(); 


>>>>>>> 03233d11b1601e390490eb78324ee92756379014
}