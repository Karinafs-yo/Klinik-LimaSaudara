#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <string>
using namespace std;

struct antrian {
    string no_antrian;
    string nama_pasien;
    string keluhan;
    bool is_bpjs;
    int banyak_resep = 0;
    string resep_obat[10][3];
    antrian *next = NULL, *prev = NULL;
};

struct history {
    string no_antrian;
    string nama_pasien;
    string keluhan;
    bool is_bpjs;
    int banyak_resep = 0;
    string resep_obat[10][3];
    history *next = NULL, *prev = NULL;
};

extern antrian *head_bpjs, *tail_bpjs, *head_prioritas, *tail_prioritas;
extern history *head_history, *tail_history;
extern int antrian_bpjs, antrian_prioritas;
#endif