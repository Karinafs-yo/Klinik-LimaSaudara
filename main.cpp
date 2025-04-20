#include <iostream>
#include <antrian.hpp>
#include "menu.hpp"
#include "utils.hpp"
#include <constant.hpp>
using namespace std;

int main()
{
    // createDummy();
    
    const string filename = "src/var/obat.csv";
    loadData(filename, obat, harga, stok);

    d_MenuUtama();

    saveData(filename, obat, harga, stok);
}