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
    
<<<<<<< HEAD
    string no_antrian = createAntrian(isBPJS); //generate nomor antrian

    cout << "No Antrian: " << no_antrian; cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "-------------- Nomor Antrian Berhasil Dibuat! -------------" << endl;
=======
    string no_antrian = createAntrian(isBPJS);
    clearTerminal();
    cout << endl << "-------------- Nomor Antrian Berhasil Dibuat! -------------" << endl;
    cout << "                           " << no_antrian << "                                " << endl;
    cout << "-----------------------------------------------------------" << endl << endl;
>>>>>>> 03233d11b1601e390490eb78324ee92756379014
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