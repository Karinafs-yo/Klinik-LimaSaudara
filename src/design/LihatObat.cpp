#include "menu.hpp"
#include "constant.hpp"
#include "iomanip"

void d_LihatObat(){
    cout << left << setw(5) << "No" 
         << setw(25) << "Nama Obat" 
         << setw(10) << "Harga" 
         << setw(10) << "Stok" << endl;

    cout << string(50, '-') << endl;

    for (int i = 0; i < 50; i++)
    {
        cout << left << setw(5) << (i + 1)
             << setw(25) << obat[i]
             << setw(10) << harga[i]
             << setw(10) << stok[i]
             << endl;
    }

    cout << "\n\n----------------------------------------------------------------" << endl;
    cout << "                       Klik 1 untuk Kembali                     " << endl;
    cout << "-------------------------------------------------------- Ketik: "; int c; cin >> c; c ? d_MenuUtama() : d_MenuUtama(); 
}