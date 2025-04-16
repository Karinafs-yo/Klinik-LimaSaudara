#include "menu.hpp"
#include "antrian.hpp"
#include "structs.hpp"
#include "utils.hpp"

void d_BuatAntrianBaru()
{
    clearTerminal();
    string isBPJS;
    
    cout << "-------------------- Buat Antrian Baru --------------------" << endl;
    cout << "Pengguna BPJS (Ya/Tidak)? "; cin >> isBPJS;
    
    string no_antrian = createAntrian(isBPJS); // generate nomor antrian
    clearTerminal();
    cout << endl << "-------------- Nomor Antrian Berhasil Dibuat! -------------" << endl;
    cout << "                           " << no_antrian << "                                " << endl;
    cout << "-----------------------------------------------------------" << endl << endl;
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