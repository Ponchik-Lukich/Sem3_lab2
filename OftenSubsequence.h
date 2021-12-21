#ifndef LABA222_OFTENSUBSEQUENCE_H
#define LABA222_OFTENSUBSEQUENCE_H

#include <iostream>
#include <string>
#include "Sequence.h"
#include "Dictionary.h"
#include "ArraySequence.h"


class OftenSubSeq
{
private:

    Dictionary<string, int>* dict;
    int start, end, max;
    string maxstring;

public:
    OftenSubSeq(Sequence<char>* seq, int start, int end, bool (*cmp_dict)(PairKE<string , int>, PairKE<string, int>))
    {
        dict = new Dictionary<string, int>(cmp_dict);
        this->max = 0;
        this->start = start;
        this->end = end;
        for (int i = 0; i < seq->GetSize(); i++)
        {
            for (int j = start; i + j <= seq->GetSize() && j <= end; j++)
            {
                Sequence<char>* sub = seq->GetSubSequence(i, i + j);

                string subs;
                subs.clear();
                for (int k = 0; k < sub->GetSize(); k++)
                {
                    subs.append(1, sub->Get(k));
                }
                if (!dict->ContainsKey(subs))
                {
                    int count = 1;
                    dict->Add(subs, count);
                    if (max < count) {
                        max = 1;
                        maxstring = subs;
                    }

                }
                else
                {
                    int count = dict->Get(subs);
                    count++;
                    dict->Remove(subs);
                    dict->Add(subs, count);
                    if (max < count) {
                        max = count;
                        maxstring = subs;
                    }
                }
            }
        }
    }

    Sequence<PairKE<string, int>>* Max_pair()
    {
        ArraySequence<PairKE<string, int>>* result = dict->Get_Array();
        ArraySequence<PairKE<string, int>>* Max = new ArraySequence<PairKE<string, int>>;
        for (int i = 0; i < result->GetSize(); i+=1)
        {
            if (result->Get(i).GetElem() == max)
            {
                Max->Append(result->Get(i));
            }
        }
        return Max;

    }

    Sequence<PairKE<string, int>>* print_help()
    {
        ArraySequence<PairKE<string, int>>* result = dict->Get_Array();
        return result;
    }

    ~OftenSubSeq()
    {
        delete dict;
    }

};

#endif