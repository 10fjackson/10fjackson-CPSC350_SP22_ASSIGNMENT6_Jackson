#ifndef DATABASE_H
#define DATABASE_H
#include<iostream>
#include<string>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;
class DataBase
{
    public:
        DataBase();
        ~DataBase();
        addStudent(Student *s);
        addFaculty(Faculty *f);
        removeStudent(Student *s);
        removeFaculty(Faculty *f);
    private:
        BST<Student> *masterStudent;
        BST<Faculty> *masterFaculty;
};

DataBase::DataBase(){
    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();
}
DataBase::~DataBase(){}


DataBase::addStudent(Student *s){
    masterStudent->insert(s);
}

DataBase::addFaculty(Faculty *f){
    masterFaculty->insert(f);
}

DataBase::removeStudent(Student *s){
    masterStudent->deleteNode(s);
}

DataBase::removeFaculty(Faculty *f){
    masterFaculty->deleteNode(f);
}


#endif