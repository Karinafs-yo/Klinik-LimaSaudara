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
        //tambah Obat
    }else {
        for(int i = 0; i < 10; i++){
            for (int y = 0; y < 3; y++){

            }
        }
    cout << "   ";}
    cout << "└───────────────────────────────────────────────────────────────┘";
}