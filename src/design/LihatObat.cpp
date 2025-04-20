#include "menu.hpp"
#include "constant.hpp"
#include "utils.hpp"
#include "iomanip"

void d_LihatObat() // Fungsi untuk menampilkan daftar obat dalam format tabel
{
    clearTerminal();

    cout << left << setw(5) << "No" // Menampilkan nomor antrian, lebar 5 karakter
         << setw(25) << "Nama Obat" // Menampilkan nama obat, lebar 25 karakter
         << setw(10) << "Harga" // Menampilkan harga, lebar 10 karakter
         << setw(10) << "Stok" << endl; // Menampilkan stok obat, lebar 10 karakter

    cout << string(50, '-') << endl;  // Menampilkan garis horizontal sebagai pemisah antara header dan data

    for (size_t i = 0; i < obat.size(); i++) // Menampilkan data obat
    {
        cout << left << setw(5) << (i + 1)
             << setw(25) << obat[i]
             << setw(10) << harga[i]
             << setw(10) << stok[i]
             << endl;
    }

    cout << "\n\n----------------------------------------------------------------" << endl;
    cout << "                       Klik 1 untuk Kembali                     " << endl;
    cout << "-------------------------------------------------------- Ketik: "; int c; cin >> c; return;
}