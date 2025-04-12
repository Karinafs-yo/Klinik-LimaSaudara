#include "utils.hpp"
#include "structs.hpp"

void createDummy(){
    antrian *newAntrian = new antrian;
    newAntrian -> no_antrian = "A0";
    newAntrian -> nama_pasien = "Dummy";
    newAntrian -> keluhan = "Dummy";
    newAntrian -> is_bpjs= false;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            newAntrian->resep_obat[i][j] = "Dummy";
        }
    }
    head_bpjs = newAntrian;
    tail_bpjs = newAntrian;

    history *newHistory = new history;
    newHistory -> no_antrian = "B0";
    newHistory -> nama_pasien = "Dummy";
    newHistory -> keluhan = "Dummy";
    newHistory -> is_bpjs= false;
    head_history = newHistory;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            newHistory->resep_obat[i][j] = "Dummy";
        }
    }

    tail_history = newHistory;
}