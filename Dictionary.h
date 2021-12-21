#pragma once

#include "Binary_Tree.h"
#include "Pair.h"

#define NO_ELEMENT "NO ELEMENT WITH GIVEN KEY"

template <class TKey, class TElement>
class Dictionary
{
protected:

    BinaryTree<PairKE<TKey,  TElement>>* dict;

public:
    Dictionary(const TKey key, const TElement elem, bool (*cmp)(PairKE<TKey, TElement>, PairKE<TKey, TElement>))
    {
        PairKE<TKey, TElement> spair = PairKE<TKey, TElement>(key, elem);
        this->dict = new BinaryTree<PairKE<TKey, TElement>>(spair, cmp);
    }

    Dictionary(bool (*cmp)(PairKE<TKey, TElement>, PairKE<TKey, TElement>))
    {
        this->dict = new BinaryTree<PairKE<TKey, TElement>>(cmp);
    }

    ~Dictionary() = default;
    
    int GetCount()
    {
        return this->dict->GetSize();
    }
    
    TElement Get(TKey key)
    {
        PairKE<TKey, TElement> pair = PairKE<TKey, TElement>();
        pair.SetKey(key);
        if(this->dict->Exist(pair))
            return this->dict->GetElem(dict->Search(pair)).GetElem();
        throw std::out_of_range(NO_ELEMENT);
    }

    bool ContainsKey(TKey key)
    {
        PairKE<TKey, TElement> pair = PairKE<TKey, TElement>();
        pair.SetKey(key);
        return this->dict->Exist(pair);
    }
    
    void Add(TKey key, TElement element)
    {
        PairKE<TKey, TElement> pair = PairKE<TKey, TElement>(key, element);
        if(this->dict->Exist(pair))
        {
            return;
        }
        this->dict->Add(pair);
    }
    
    void Remove(TKey key)
    {
        PairKE<TKey, TElement> pair = PairKE<TKey, TElement>();
        pair.SetKey(key);
        if(this->dict->Exist(pair))
        {
            this->dict->Erase(pair);
            return;
        }
        throw std::out_of_range(NO_ELEMENT);
    }
    
    void print()
    {
        this->dict->printAll();
    }
    
    void ChangeElem(TKey key, TElement elem)
    {
        PairKE<TKey, TElement> pair = PairKE<TKey, TElement>(key, elem);
        this->dict->SetElem(this->dict->Search(pair), pair);
    }

    ArraySequence<PairKE<TKey, TElement>>* Get_Array()
    {
        return this->dict->get_all();
    }
};