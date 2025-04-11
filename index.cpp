#include <iostream>
using namespace std;

//? Struct
struct antrian {
    string no_antrian;
    string nama_pasien;
    string keluhan;
    bool status;
    string resep_obat[10][3];
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

string obat[50] = {
    "Paracetamol", "Amoxicillin", "Ibuprofen", "Vitamin C", "Antasida",
    "Cetirizine", "Loperamide", "Omeprazole", "Aspirin", "Metformin",
    "Simvastatin", "Losartan", "Captopril", "Salbutamol", "Diazepam",
    "Chlorpheniramine", "Dexamethasone", "Ranitidine", "Mefenamic Acid", "Betadine",
    "Hydrocortisone", "Clindamycin", "Erythromycin", "Ketoconazole", "Fluconazole",
    "Albendazole", "Loratadine", "Promethazine", "Neurobion", "Sanmol",
    "Panadol", "Bodrex", "Mixagrip", "Woods", "Konidin",
    "Termorex", "Procold", "Paramex", "Antimo", "Paratusin",
    "Tolak Angin", "Sakatonik", "Becom-C", "Hemaviton", "Curcuma Plus",
    "Enervon-C", "Imboost", "Diapet", "Entrostop", "Minyak Kayu Putih"
};

double harga[50] = {
    5000, 12000, 8000, 3000, 4000,
    6000, 3500, 10000, 7500, 15000,
    18000, 20000, 17000, 11000, 9000,
    4500, 7000, 9500, 8500, 6500,
    12000, 14000, 13000, 10000, 12500,
    8000, 5000, 6000, 9000, 4000,
    5500, 5600, 5200, 5300, 5100,
    4500, 4600, 4700, 4800, 4900,
    3000, 3500, 3600, 3700, 3800,
    3900, 4000, 4100, 4200, 4300
};

int stok[50] = {
    50, 30, 40, 100, 60,
    45, 70, 35, 55, 25,
    40, 38, 28, 33, 65,
    90, 77, 46, 60, 30,
    32, 41, 50, 29, 35,
    55, 60, 58, 64, 70,
    80, 75, 72, 66, 68,
    50, 52, 49, 47, 45,
    85, 87, 78, 74, 90,
    65, 55, 62, 59, 73
}, jumlah_obat = 0;
antrian *head_bpjs = NULL;

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

void TampilkanObat()
{
    for (int i = 0; i < sizeof(obat) / sizeof(obat[0]); i++)
    {
        cout << obat[i] << "\t" << harga[i] << "\t" << stok[i] << endl;
    }
}



int main(){
TampilkanObat();
}