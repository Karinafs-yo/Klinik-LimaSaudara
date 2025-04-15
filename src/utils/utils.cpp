#include "utils.hpp"
#include <cstdlib>
#include <thread>
#include <chrono>
#include "structs.hpp"
using namespace std;

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
    newHistory -> banyak_resep= 10;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            newHistory->resep_obat[i][j] = "Dummy";
        }
    }
    head_history = newHistory;
    
    history *newSecondHistory = new history;
    newSecondHistory -> no_antrian = "B1";
    newSecondHistory -> nama_pasien = "Dummy";
    newSecondHistory -> keluhan = "Dummy";
    newSecondHistory -> is_bpjs= false;
    newSecondHistory -> banyak_resep= 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            newSecondHistory->resep_obat[i][j] = "Dummy";
        }
    }
    newSecondHistory ->prev = newHistory;
    newHistory->next = newSecondHistory;
    
    tail_history = newSecondHistory;
}

void loadingMenu(string menuName){
    int repeatFor = 3;
    for(int i = 0; i < repeatFor; i++){
        clearTerminal();
        cout << "-----------------------------------------------------------------" << endl;
        cout << "                   " << endl;
        cout << "                   " << menuName << "." << endl;
        cout << "                   " << endl;
        cout << "-----------------------------------------------------------------" << endl;
        // this_thread::sleep_for(chrono::milliseconds(300));
        clearTerminal();
        cout << "-----------------------------------------------------------------" << endl;
        cout << "                   " << endl;
        cout << "                   " << menuName << ".." << endl;
        cout << "                   " << endl;
        cout << "-----------------------------------------------------------------" << endl;
        // this_thread::sleep_for(chrono::milliseconds(300));
        clearTerminal();
        cout << "-----------------------------------------------------------------" << endl;
        cout << "                   " << endl;
        cout << "                   " << menuName << "..." << endl;
        cout << "                   " << endl;
        cout << "-----------------------------------------------------------------" << endl;
        // this_thread::sleep_for(chrono::milliseconds(300));
        clearTerminal();
    }
}

void clearTerminal(){ system("cls"); }
void clearOneLine(){
    // Move cursor up one line
    cout << "\033[1A";

    // Clear the entire line
    cout << "\033[2K";

    // Optionally move back to the beginning of the line
    cout << "\r";
}
