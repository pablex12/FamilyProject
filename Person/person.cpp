
#include <iostream>
#include <string>
#include <sstream>
#include "person.h"

using namespace std;

Person::Person() : gender(""), age(0), savings(0), attack(0), defense(0), wisdom(0), name(""), lastName(""), secondLastName("")
{
}

Person::Person(string name, string lastName, string secondLastName, string gender, int age, int savings, int attack, int defense, int wisdom)
{
    this->name = name;
    this->lastName = lastName;
    this->secondLastName = secondLastName;
    this->gender = gender;
    this->age = age;
    this->savings = savings;
    this->attack = attack;
    this->defense = defense;
    this->wisdom = wisdom;
    this->partner = nullptr;
}

string Person::getFullName()
{
    return this->name + " " + this->lastName + " " + this->secondLastName;
}

string Person::getName()
{
    return this->name;
}

string Person::getLastName()
{
    return this->lastName;
}

string Person::getSecondLastName()
{
    return this->secondLastName;
}

string Person::getGender()
{
    return this->gender;
}

void Person::setPartner(Person &partner)
{
    if (partner.getGender() != this->gender && this->partner == nullptr)
    {
        this->partner = &partner;
    }
}

Person *Person::getPartner()
{
    return this->partner;
}

int Person::getAge() const
{
    return this->age;
}

int Person::getSavings() const
{
    return this->savings;
}

int Person::getAttack() const
{
    return this->attack;
}

int Person::getDefense() const
{
    return this->defense;
}

int Person::getWisdom() const
{
    return this->wisdom;
}

string Person::getInfo()
{
    return "Nombre: " + this->name + "\n" + "Apellido: " + this->lastName + "\n" + "Segundo Apellido: " + this->secondLastName + "\n" + "Sexo: " + this->gender + "\n" + "Edad: " + to_string(this->age) + "\n";
}

int Person::getFeatureValue(int feature)
{
    switch (feature)
    {
    case 1:
        return this->age;
    case 2:
        return this->savings;
    case 3:
        return this->attack;
    case 4:
        return this->defense;
    case 5:
        return this->wisdom;
    default:
        return 0;
    }
}