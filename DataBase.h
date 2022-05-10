#ifndef DATABASE_H
#define DATABASE_H
#include<iostream>
#include<string>
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
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
        GenStack<Student> *studentRollback;
        GenStack<Faculty> *facultyRollback;
};

DataBase::DataBase(){
    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();
    studentRollback = new GenStack<Student>();
    facultyRollback = new GenStack<Faculty>();
}
DataBase::~DataBase(){}


DataBase::addStudent(Student *s){
    masterStudent->insert(s);
    studentRollback->push(s);
}

DataBase::addFaculty(Faculty *f){
    masterFaculty->insert(f);
    studentRollback->push(f);
}

DataBase::removeStudent(Student *s){
    masterStudent->deleteNode(s);
    studentRollback->push(s);
}

DataBase::removeFaculty(Faculty *f){
    masterFaculty->deleteNode(f);
    facultyRollback->push(f);
}

DataBase::rollback(){
    
}


#endif
