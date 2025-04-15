#include "history.hpp"

void formatInvoice(history *temp)
{
    cout << temp -> no_antrian;
    cout << "=========== Antrian " << temp->no_antrian << "==============" << endl;
    cout << "Nama Pasien: " << temp->nama_pasien << endl;
    cout << "Keluhan: " << temp->keluhan << endl;
    cout << "Resep: " << endl;
    cout << "" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (temp->resep_obat[i][0] != "")
        {
            cout << temp->resep_obat[i][0] << " - " << temp->resep_obat[i][0] << " (" << temp->resep_obat[i][1] << ")           " << temp->resep_obat[i][2] << endl;
        }
    }
    cout << "=============" << (temp->is_bpjs ? "BPJS" : "PRIORITAS") << "============" << endl;
}