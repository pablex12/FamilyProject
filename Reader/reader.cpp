#include <string>
#include <iostream>
#include "reader.h"

using namespace std;

//~~~~~~~~~~~Constructors and Destructors~~~~~~~~~

Reader::Reader()
{
}

Reader::~Reader()
{
    myFile.close();
}

// vector<Person> Reader::getPeople()
Person *Reader::getPeople()
{
    return this->people;
}

Person *Reader::getPartners()
{
    return this->partners;
}

void Reader::getPeopleInfo(const string &fileName)
{
    myFile.open(fileName);
    if (myFile.is_open())
    {
        string line;
        string fullName = "";
        string name = "";
        string lastName = "";
        string secondLastName = "";
        string gender = "";
        int age = 0;
        int savings = 0;
        int attack = 0;
        int defense = 0;
        int wisdom = 0;
        int count = 0;

        while (getline(myFile, line))
        {
            if (line.find("#") != std::string::npos)
            {
                // cout << name << endl;
                Person p(name, lastName, secondLastName, gender, age, savings, attack, defense, wisdom);
                // cout << p.getInfo() << endl;
                // cout << count << endl;
                // this->people.push_back(p);
                this->people[count] = p;
                count++;
            }
            else if (line.find("Nombre") != std::string::npos)
            {
                fullName = line.substr(line.find(":") + 2);

                size_t firstSpacePos = fullName.find(' ');
                size_t secondSpacePos = fullName.find(' ', firstSpacePos + 1);

                name = fullName.substr(0, firstSpacePos);
                lastName = fullName.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
                secondLastName = fullName.substr(secondSpacePos + 1);

                // cout << name << endl;
                // cout << lastName << endl;
                // cout << secondLastName << endl;
            }
            else if (line.find("Sexo") != std::string::npos)
            {
                gender = line.substr(line.find(":") + 2);
                // cout << gender << endl;
            }
            else if (line.find("Edad") != std::string::npos)
            {
                age = stoi(line.substr(line.find(":") + 2));
                // cout << age << endl;
            }
            else if (line.find("Ahorros") != std::string::npos)
            {
                savings = stoi(line.substr(line.find("$") + 1));
                // cout << savings << endl;
            }
            else if (line.find("Ataque") != std::string::npos)
            {
                attack = stoi(line.substr(line.find(":") + 2));
                // cout << attack << endl;
            }
            else if (line.find("Defensa") != std::string::npos)
            {
                defense = stoi(line.substr(line.find(":") + 2));
                // cout << defense << endl;
            }
            else if (line.find("Sabiduria") != std::string::npos)
            {
                wisdom = stoi(line.substr(line.find(":") + 2));
                // cout << wisdom << endl;
            }
        }
    }
    else
    {
        cerr << "Error: el archivo no se pudo abrir" << endl;
        exit(1);
    }
    myFile.close();
}

void Reader::setPeoplePartners(const string &fileName)
{
    myFile.open(fileName);
    if (myFile.is_open())
    {
        string line;
        string fullName1;
        string fullName2;

        while (getline(myFile, line))
        {
            fullName1 = line.substr(0, line.find("."));
            fullName2 = line.substr(line.find(".") + 2);
            // cout << fullName1 << "Name1" << endl;
            // cout << fullName2 << "Name2" << endl;

            int pos1;
            int pos2;

            for (int i = 0; i < this->size; i++)
            {

                if (fullName1 == this->people[i].getFullName())
                {
                    // cout << "Assigning pos1" << endl;
                    pos1 = i;
                }
                if (fullName2 == this->people[i].getFullName())
                {
                    // cout << "Assigning pos2" << endl;
                    pos2 = i;
                }
            }

            // cout << people[pos1].getFullName() << "pos" << pos1 << endl;
            // cout << people[pos2].getFullName() << "pos" << pos2 << endl;

            // cout << this->people[pos1].getFullName() << pos1 << "->" << this->people[pos2].getFullName() << pos2 << endl;
            // cout << this->people[pos2].getFullName() << pos2 << "->" << this->people[pos1].getFullName() << pos1 << endl;

            this->people[pos1].setPartner(this->people[pos2]);
            this->people[pos2].setPartner(this->people[pos1]);
        }

        int count = 0;
        for (int i = 0; i < this->size; i++)
        {
            if (this->people[i].getGender() == "Hombre")
            {
                // cout << this->people[i].getFullName() << endl;
                this->partners[count] = this->people[i];
                count++;
            }
        }
    }
    else
    {
        cerr << "Error: el archivo no se pudo abrir" << endl;
        exit(1);
    }
    myFile.close();
}

//~~~~~~~~~~~Main Fuctions~~~~~~~~~//