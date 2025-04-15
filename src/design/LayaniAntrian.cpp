#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"

void d_LayaniAntrian()
{
    antrian *temp  = new antrian();
    temp = findLastAntrian();

    cout << "┌───────────────────────────────────────────────────────────────┐";
    cout << "               Layani Antrian ke-" << temp->no_antrian;
    cout << "   👤Nama      : "; cin >> temp -> nama_pasien;
    cout << "   😣Keluhan   : "; cin >> temp -> keluhan;
    cout << "   📃Resep     : \n";
    if((sizeof(temp->resep_obat) / sizeof(temp->resep_obat[0])) < 1){
        d_PilihObat();
    } else {
        for(int i = 0; i < 10; i++){
            for (int y = 0; y < 3; y++){
                if(temp -> resep_obat[i]) cout << "   " << i << ". " << temp->resep_obat[i][1] << "(" << temp->resep_obat[i][2] << ")         Rp. " << temp -> resep_obat[i][3] << endl;
            }
        }
    cout << "   ";}
    cout << "                            " << (temp->is_bpjs ? "   BPJS  " : "Prioritas") << "                           " << endl;
    cout << "└───────────────────────────────────────────────────────────────┘";
}