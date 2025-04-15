#include "menu.hpp"
#include "structs.hpp"
#include "history.hpp"

void d_LihatHistory(history *temp){
    if(temp != NULL) temp = tail_history;

    cout << "-----------------------------------------------------------------" << endl;
    cout << "   No Antrian      : " << temp -> no_antrian << endl;;
    cout << "   Nama Pasien     : " << temp -> nama_pasien << endl;;
    cout << "   Keluhan Pasien  : " << temp -> keluhan << endl;;
    cout << "   Resep Obat: " << endl;
    for(int i = 0; i < 10; i++){
        if(temp -> resep_obat[i]) cout << "   " << i << ". " << temp->resep_obat[i][1] << "(" << temp->resep_obat[i][2] << ")         Rp. " << temp -> resep_obat[i][3] << endl;
    }
    cout << "   Antrian " << (temp->is_bpjs ? "BPJS" : "Prioritas") << endl << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|  1 - Lanjut List                                               |" << endl;
    cout << "|  2 - Mundur List                                               |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    while(true){
        cout << "\nPilih Fitur? "; int confirmation;cin >> confirmation;
        switch (confirmation) {
            case 1:
                // if(temp->prev == NULL) break;
                // return d_LihatHistory(temp->next);
            break;
            default:
                // if(temp->prev == NULL) break;
                // return d_LihatHistory(temp->prev);
            break;
        }
    }
}