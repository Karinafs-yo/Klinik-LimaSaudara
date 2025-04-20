#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>
#include <vector>
using namespace std;

extern vector<string> obat;
extern vector<double> harga;
extern vector<int> stok;

int cariObat(const string& namaObat);

int cariObat(const vector<string>& obat, const string& namaObat);

bool loadData(const string& filename, 
            vector<string>& obat, 
            vector<double>& harga, 
            vector<int>& stok);

bool saveData(const string& filename,
              const vector<string>& obat,
              const vector<double>& harga,
              const vector<int>& stok);

vector<string> split(const string &s, char delimiter);

#endif