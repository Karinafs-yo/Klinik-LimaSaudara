#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"

void d_LayaniAntrian()
{
    clearTerminal();
    antrian *temp  = new antrian();
    temp = findLastAntrian();

    cout << "-----------------------------------------------------------------" << endl;
    cout << "                       Layani Antrian ke-" << temp->no_antrian << endl;
    cout << "   Nama      : "; if (temp->nama_pasien != ""){ 
        cout << temp->nama_pasien << endl; 
    } else cin >> temp -> nama_pasien; 

    cout << "   Keluhan   : "; if (temp->keluhan != ""){ 
        cout << temp->keluhan << endl; 
    } else cin >> temp -> keluhan; 

    cout << "   Resep     : \n";
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


}