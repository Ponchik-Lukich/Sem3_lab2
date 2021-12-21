#ifndef LABA222_ALPHABET_H
#define LABA222_ALPHABET_H

#include "Sequence.h"
#include "ArraySequence.h"
#include <string>
#include "Dictionary.h"

class PageSplitter
{
private:
    Dictionary<string, int>* dict;
    int capacity, size = 0;
public:
    PageSplitter(Sequence<string>* seq, int symbols, bool (*cmp)(PairKE<string , int>, PairKE<string, int>))
    {
        this->dict = new Dictionary<string, int>(cmp);
        this->capacity=0;
        int count = 1;
        int page_symbol = symbols;
        for (int i = 0; i < seq->GetSize(); i+=1)
        {
            if (count == 1)
            {
                if ( (((seq->Get(i)).length() <= page_symbol/2) && page_symbol == symbols) || (((seq->Get(i)).length() <= page_symbol) && page_symbol != symbols) )
                {
                    if (page_symbol == symbols)
                    {
                        page_symbol = symbols/2;
                    }
                    this->dict->Add(seq->Get(i), 1);
                    page_symbol -= (seq->Get(i)).length();
                }
                else
                {
                    SplitHelper(seq, i, page_symbol/2, count);
                    page_symbol = symbols;
                    count++;
                }
            }
            else if (count % 10 == 0)
            {
                if ( ((seq->Get(i)).length() <= 3 * page_symbol/4 && page_symbol == symbols) || ((seq->Get(i)).length() <= page_symbol && page_symbol != symbols) )
                {
                    this->dict->Add(seq->Get(i), count);
                    page_symbol -= 3 * ((seq->Get(i)).length())/4;
                }
                else
                {
                    SplitHelper(seq, i, 3*page_symbol/4, count);
                    page_symbol = symbols;
                    count++;
                }
            }
            else
            {
                if ( (seq->Get(i)).length() <= page_symbol)
                {
                    this->dict->Add(seq->Get(i), count);
                    page_symbol -= (seq->Get(i)).length();
                }
                else
                {
                    SplitHelper(seq, i, page_symbol, count);
                    page_symbol = symbols;
                    count++;
                }
            }

        }
        this->size = count;

    }

    void SplitHelper(Sequence<string>* seq, int index, int page_symbol, int count)
    {
        string temp;
        string temp_next;
        string word = seq->Get(index);
        for (int j = 0; j < page_symbol; j+=1)
        {
            temp += word[j];
        }
        for (int k = page_symbol; k < word.length(); k+=1)
        {
            temp_next += word[k];
        }

        if ((!this->dict->ContainsKey(temp)) && !temp.empty())
        {
            this->dict->Add(temp, count);
        }

        seq->InsertAt(temp_next, index+1);
    }

    int HowManyPages()
    {
        return this->size;
    }

    int Find(string key)
    {
        if(this->dict->ContainsKey(key))
        {
            int page = this->dict->Get(key);
            return page;
        }
        return -1;
    }

    Sequence<PairKE<string, int>>* print_helper()
    {
        ArraySequence<PairKE<string, int>>* result = dict->Get_Array();
        return result;
    }



};

#endif

