#include <iostream>
#include <antrian.hpp>
#include "menu.hpp"
#include "utils.hpp"
#include <thread>
#include <chrono>
#include <limits>
using namespace std;

void d_MenuUtama()
{
    while (true) {
        clearTerminal();
        
        antrian *temp = findLastAntrian();

        string firstLine = "", secondLine = "", thirdLine = "";
        while (temp != NULL)
        {
            firstLine += "  ------";
            secondLine += "  | " + temp->no_antrian + " |";
            thirdLine += "  ------";
            temp = temp->next;
        }

        if (firstLine != "")
            cout << firstLine << endl << secondLine << endl << thirdLine;

        cout << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "|  1 - Buat Antrian Baru                                        |" << endl;
        cout << "|  2 - Layani Antrian Baru                                      |" << endl;
        cout << "|  3 - Lihat History                                            |" << endl;
        cout << "|  4 - Lihat Obat                                               |" << endl;
        cout << "|  5 - Atur Stok Obat                                           |" << endl;
        cout << "|  6 - Keluar Program                                           |" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Pilih Fitur? ";

        int confirmation;
        if(!(cin >> confirmation)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Tolong masukkan input yang valid.";
            this_thread::sleep_for(chrono::milliseconds(1000));
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //cin >> confirmation;

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
        case 5:
            loadingMenu("Atur Stok Obat");;
            d_AturStok();
            break;
        case 6:
            loadingMenu("Exiting Program");
            return;
        default:
            cout << endl << "Tolong masukkan input yang valid.";
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
}