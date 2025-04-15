#include <iostream>
#include "menu.hpp"
#include "utils.hpp"
using namespace std;

int main()
{
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|  1 - Buat Antrian Baru                                    |" << endl;
    cout << "|  2 - Layani Antrian Baru                                  |" << endl;
    cout << "|  3 - Lihat History                                        |" << endl;
    cout << "|  4 - Lihat Obat                                           |" << endl;
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
    default:
        loadingMenu("Lihat Obat");
        d_LihatObat();
        break;
    }
}
