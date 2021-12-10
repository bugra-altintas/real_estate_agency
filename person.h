#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "owner.h"

class Person : public Owner
{
public:
    /**
     * Constructor of Person class
     * 
     * Creates instance and add it to the owner's property list if the owner is not NULL.
     * 
     * name: Name of the person
     * balance: Balance value of the person
     * age: Age of the person
    */
    Person(const std::string &name, float balance, int age);

    /**
     * Prints information about person:
     * 
     * Name: <name> Age: <age>
    */
    void print_info();

private:
    int age;
};

#endif //PERSON_H