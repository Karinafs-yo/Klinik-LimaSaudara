#include "menu.hpp"
#include "structs.hpp"
#include "history.hpp"
#include "utils.hpp"

void d_LihatHistory(history *temp)
{
    clearTerminal();
    if (temp == NULL) temp = tail_history;

    cout << "-----------------------------------------------------------------" << endl;
    cout << "   No Antrian      : " << temp->no_antrian << endl;
    cout << "   Antrian " << (temp->is_bpjs ? "BPJS" : "Prioritas") << endl;
    cout << "   Nama Pasien     : " << temp->nama_pasien << endl;
    cout << "   Keluhan Pasien  : " << temp->keluhan << endl;
    cout << "   Resep Obat: " << endl;
    for (int i = 0; i < temp->banyak_resep; i++) cout << "   " << i + 1 << ". " << temp->resep_obat[i][0] << "(" << temp->resep_obat[i][1] << ")         Rp. " << temp->resep_obat[i][2] << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|  1 - Maju List                                                 |" << endl;
    cout << "|  2 - Mundur List                                               |" << endl;
    cout << "|  3 - Kembali ke Menu Utama                                               |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    while (true)
    {
        cout << "Pilih Fitur? "; int confirmation; cin >> confirmation;
        switch (confirmation)
        {
        case 1:
            if (temp->next != NULL) return d_LihatHistory(temp->next);
            clearOneLine();
        break;
        case 2:
            if (temp->prev != NULL) return d_LihatHistory(temp->prev);
            clearOneLine();
        break;
        default:
            clearTerminal();
            d_MenuUtama();
        break;
        }
    }
}