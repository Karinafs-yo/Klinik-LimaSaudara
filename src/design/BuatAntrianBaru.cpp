#include "menu.hpp"
#include "antrian.hpp"
#include "structs.hpp"
#include "utils.hpp"
#include <limits>

void d_BuatAntrianBaru()
{
    string isBPJS;
    bool validInput = false;

    while (!validInput){
        clearTerminal();

        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "-------------------- Buat Antrian Baru --------------------" << endl;
        cout << "Pengguna BPJS (Y/n)? "; cin >> isBPJS;

        if (isBPJS == "Y" || isBPJS == "y" || isBPJS == "N" || isBPJS == "n") {
            validInput = true;
        }
    }
        
    string no_antrian = createAntrian(isBPJS); // generate nomor antrian
    clearTerminal();
    cout << endl << "-------------- Nomor Antrian Berhasil Dibuat! -------------" << endl;
    cout << "                           " << no_antrian << "                                " << endl;
    cout << "-----------------------------------------------------------" << endl << endl;

    validInput = false;
    while (!validInput){
        cout << "Apakah ingin membuat antrian baru lagi? (Y/n) = "; cin >> isBPJS;
        if (isBPJS == "Y" || isBPJS == "y")
        {
            validInput = true;
            d_BuatAntrianBaru();
        }
        else if (isBPJS == "N" || isBPJS == "n")
        {
            clearTerminal();
            return;
        }
        clearOneLine();
    }
}