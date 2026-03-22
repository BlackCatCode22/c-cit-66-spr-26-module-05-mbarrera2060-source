#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <memory>

using namespace std;

/*
Base Class: Animal
 This class stores common attributes shared by all animals.
Encapsulation is used with protected variables and public getters & setters.
*/
class Animal {

protected:
    string name;
    int age;
    string species;

public:

    // Constructor
    Animal(string n, int a, string s) {
        name = n;
        age = a;
        species = s;
    }

    //Virtual destructor
    virtual ~Animal() {}

    //Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getSpecies() { return species; }

    //Setters
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }

    // Virtual function used for polymorphism
    virtual string getInfo() {
        return name + " (Age: " + to_string(age) + ")";
    }
};

/*
    Subclass: Hyena
    Inherits from Animal and sets species automatically.
*/
class Hyena : public Animal {

public:
    Hyena(string n, int a) : Animal(n, a, "Hyena") {}

    string getInfo() override {
        return "Hyena - " + name + " Age: " + to_string(age);
    }
};

/*
    Subclass: Lion
*/
class Lion : public Animal {

public:
    Lion(string n, int a) : Animal(n, a, "Lion") {}

    string getInfo() override {
        return "Lion - " + name + " Age: " + to_string(age);
    }
};

/*
Subclass: Tiger
*/
class Tiger : public Animal {

public:
    Tiger(string n, int a) : Animal(n, a, "Tiger") {}

    string getInfo() override {
        return "Tiger - " + name + " Age: " + to_string(age);
    }
};

/*
    Subclass : Bear
*/
class Bear : public Animal {

public:
    Bear(string n, int a) : Animal(n, a, "Bear") {}

    string getInfo() override {
        return "Bear - " + name + " Age: " + to_string(age);
    }
};

int main() {

    //Vector stores all animal objects
    vector<shared_ptr<Animal>> zooAnimals;

    //Map counts how many animals per species
    map<string, int> speciesCount;

    //Opens files
    ifstream inputFile("arrivingAnimals(2).txt");
    ofstream outputFile("newAnimals.txt");

    if (!inputFile) {
        cout << "Error opening arrivingAnimals(2).txt\n";
        return 1;
    }

    string species, name;
    int age;

    /*
    Loops reads the input file until the end.
        Each line should contain: species name age
    */
    while (inputFile >> species >> name >> age) {

        //Creates objects based on species
        if (species == "Hyena")
            zooAnimals.push_back(make_shared<Hyena>(name, age));

        else if (species == "Lion")
            zooAnimals.push_back(make_shared<Lion>(name, age));

        else if (species == "Tiger")
            zooAnimals.push_back(make_shared<Tiger>(name, age));

        else if (species == "Bear")
            zooAnimals.push_back(make_shared<Bear>(name, age));

        // Increases species count
        speciesCount[species]++;
    }

    /*
    Generates report in arrivingAnimals(2).txt
    */

    outputFile << "Zoo Animal Report\n";
    outputFile << "====================\n\n";

    //Organises animals by species
    map<string, vector<string>> categorizedAnimals;

    for (auto& animal : zooAnimals) {
        categorizedAnimals[animal->getSpecies()].push_back(animal->getInfo());
    }

    //Prints report
    for (auto& pair : categorizedAnimals) {

        outputFile << pair.first << " Enclosure\n";
        outputFile << "------------------\n";

        for (string info : pair.second) {
            outputFile << info << endl;
        }

        outputFile << "Total " << pair.first
                   << ": " << speciesCount[pair.first] << "\n\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Report generated successfully: newAnimals.txt\n";

    return 0;
}