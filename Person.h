#ifndef LAB2_PERSON_H
#define LAB2_PERSON_H

#include <string>
#include <utility>

using namespace std;

class Person
{
private:
    string Firstname;
    string Lastname;
    int Age = 0;
    int Mark = 0;
public:

    Person() = default;

    Person(string firstname, string lastname, int age, int mark)
    {
        this->Firstname = std::move(firstname);
        this->Lastname = std::move(lastname);
        this->Age = age;
        this->Mark = mark;
    }

    string GetFirstname()
    {
        return this->Firstname;
    }

    string GetLastname()
    {
        return this->Lastname;
    }

    int GetMark()
    {
        return this->Mark;
    }

    int GetAge()
    {
        return this->Age;
    }

    string GetFullname()
    {
        return this->Firstname + " " + this->Lastname;
    }

    int GetBirthYear()
    {
        return (2021 - this->Age);
    }


    bool operator==(const Person& second)
    {
        if(this->Firstname == second.Firstname && this->Lastname == second.Lastname && this->Age == second.Age && this->Mark == second.Mark)
        {
            return true;
        }
        return false;
    }

};

std::ostream& operator<< (std::ostream &out, Person person)
{
    return out << "{" << person.GetFullname() << ", " << person.GetAge() << ", " << person.GetMark() << "}";
}


#endif
