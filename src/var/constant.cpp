#include "constant.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

    // string obat[50] = {
    //     "Paracetamol", "Amoxicillin", "Ibuprofen", "Vitamin C", "Antasida",
    //     "Cetirizine", "Loperamide", "Omeprazole", "Aspirin", "Metformin",
    //     "Simvastatin", "Losartan", "Captopril", "Salbutamol", "Diazepam",
    //     "Chlorpheniramine", "Dexamethasone", "Ranitidine", "Mefenamic Acid", "Betadine",
    //     "Hydrocortisone", "Clindamycin", "Erythromycin", "Ketoconazole", "Fluconazole",
    //     "Albendazole", "Loratadine", "Promethazine", "Neurobion", "Sanmol",
    //     "Panadol", "Bodrex", "Mixagrip", "Woods", "Konidin",
    //     "Termorex", "Procold", "Paramex", "Antimo", "Paratusin",
    //     "Tolak Angin", "Sakatonik", "Becom-C", "Hemaviton", "Curcuma Plus",
    //     "Enervon-C", "Imboost", "Diapet", "Entrostop", "Minyak Kayu Putih"
    // };

    // double harga[50] = {
    //     5000, 12000, 8000, 3000, 4000,
    //     6000, 3500, 10000, 7500, 15000,
    //     18000, 20000, 17000, 11000, 9000,
    //     4500, 7000, 9500, 8500, 6500,
    //     12000, 14000, 13000, 10000, 12500,
    //     8000, 5000, 6000, 9000, 4000,
    //     5500, 5600, 5200, 5300, 5100,
    //     4500, 4600, 4700, 4800, 4900,
    //     3000, 3500, 3600, 3700, 3800,
    //     3900, 4000, 4100, 4200, 4300
    // };

    // int stok[50] = {
    //     50, 30, 40, 100, 60,
    //     45, 70, 35, 55, 25,
    //     40, 38, 28, 33, 65,
    //     90, 77, 46, 60, 30,
    //     32, 41, 50, 29, 35,
    //     55, 60, 58, 64, 70,
    //     80, 75, 72, 66, 68,
    //     50, 52, 49, 47, 45,
    //     85, 87, 78, 74, 90,
    //     65, 55, 62, 59, 73
    // };

    // int cariObat(string namaObat) { 
    //     for (int i = 0; i < 50; i++) {
    //         if (obat[i] == namaObat) return i;
    //     } return -1;
    // }


    vector<string> obat;
    vector<double> harga;
    vector<int> stok;


    // Function untuk memisahkan string dengan delimiter
    vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }


    // Function untuk ngeload data di dalam CSV
    bool loadData(const string& filename, 
                        vector<string>& obat, 
                        vector<double>& harga, 
                        vector<int>& stok) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Gagal membuka file: " << filename << endl;
            return false;
            }

            obat.clear();
            harga.clear();
            stok.clear();

            string line;

            getline(file, line);

            while (getline(file, line)) {
                vector<string> fields = split(line, ',');
                if (fields.size() >= 3) {
                    obat.push_back(fields[0]);
                    harga.push_back(stod(fields[1]));
                    stok.push_back(stoi(fields[2]));
                }
        }

    return true;
    }


    // Function untuk menyimpan data ke file CSV
    bool saveData(const string& filename,
        const vector<string>& obat,
        const vector<double>& harga,
        const vector<int>& stok) {

    if (obat.size() != harga.size() || obat.size() != stok.size()) {
    cerr << "Ukuran vector tidak sama" << endl;
    return false;
    }

    ofstream file(filename);
    if (!file.is_open()) {
    cerr << "Gagal membuka file: " << filename << endl;
    return false;
    }

    file << "name,price,stock" << endl;

    for (size_t i = 0; i < obat.size(); i++) {
    file << obat[i] << "," << harga[i] << "," << stok[i] << endl;
    }

    return true;
    }
    

    // Function untuk nyari obat
    int cariObat(const vector<string>& obat, const string& namaObat) {
        for (size_t i = 0; i < obat.size(); i++) {
            if (obat[i] == namaObat) {
                return i;
            }
        }
        return -1;
    }

    // Function kedua untuk backward compatibility
    int cariObat(const string& namaObat) {
        return cariObat(obat, namaObat);
    }
