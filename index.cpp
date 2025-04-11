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
    string resep_obat[10][3];
    history *next, *prev;
};

string obat[];
double harga;
int stok, jumlah_obat = 0, no_antrian_BPJS = 0, no_antrian_general = 0;
antrian *head_bpjs = NULL, *tail_bpjs = NULL, *head_general = NULL, *tail_general = NULL;

//? Function
void antrianBaru()
{
    string isBPJS;
    cout << "BPJS = Ya / Tidak? "; cin >> isBPJS;
    antrian *newAntrian = new antrian;

    if (isBPJS == "Ya")
    {
        newAntrian -> no_antrian = "B" + to_string(no_antrian_BPJS++);
        if (head_bpjs == NULL)
        {
            newAntrian -> prev = tail_general;
            head_bpjs = newAntrian;
            tail_bpjs = newAntrian;
        }
        else
        {
            newAntrian -> prev = tail_bpjs;
            tail_bpjs = newAntrian;
        }
    }
    else if (isBPJS == "Tidak")
    {
        newAntrian -> no_antrian = "A" + to_string(no_antrian_general++);
        if (head_general == NULL)
        {
            head_general = newAntrian;
            tail_general = newAntrian;
        }
        else
        {
            tail_general -> next = newAntrian;
            newAntrian->prev = tail_general;
            tail_general = newAntrian;
        }
    }
    cout << "No Antrian: " << newAntrian -> no_antrian << endl;
}



int main(){

}