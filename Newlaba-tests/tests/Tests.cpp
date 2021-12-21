#include "gtest/gtest.h"
#include "../../ListSequence.h"
#include "../../ArraySequence.h"
#include "../../Sorts.h"
#include "../../Complex.h"
#include "../../Function.h"
#include "../../Alphabet.h"
#include "../../Histogram.h"
#include "../../Dictionary.h"
#include "../../OftenSubsequence.h"
#include "../../Sorts.h"

using namespace Sorts_algorithms;

int arr[] = {1, 2, 3, 4, 5};
float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
int arr3[] = {4, 323, -999, 8, 5};
double arr4[] = {1.112, 5.3, 1.111, 2.5, 7.9, 525.0, -76.5};
complex arr5[] = {complex(3,3), complex(1,1), complex(2,2), complex(1, 2)};

int *array_1 = arr;
float *array_2 = arr2;
int *array_3 = arr3;
double  *array_4 = arr4;
complex *array_5 = arr5;



string test = "mama_la_morema";

TEST(DynamicArray, Default)
{
    DynamicArray<int> array = DynamicArray<int>(0);
    ASSERT_EQ(0, array.GetSize());
}

TEST(DynamicArray, Getsize)
{
    DynamicArray<int> array = DynamicArray<int>(10);
    ASSERT_EQ(10, array.GetSize());
}

TEST(DynamicArray, Float)
{
    DynamicArray<float> array = DynamicArray<float>(array_2,5);
    ASSERT_EQ(5, array.GetSize());
    EXPECT_FLOAT_EQ(1.1, array.Get(0));
    EXPECT_FLOAT_EQ(5.5, array.Get(4));
}

TEST(DynamicArray, FromArray_Get)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ASSERT_EQ(5, array.GetSize());
    ASSERT_EQ(1, array.Get(0));
    ASSERT_EQ(5, array.Get(4));
}

TEST(DynamicArray, Set)
{
    DynamicArray<int> array = DynamicArray<int>(3);
    array.Set(2,999);
    ASSERT_EQ(999, array.Get(2));
}

TEST(DynamicArray, Resize)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    array.Resize(3);
    ASSERT_EQ(3, array.Get(2));
}

TEST(LinkedList, InitDefault)
{
    LinkedList<int> arr = LinkedList<int>();
    ASSERT_EQ(0, arr.GetLength());
}

TEST(LinkedList, Creation_from_array)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ASSERT_EQ(5,list.GetLength());
}

TEST(LinkedList, Get)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ASSERT_EQ(1,list.Get(0));
    ASSERT_EQ(5,list.Get(4));
}

TEST(LinkedList, float)
{
    LinkedList<float> list = LinkedList<float>(array_2, 5);
    EXPECT_FLOAT_EQ(1.1,list.Get(0));
    EXPECT_FLOAT_EQ(5.5,list.Get(4));
}

TEST(LinkedList, GetLast_GetFirst)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ASSERT_EQ(1,list.GetFirst());
    ASSERT_EQ(5,list.GetLast());
}

TEST(LinkedList, Getsublist)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    LinkedList<int>* list1 = new LinkedList<int>();
    list1 = list.GetSublist(1,3);
    ASSERT_EQ(2,list1->GetFirst());
    ASSERT_EQ(4,list1->GetLast());
}

TEST(LinkedList, Append)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.Append(22);
    ASSERT_EQ(22, list.Get(5));
}

TEST(LinkedList, Prepend)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.Prepend(22);
    ASSERT_EQ(22, list.Get(0));
}

TEST(LinkedList, Insert)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.InsertAt(11,2);
    ASSERT_EQ(11, list.Get(2));
}

TEST(LinkedList, Clear)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    list.Clear();
    ASSERT_EQ(0, list.GetLength());
}

TEST(ArraySequence, Get_First_Last)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    ASSERT_EQ(1, seq.GetFirst());
    ASSERT_EQ(5, seq.GetLast());
}

TEST(ArraySequence, GetSubseq)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    ArraySequence<int> *seq1 = new ArraySequence<int>();
    seq1 = seq.GetSubSequence(0, 1);
    ASSERT_EQ(1, seq1->GetFirst());
    ASSERT_EQ(1, seq1->GetLast());
}

TEST(ArraySequence, Set1)
{
    DynamicArray<int> array = DynamicArray<int>(array_1, 5);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    seq.Set(0,11);
    ASSERT_EQ(11, seq.Get(0));
}

TEST(ListSequence, Get_First_Get_Last)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ListSequence<int> seq = ListSequence<int>(&list);
    ASSERT_EQ(1, seq.GetFirst());
    ASSERT_EQ(5, seq.GetLast());
}

TEST(ListSequence, GetSize)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ListSequence<int> seq = ListSequence<int>(&list);
    ASSERT_EQ(5, seq.GetSize());
}

TEST(ListSequence, Set)
{
    LinkedList<int> list = LinkedList<int>(array_1, 5);
    ListSequence<int> seq = ListSequence<int>(&list);
    seq.Set(1, 11);
    ASSERT_EQ(11, seq.Get(1));
}

TEST(OftenSubsequence, first)
{
    ArraySequence<char>* arr_char = new ArraySequence<char>;
    for (size_t i = 0; i < test.size(); i++)
    {
        arr_char->Append(test[i]);
    }
    OftenSubSeq* sub = new OftenSubSeq(arr_char, 2, 3, compare_string_int);
    Sequence<PairKE<string, int>>* all = sub->Max_pair();
    ASSERT_EQ(3, all->Get(0).GetElem());
    ASSERT_EQ("ma", all->Get(0).GetKey());
}

TEST(Dictionary, first)
{
    Dictionary<string , int>* dict;
    dict = new Dictionary<string , int>(compare_string_int);
    dict->Add("I", 1);
    dict->Add("am", 2);
    dict->Add("Artemii", 3);
    ASSERT_TRUE(dict->ContainsKey("I"));
    ASSERT_TRUE(dict->ContainsKey("am"));
    ASSERT_TRUE(dict->ContainsKey("Artemii"));
    ASSERT_FALSE(dict->ContainsKey("Artemi"));
    ASSERT_EQ(1, dict->Get("I"));
    ASSERT_EQ(2, dict->Get("am"));
    ASSERT_EQ(3, dict->Get("Artemii"));
    ASSERT_EQ(3, dict->GetCount());
}

TEST(Dictionary, second)
{
    Dictionary<string , int>* dict1;
    dict1 = new Dictionary<string , int>(compare_string_int);
    dict1->Add("I", 1);
    dict1->Add("am", 2);
    dict1->Add("Groot", 3);
    dict1->ChangeElem("Groot", 5);
    ASSERT_EQ(5, dict1->Get("Groot"));
    dict1->Remove("am");
    ASSERT_TRUE(dict1->ContainsKey("I"));
    ASSERT_FALSE(dict1->ContainsKey("am"));
    ASSERT_TRUE(dict1->ContainsKey("Groot"));
    ASSERT_EQ(2, dict1->GetCount());
}

TEST(Histogram, first)
{
    Histogram *hist;
    ArraySequence<Person> *seq = new ArraySequence<Person>();
    seq->Append(Person("Andrey", "Ivanov", 20, 80));
    seq->Append(Person("Andrey", "Ivanov", 20, 90));
    seq->Append(Person("Andrey", "Ivanov", 20, 80));
    seq->Append(Person("Andrey", "Ivanov", 20, 90));
    int (Person::*getParam)() = &Person::GetMark;
    hist = new Histogram(*seq, getParam, 2);
    Sequence<PairKE<int, int>>* pairs = hist->print_hist();
    ASSERT_EQ(80, pairs->Get(0).GetKey());
    ASSERT_EQ(85, pairs->Get(1).GetKey());
    ASSERT_EQ(2, pairs->Get(0).GetElem());
    ASSERT_EQ(2, pairs->Get(1).GetElem());
}

TEST(Alphabet, first)
{
    string* arr = new string[3];
    arr[0] = "mama";
    arr[1] = "mia";
    arr[2] = "more";
    Sequence<string>* seq = new ArraySequence<string>(arr, 3);
    PageSplitter test(seq, 3, compare_string_int);
    Sequence<PairKE<string, int>>* all = test.print_helper();
    int page1 = test.Find("m");
    int page2 = test.Find("ama");
    int page3 = test.Find("mia");
    int page4 = test.Find("mor");
    int page5 = test.Find("e");
    int page6 = test.Find("pablo");

    ASSERT_EQ(5, test.HowManyPages());
    ASSERT_EQ(1, page1);
    ASSERT_EQ(2, page2);
    ASSERT_EQ(3, page3);
    ASSERT_EQ(4, page4);
    ASSERT_EQ(5, page5);
    ASSERT_EQ(-1, page6);

}