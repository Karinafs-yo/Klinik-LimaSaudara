#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"

void d_LayaniAntrian()
{
    antrian *temp  = new antrian();
    temp = findLastAntrian();

    cout << "----------------------------------------------------------------" << endl;
    cout << "               Layani Antrian ke-" << temp->no_antrian << endl;
    cout << "   Nama      : "; cin >> temp -> nama_pasien;
    cout << "   Keluhan   : "; cin >> temp -> keluhan;
    cout << "   Resep     : \n";
    if(temp->banyak_resep < 1){
        d_PilihObat(temp);
    } else {
        cout << sizeof(temp->resep_obat) / sizeof(temp->resep_obat[0]);
    }
    cout << "   ";
    cout << "                            " << (temp->is_bpjs ? "   BPJS  " : "Prioritas") << "                           " << endl;
    cout << "----------------------------------------------------------------";
}