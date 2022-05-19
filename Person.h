#ifndef Person_H
#define Person_H
#include<iostream>
#include<string>
#include "BST.h"
#include "GenStack.h"
#include "DoublyLinkedList.h"
using namespace std;
class Person
{
    public:
        Person();
        ~Person();
        Person(int id, string name, string level);
    protected:
        int m_id;
        string m_name;
        string m_level;
};

Person::Person(){
    m_id = 0;
    m_name = "";
    m_level = "";
}

Person::~Person(){}

Person::Person(int id, string name, string level){
    m_id = id;
    m_name = name;
    m_level = level;
}

#endif