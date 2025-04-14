#include "menu.hpp"
#include "constant.hpp"

void d_LihatObat(){
    for (int i = 0; i < sizeof(obat) / sizeof(string); i++)
    {
        cout << obat[i] << "\t" << harga[i] << "\t" << stok[i] << endl;
    }
}