#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"

void d_LayaniAntrian()
{
    antrian *temp  = new antrian(); // Alokasi memori untuk pointer antrian baru
    temp = findLastAntrian();  // Mendapatkan pointer ke antrian terakhir

    cout << "----------------------------------------------------------------" << endl;
    cout << "               Layani Antrian ke-" << temp->no_antrian << endl;
    cout << "   Nama      : "; cin >> temp -> nama_pasien;
    cout << "   Keluhan   : "; cin >> temp -> keluhan;
    cout << "   Resep     : \n";
   
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
}