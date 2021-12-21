#pragma once

#include "Person.h"
#include "Sequence.h"
#include "Dictionary.h"

using namespace std;

class Histogram
{
private:

    Dictionary<int, int>* dict;
    int (Person::*getParam)();

public:
    Histogram(ArraySequence<Person> seq, int (Person::*getParam)(), int n)
    {
        int min = (seq.Get(0).*getParam)();
        int max = (seq.Get(0).*getParam)();

        for (int i = 1; i < seq.GetSize(); i++)
        {
            if ((seq.Get(i).*getParam)() < min)
                min = (seq.Get(i).*getParam)();
            
            if ((seq.Get(i).*getParam)() > max)
                max = (seq.Get(i).*getParam)();
        }
        int dif = (max - min) / n;

        while (dif == 0)
        {
            n--;
            dif = (max - min) / n;
        }
        
        dict = new Dictionary<int, int>(min, 0, compareT);
        
        for (int i = 1; i < n; i++)
            dict->Add((min + dif*i), 0);

        int j = 0;
        int amount = 0;
        
        for (int i = 0; i < seq.GetSize(); i++)
        {
            j = (((seq.Get(i).*getParam)() - min)  / dif);
            if (j == n) j--;
            amount = dict->Get((min + j * dif));
            dict->ChangeElem((min + j * dif), amount + 1);
        }
        this->getParam = getParam;
    }

    ~Histogram()
    {
        delete dict;
    }
    
    int GetAmountOfSubSets()
    {
        return this->dict->GetCount();
    }
    
    Sequence<PairKE<int, int>>* print_hist()
    {
        Sequence<PairKE<int, int>>* seq = dict->Get_Array();
        return seq;
    }
};
