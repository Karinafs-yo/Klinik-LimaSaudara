#ifndef ANTRIAN_HPP
#define ANTRIAN_HPP

#include <iostream>
#include "structs.hpp"
using namespace std;

string createAntrian(string isBPJS);
antrian* findLastAntrian();
void backupAntrian(antrian *hapus);

#endif
