#include "menu.hpp"
#include "structs.hpp"
#include "antrian.hpp"
#include "utils.hpp"

void d_LayaniAntrian()
{
    antrian *temp  = new antrian();
    temp = findLastAntrian();

    cout << "-----------------------------------------------------------------" << endl;
    cout << "               Layani Antrian ke-" << temp->no_antrian << endl;
    cout << "   Nama      : "; cin >> temp -> nama_pasien; cout << endl;
    cout << "   Keluhan   : "; cin >> temp -> keluhan; cout << endl;
    cout << "   Resep     : \n";
    if((sizeof(temp->resep_obat) / sizeof(temp->resep_obat[0])) < 1){
        d_PilihObat(temp);
    } else {
        for (int i = 0; i < temp->banyak_resep; i++) cout << "   " << i + 1 << ". " << temp->resep_obat[i][0] << "(" << temp->resep_obat[i][1] << ")         Rp. " << temp->resep_obat[i][2] << endl;
    }
    cout << "   ";
    cout << "                            " << (temp->is_bpjs ? "   BPJS  " : "Prioritas") << "                           " << endl;
    cout << "-----------------------------------------------------------------";
}