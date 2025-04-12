#include "menu.hpp"
#include "constant.hpp"

void d_LihatObat(){
    for (int i = 0; i < sizeof(obat) / sizeof(obat[0]); i++)
    {
        cout << obat[i] << "\t" << harga[i] << "\t" << stok[i] << endl;
    }
}