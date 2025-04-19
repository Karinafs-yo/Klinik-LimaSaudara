#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"
#include <limits>
#include <string>
#include <thread>
#include <chrono>

void d_LayaniAntrian()
{
    clearTerminal();
    // antrian *temp  = new antrian(); // Alokasi memori untuk pointer antrian baru
    // temp = findLastAntrian(); // Mendapatkan pointer ke antrian terakhir
    antrian *temp = findLastAntrian(); 

    if(temp == NULL) { 
        cout << "Tidak ada antrian yang tersedia. Mengembalikan Anda ke menu utama...";
        this_thread::sleep_for(chrono::milliseconds(1000));
        return;
    }

    cout << "-----------------------------------------------------------------" << endl;
    cout << "                       Layani Antrian ke-" << temp->no_antrian << endl;
    
    if (temp->nama_pasien != ""){ 
        cout << "   Nama      : " << temp->nama_pasien << endl; 
    } else {
        cout << "   Nama      : ";
        getline(cin, temp->nama_pasien);
    }

    if (temp->keluhan != ""){ 
        cout << "   Keluhan   : " << temp->keluhan << endl; 
    } else {
        cout << "   Keluhan   : ";
        getline(cin, temp->keluhan);
    }

    cout << "   Resep     : \n";
    // Cek apakah array resep_obat kosong atau tidak
    if(temp->banyak_resep < 1){
        d_PilihObat(temp); // Kalau kosong, panggil fungsi untuk memilih obat
    } else {
        for (int i = 0; i < temp->banyak_resep; i++) // Kalau sudah ada, tampilkan semua resep yang telah dipilih
        {
            if(temp -> resep_obat[i]){
                cout << "   " << i + 1 << ". " << temp->resep_obat[i][0] << "(" << temp->resep_obat[i][1] << ")         Rp. " << temp -> resep_obat[i][2] << endl;
            }
        }
        cout << "\n\n";
        cout << "                       " << (temp->is_bpjs ? "   BPJS  " : "Prioritas") << "                           " << endl;
        cout << "----------------------------------------------------------------";

        backupAntrian(temp);

        cout << "\n\n----------------------------------------------------------------" << endl;
        cout << "                       Klik 1 untuk Kembali                     " << endl;
        cout << "-------------------------------------------------------- Ketik: "; 
    }
    
    string c; 
    getline(cin, c);

    return;
}