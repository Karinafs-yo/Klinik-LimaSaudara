#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"

void d_LayaniAntrian()
{
    antrian *temp  = new antrian();
    *temp = findLastAntrian();
    cout << endl;
    cout << "┌───────────────────────────────────────────────────────────────┐";
    cout << "               Layani Antrian ke-" << temp->no_antrian;
    cout << "   👤Nama      : "; cin >> temp -> nama_pasien;
    cout << "   😣Keluhan   : "; cin >> temp -> keluhan;
    cout << "   📃Resep     : \n";
    if(lengthArrayString(temp->resep_obat) < 1){
        //tambah Obat
    }else {
        for(int i = 0; i < lengthArrayString(temp->resep_obat); i++){
            for (int i = 0; )
        }
    cout << "   ";
    }
    cout << "└───────────────────────────────────────────────────────────────┘";
}