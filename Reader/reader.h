#ifndef READER_H
#define READER_H
#include <string>
#include <iostream>
#include <fstream>
// #include <vector>
#include "../Person/person.h"

using namespace std;

class Reader
{
private:
    ifstream myFile;
    // vector<Person> people;
    Person people[sizeof(Person) * 14];
    Person partners[sizeof(Person) * 14];
    int size = 14;

public:
    Reader();
    ~Reader();

    void getPeopleInfo(const string &fileName);
    void setPeoplePartners(const string &fileName);
    // vector<Person> getPeople();
    Person *getPartners();
    Person *getPeople();
};

#endif