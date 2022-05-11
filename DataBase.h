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
        void runProgram();
        void addStudent(Student *s);
        void addFaculty(Faculty *f);
        void removeStudent(Student *s);
        void removeFaculty(Faculty *f);
        void rollback();
        int prompt();
    private:
        BST<Student> *masterStudent;
        BST<Faculty> *masterFaculty;
        GenStack<Student> *studentRollback;
        GenStack<Faculty> *facultyRollback;
        GenStack<int> *rollbackStack;
};

DataBase::DataBase(){
    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();
    studentRollback = new GenStack<Student>();
    facultyRollback = new GenStack<Faculty>();
    rollbackStack = new GenStack<int>();
}
DataBase::~DataBase(){}

DataBase::runProgram(){


    //variable for when the user wants to exit
    bool exit = false;
    while(exit == false){
        int num = prompt();

        //Print all students and their information (sorted by ascending id #)
        if(num == 1){
            Student->printInfo();
        }

        //Print all faculty and their information (sorted by ascending id #)
        if(num == 2){
            Faculty->printInfo();
        }

        //Find and display student information given the students id
        if(num == 3){
            string stuID;
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
            Student->printItem(id);
        }

        //Find and display faculty information given the faculty id
        if(num == 4){
            string facID;
            cout<<"Enter the Faculty's ID number."<<endl;
            cin>>facID;
            int id = stoi(facID);
            Student->printItem(id);
        }

        //Given a student's id, print the name and info of their faculty advisor
        if(num == 5){
            string stuID;
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
            int advisorID = Student->getPerson(id)->getAdvisorID();
            Faculty->printPerson(advisorID);
        }

        //Given a faculty id, print ALL the names and info of his/her advisees
        if(num == 6){
            string facID;
            cout<<"Enter the Students ID number"<<endl;
            cin>>facID;
            int id = stoi(facID);
            for(int i = 0; i < Faculty->getListSize(); ++i){
                int temp = Faculty->getList()->removeFront();
                Student->printPerson(temp);
                Faculty->getList()->insertBack(temp);
            }
        }

        //Add a new student
        if(num == 7){
            string stuID;
            string name;
            string major;
            string stuGpa;
            string advID;
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(studID);
            cout<<"Enter the Student's name."<<endl;
            cin>>name;
            cout<<"Enter the Student's major."<<endl;
            cin>>major;
            cout<<"Enter the Student's GPA."<<endl;
            cin>>stuGpa;
            double gpa = stof(stuGpa);
            cout<<"Enter the Student's advisor's ID."<<endl;
            cin>>advID;
            int advisorID = stoi(advID);
            Student *s = new Student(id, name, major, gpa, advisorID);
            masterStudent->addStudent(s);
            studentRollback->push(s);
            rollbackStack->push(num);
        }

        //Delete a student given the id
        if(num == 8){
            string stuID;
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(studID);


        }

        //Add a new faculty member
        if(num == 9){
            
        }

        //Delete a faculty member given the id
        if(num == 10){

        }

        //Change a student's advisor given the student id and the new faculty id
        if(num == 11){

        }

        //Remove an advisee from a faculty member given the ids
        if(num == 12){

        }

        //Rollback
        if(num == 13){
            if(rollbackStack->pop() == 7){
                //undo adding a student
                Student *s = studentRollback->pop();
                masterStudent->removeStudent(s);

            } else if(rollbackStack->pop() == 8){

            } else if(rollbackStack->pop() == 9){

            } else if(rollbackStack->pop() == 10){

            } else if (rollbackStack->pop() == 11){

            } else if (rollback->pop() == 12){

            }
        }

        //Exit
        if(num == 14){
            exit = true;
        }



    }

}


void DataBase::addStudent(Student *s){
    masterStudent->insert(s);
    studentRollback->push(s);
}

void DataBase::addFaculty(Faculty *f){
    masterFaculty->insert(f);
    studentRollback->push(f);
}

void DataBase::removeStudent(Student *s){
    masterStudent->deleteNode(s);
    studentRollback->push(s);
}

void DataBase::removeFaculty(Faculty *f){
    masterFaculty->deleteNode(f);
    facultyRollback->push(f);
}

void DataBase::rollback(){

}

void DataBase::serialize(){

}

void DataBase::deserialize(){

}



int DataBase::prompt(){
    cout<<"Enter the number of the item you wish to execute"<<endl;
    cout<<"1. Print all students and their information (sorted by ascending id #)"<<endl;
    cout<<"2. Print all faculty and their information (sorted by ascending id #)"<<endl:
    cout<<"3. Find and display student information given the students id"<<endl;
    cout<<"4. Find and display faculty information given the faculty id"<<endl;
    cout<<"5. Given a student's id, print the name and info of their faculty advisor"<<endl;
    cout<<"6. Given a faculty id, print ALL the names and info of his/her advisees."<<endl;
    cout<<"7. Add a new student"<<endl;
    cout<