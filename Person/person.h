#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string gender;
    int age;
    int savings;
    int attack;
    int defense;
    int wisdom;

public:
    string name;
    string lastName;
    string secondLastName;
    Person *partner;
    Person();
    Person(string name, string lastName, string secondLastName, string gender, int age, int savings, int attack, int defense, int wisdom);
    // Person(const string &personInfo);
    int getAge() const;
    int getSavings() const;
    int getAttack() const;
    int getDefense() const;
    int getWisdom() const;
    string getFullName();
    string getInfo();
    int getFeatureValue(int feature);
    string getGender();
    void setPartner(Person &partner);
    Person *getPartner();
    string getName();
    string getLastName();
    string getSecondLastName();
};

#endif
