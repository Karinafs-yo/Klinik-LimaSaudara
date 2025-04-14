#include "menu.hpp"
#include "structs.hpp"
#include "history.hpp"

void d_LihatHistory(history *temp){

    if(temp != NULL) temp = tail_history;
    formatInvoice(temp);

    cout << endl;
    cout << "┌───────────────────────────────────────────────────────────────┐";
    cout << "|  N. ⏭️ - Next                                                 |";
    cout << "|  B. ⏮️ - Back                                                 |";
    cout << "└───────────────────────────────────────────────────────────────┘";
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