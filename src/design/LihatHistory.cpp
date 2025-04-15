#include "menu.hpp"
#include "structs.hpp"
#include "history.hpp"

void d_LihatHistory(history *temp){

    if(temp != NULL) temp = tail_history;
    cout << temp -> no_antrian;

    cout << "-----------------------------------------------------------------" << endl;
    cout << "   No Antrian      : " << temp -> no_antrian << endl;;
    cout << "   Nama Pasien     : " << temp -> nama_pasien << endl;;
    cout << "   Keluhan Pasien  : " << temp -> keluhan << endl;;
    cout << "   Resep Obat: " << endl;
    for(int i = 0; i < 10; i++){
        if(temp -> resep_obat[i]){
            cout << "   " << i << ". " << temp->resep_obat[i][x]
        }
    }
    cout << "-----------------------------------------------------------------";
    cout << "|  1 - Lanjut List                                               |";
    cout << "|  2 - Mundur List                                               |";
    cout << "-----------------------------------------------------------------";
    while(true){
        cout << "\nSelect a feature? "; int confirmation;cin >> confirmation;
        switch (confirmation) {
            case 1:
                if(temp->prev == NULL) break;
                return d_LihatHistory(temp->next);
            break;
            default:
                if(temp->prev == NULL) break;
                return d_LihatHistory(temp->prev);
            break;
        }
    }
}