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
            newAntrian->prev = tail_prioritas;
            head_bpjs = newAntrian;
            tail_bpjs = newAntrian;
        }
        else
        {
            newAntrian->prev = tail_bpjs;
            tail_bpjs = newAntrian;
        }
    }
    else
    {
        newAntrian->no_antrian = "A" + to_string(antrian_prioritas++);
        if (head_prioritas == NULL)
        {
            head_prioritas = newAntrian;
            tail_prioritas = newAntrian;
        }
        else
        {
            tail_prioritas->next = newAntrian;
            newAntrian->prev = tail_prioritas;
            tail_prioritas = newAntrian;
        }
    }
    return newAntrian->no_antrian;
}

antrian *findLastAntrian()
{
    if (head_prioritas != NULL)
        return head_prioritas;
    if (head_bpjs != NULL)
        return head_bpjs;
    return NULL;
}
