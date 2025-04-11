#include <iostream>
using namespace std;

//? Struct
struct antrian {
    string no_antrian;
    string nama_pasien;
    string keluhan;
    bool status;
    string resep_obat[][];
    antrian *next, *prev;
};

struct history {
    string no_antrian;
    string nama_pasien;
    string keluhan;
    bool status;
    string resep_obat[][];
    history *next, *prev;
};

string obat[];
double harga;
int stok, jumlah_obat = 0;
antrian *head_bpjs = NULL;

//? Function
void antrianBaru()
{
    string isBPJS;
    cout << "BPJS = Ya / Tidak? "; cin >> isBPJS;

    if (isBPJS == "Ya")
    {
        
    }
}



int main(){

}