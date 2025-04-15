#include <iostream>
#include <antrian.hpp>
#include "menu.hpp"
#include "utils.hpp"
using namespace std;

void d_MenuUtama(){
    clearTerminal();
    antrian *temp = findLastAntrian();
    string firstLine = "", secondLine = "", thirdLine = "";
    //?Tolong perbaiki ini 😑
    // while(true){
    //     cout << temp -> no_antrian;
    //     firstLine += "-----";
    //     secondLine +="|  " + temp ->no_antrian + " |";
    //     thirdLine += "-----";
    //     temp = temp -> next;
    // }

    cout << firstLine << endl << secondLine << endl << thirdLine;

    cout << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|  1 - Buat Antrian Baru                                        |" << endl;
    cout << "|  2 - Layani Antrian Baru                                      |" << endl;
    cout << "|  3 - Lihat History                                            |" << endl;
    cout << "|  4 - Lihat Obat                                               |" << endl;
    cout << "|  5 - Keluar Program                                           |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "Pilih Fitur? "; int confirmation; cin >> confirmation;

    switch (confirmation)
    {
    case 1:
        loadingMenu("Buat Antrian Baru");
        d_BuatAntrianBaru();
        break;
    case 2:
        loadingMenu("Layani Antrian Baru");
        d_LayaniAntrian();
        break;
    case 3:
        loadingMenu("Lihat History");
        d_LihatHistory(NULL);
        break;
    case 4:
        loadingMenu("Lihat Obat");
        d_LihatObat();
        break;
    default:
        loadingMenu("Exiting Program");
        return;
    }
}
