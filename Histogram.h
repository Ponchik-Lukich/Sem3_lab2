#pragma once

#include "Person.h"
#include "Sequence.h"
#include "Dictionary.h"

using namespace std;

template <class T>
class Histogram
{
private:

    Dictionary<T, int>* dict;
    T (Person::*getParam)();

public:
    Histogram(ArraySequence<Person> seq, int (Person::*getParam)(), int n, int (*cmp)(T, T))
    {
        T min = (seq.Get(0).*getParam)();
        T max = (seq.Get(0).*getParam)();

        for (int i = 1; i < seq.GetSize(); i++)
        {
            if (cmp((seq.Get(i).*getParam)(), min) == 0)
                min = (seq.Get(i).*getParam)();
            
            if (cmp((seq.Get(i).*getParam)(), max) == 1)
                max = (seq.Get(i).*getParam)();
        }
        T dif = (max - min) / n;

        while (dif == 0)
        {
            n--;
            dif = (max - min) / n;
        }
        
        dict = new Dictionary<T, int>(min, 0, compareT);
        
        for (int i = 1; i < n; i++)
        {
            dict->Add((min + dif*i), 0);
        }

        T j = 0;
        int amount = 0;
        
        for (int i = 0; i < seq.GetSize(); i++)
        {
            j = (((seq.Get(i).*getParam)() - min)  / dif);
            if (cmp(j, n) == 2) j--;
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
    
    Sequence<PairKE<T, int>>* print_hist()
    {
        Sequence<PairKE<T, int>>* seq = dict->Get_Array();
        return seq;
    }
};
