#pragma once

#include "Sequence.h"
#include "Dictionary.h"

using namespace std;

template <class T>
bool compareT(T a, T b)
{
    return a <= b;
}

bool compare_string_int(PairKE<string, int> a, PairKE<string, int> b) {
    if (a.GetKey() <= b.GetKey())
    {
        return true;
    }
    return false;
}

int compare_string_int1(PairKE<string, int> a, PairKE<string, int> b) {
    if (a.GetElem() < b.GetElem())
    {
        return 0;
    }
    if (a.GetElem() > b.GetElem())
    {
        return 1;
    }
    return 2;
}