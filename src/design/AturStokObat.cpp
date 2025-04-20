#include "menu.hpp"
#include "constant.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void d_AturStok() {
    string obatName;
    bool found = false;
    int index = -1;
    int newStock = 0;
    
    clearTerminal();
    
    cout << left << setw(5) << "No" 
         << setw(25) << "Nama Obat"
         << setw(10) << "Harga" 
         << setw(10) << "Stok" << endl;
    cout << string(50, '-') << endl;
    
    for (size_t i = 0; i < obat.size(); i++) {
        cout << left << setw(5) << (i + 1)
             << setw(25) << obat[i]
             << setw(10) << harga[i]
             << setw(10) << stok[i]
             << endl;
    }
    
    cout << "\nMasukkan Nama Obat yang akan diupdate: ";
    getline(cin, obatName);
    for (char& c : obatName) {
        c = tolower(c);
    }
    obatName[0] = toupper(obatName[0]);

    index = cariObat(obatName);
    if (index >= 0) {
        found = true;
        cout << "\nNama: " << obat[index] << endl;
        cout << "Harga: " << harga[index] << endl;
        cout << "Stok saat ini: " << stok[index] << endl;
        
        cout << "\nMasukkan stok baru untuk " << obat[index] << ": ";
        cin >> newStock;
        
        if (newStock >= 0) {
            stok[index] = newStock;
            cout << "\nStok berhasil diupdate!" << endl;
            cout << "Stok " << obat[index] << " sekarang: " << stok[index] << endl;
            
            saveData("src/var/obat.csv", obat, harga, stok);
        } else {
            cout << "\nEStok tidak bisa negatif." << endl;
        }
    } else {
        cout << "\nObat dengan nama '" << obatName << "' tidak ditemukan." << endl;
    }
    
    cout << "\n-----------------------------------------------------------------" << endl;
    cout << "                       Klik 1 untuk Kembali                     " << endl;
    cout << "-------------------------------------------------------- Ketik: ";
    int c; 
    cin >> c;
    return;
}