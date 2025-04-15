#include "menu.hpp"
#include "antrian.hpp"
#include "structs.hpp"
#include "utils.hpp"

void d_BuatAntrianBaru()
{
    string isBPJS;
    
    cout << "-------------------- Buat Antrian Baru --------------------" << endl;
    cout << "BPJS (Ya/Tidak) = "; cin >> isBPJS;
    
    string no_antrian = createAntrian(isBPJS);

    cout << "No Antrian: " << no_antrian; cout << endl;
    cout << "-----------------------------------------------------------" << endl << endl;
    cout << "-------------- Nomor Antrian Berhasil Dibuat! -------------" << endl;
    cout << "Apakah ingin membuat antrian baru lagi? (Ya/Tidak) = "; cin >> isBPJS;
    if (isBPJS == "Ya" || isBPJS == "ya")
    {
        d_BuatAntrianBaru();
    }
    else
    {
        clearTerminal();
        d_MenuUtama();
    }
}