#pragma once

#include "Sequence.h"
#include "ArraySequence.h"
#include "Dictionary.h"
#include <ctime>

using namespace std;

#ifndef LAB1_SORTS_H
#define LAB1_SORTS_H

#endif
namespace Sorts_algorithms
{
    const string INCORRECT_INDEX = "Impossible to make this operation: Incorrect number";

    void QuickSort_Support(Sequence<PairKE<string , int>> *seq, int left, int right, int (*cmp_dict)(PairKE<string , int>, PairKE<string, int>))
    {
        int i = left;
        int j = right;
        PairKE<string , int> pivot_help = seq->Get(((left + right) / 2));
        PairKE<string , int> temp;


        while (i <= j) {
            while (cmp_dict(seq->Get(i), pivot_help) == 0) {
                i++;
            }
            while (cmp_dict(seq->Get(j), pivot_help) == 1) {
                j--;
            }
            if (i <= j) {
                temp = seq->Get(i);
                seq->Set(i, seq->Get(j));
                seq->Set(j, temp);
                i++;
                j--;
            }

        }
        if (j > left) {
            QuickSort_Support(seq, left, j, cmp_dict);
        }
        if (i < right) {
            QuickSort_Support(seq, i, right, cmp_dict);
        }
    }

    Sequence<PairKE<string , int>> *QuickSort(Sequence<PairKE<string , int>> *seq, int (*cmp_dict)(PairKE<string , int>, PairKE<string, int>))
    {
        if (seq->GetSize() <= 1)
        {
            throw out_of_range(INCORRECT_INDEX);
        }
        int size = seq->GetSize();
        QuickSort_Support(seq, 0, size - 1, cmp_dict);
        return seq;
    }


}
