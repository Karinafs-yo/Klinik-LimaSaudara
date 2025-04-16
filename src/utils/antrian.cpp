#include "antrian.hpp"
#include "structs.hpp"

string createAntrian(string isBPJS)
{
    antrian *newAntrian = new antrian;

    if (isBPJS == "Ya" || isBPJS == "ya")
    {
        newAntrian->no_antrian = "B" + to_string(antrian_bpjs++);
        if (head_bpjs == NULL)
        {
            if(tail_prioritas != NULL){
                newAntrian->prev = tail_prioritas;
                tail_prioritas->next = newAntrian;
            }
            head_bpjs = newAntrian;
            tail_bpjs = newAntrian;
        }
        else
        {
            newAntrian->prev = tail_bpjs;
            tail_bpjs -> next = newAntrian;
            tail_bpjs = newAntrian;
        }
    }
    else
    {
        newAntrian->no_antrian = "A" + to_string(antrian_prioritas++);
        if (head_prioritas == NULL)
        {
            if(head_bpjs != NULL) newAntrian -> next = head_bpjs;
            head_prioritas = newAntrian;
            tail_prioritas = newAntrian;
        }
        else
        {
            newAntrian->next = tail_prioritas -> next;
            tail_prioritas->next = newAntrian;
            newAntrian->prev = tail_prioritas;
            tail_prioritas = newAntrian;
        }
    }
    return newAntrian->no_antrian;
}

antrian *findLastAntrian()
{
    if (head_prioritas != NULL) return head_prioritas;
    if (head_bpjs != NULL) return head_bpjs;
    return NULL;
}

void backupAntrian(antrian *hapus){
    history *newHistory = new history();
    newHistory->no_antrian = hapus ->no_antrian;
    newHistory->nama_pasien = hapus ->nama_pasien;
    newHistory->keluhan = hapus ->keluhan;
    newHistory->is_bpjs = hapus ->is_bpjs;
    newHistory->banyak_resep = hapus ->banyak_resep;
    for(int i = 0; i < newHistory -> banyak_resep; i++){
        newHistory->resep_obat[i][0] = hapus->resep_obat[i][0];        
        newHistory->resep_obat[i][1] = hapus->resep_obat[i][1];        
        newHistory->resep_obat[i][2] = hapus->resep_obat[i][2];        
    }

    
    newHistory->prev = tail_history;
    if (tail_history != NULL) { tail_history->next = newHistory; }
    if(hapus -> next){
        hapus->next->prev = NULL;
        hapus->next->is_bpjs ? head_bpjs = hapus->next : head_prioritas = hapus -> next;
    }else hapus ->is_bpjs ? head_bpjs = NULL : head_prioritas = NULL;
    tail_history = newHistory;
    delete hapus;
}