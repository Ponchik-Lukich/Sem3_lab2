#ifndef NEWLABA_PAIR_H
#define NEWLABA_PAIR_H

template<class TKey, class TElement>
class PairKE
{
private:
    TKey key;
    TElement element;
public:
    PairKE() = default;

    PairKE(TKey key, TElement element)
    {
        this->key = key;
        this->element = element;
    }

    ~PairKE() = default;

    TElement GetElem() const
    {
        return this->element;
    }

    TKey GetKey() const
    {
        return this->key;
    }

    void SetKey(TKey key)
    {
        this->key = key;
    }

    void SetElem(TElement elem)
    {
        this->element = elem;
    }

    bool operator<(const PairKE another)
    {
        return this->key < another.key;
    }

    bool operator>(const PairKE another)
    {
        return this->key > another.key;
    }

    bool operator<=(const PairKE another)
    {
        return this->key <= another.key;
    }

    bool operator>=(const PairKE another)
    {
        return this->key >= another.key;
    }

    bool operator!=(const PairKE another)
    {
        return this->key != another.key;
    }

    bool operator==(const PairKE another)
    {
        return this->key == another.key;
    }
};

template <class TKey, class TElement>
std::ostream& operator<< (std::ostream &out, const PairKE<TKey, TElement> pair)
{
    return out << "<" << pair.GetKey() << ", " << pair.GetElem() << ">";
}

#endif
