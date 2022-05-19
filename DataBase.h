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
        string stuID;
        string name;
        string major;
        string stuGpa;
        string advID;
        string facID;
        string level;
        string department;
};

DataBase::DataBase(){
    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();
    studentRollback = new GenStack<Student>();
    facultyRollback = new GenStack<Faculty>();
    rollbackStack = new GenStack<int>();
}
DataBase::~DataBase(){}

void DataBase::runProgram(){


    //variable for when the user wants to exit
    bool exit = false;
    while(exit == false){
        int num = prompt();

        //Print all students and their information (sorted by ascending id #)
        if(num == 1){
            masterStudent->printInfo();
        }

        //Print all faculty and their information (sorted by ascending id #)
        if(num == 2){
            masterFaculty->printInfo();
        }

        //Find and display student information given the students id
        if(num == 3){
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
            masterStudent->printPerson(id);
        }

        //Find and display faculty information given the faculty id
        if(num == 4){
            cout<<"Enter the Faculty's ID number."<<endl;
            cin>>facID;
            int id = stoi(facID);
            masterStudent->printPerson(id);
        }

        //Given a student's id, print the name and info of their faculty advisor
        if(num == 5){
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
            int advisorID = masterStudent->getPerson(id)->getAdvisorID();
            masterFaculty->printPerson(advisorID);
        }

        //Given a faculty id, print ALL the names and info of his/her advisees
        if(num == 6){
            cout<<"Enter the Students ID number"<<endl;
            cin>>facID;
            int id = stoi(facID);
            for(int i = 0; i < masterFaculty->getListSize(); ++i){
                int temp = masterFaculty->getList()->removeFront();
                masterStudent->printPerson(temp);
                masterFaculty->getList()->insertBack(temp);
            }
        }

        //Add a new student
        if(num == 7){
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
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
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(studID);
            masterStudent->deleteNode(id);

        }

        //Add a new faculty member
        if(num == 9){
            int facID;
            string name;
            string level;
            string department;
            DoublyLinkedList<int> *studentIDList;
            cout<<"Enter the Faculty's ID number."<<endl;
            cin>>facID;
            int id = stoi(studID);
            cout<<"Enter the Faculty's name."<<endl;
            cin>>name;
            cout<<"Enter the Faculty's level."<<endl;
            cin>>major;
            cout<<"Enter the Faculty's department."<<endl;
            cin>>stuGpa;
            double gpa = stof(stuGpa);

            //go through tree of students to find matching advisor ID
            studentIDList->insertBack(masterStudent->getPerson(facID));

            Faculty *f = new Faculty(id, name, level, department, studentIDList);
            masterFaculty->addFaculty(f);
            facultyRollback->push(f);
            rollbackStack->push(num);
        }

        //Delete a faculty member given the id
        if(num == 10){

        }

        //Change a student's advisor given the student id and the new faculty id
        if(num == 11){
            cout<<"Enter the Students ID you wish to edit"<<endl;
            cin>>stuID;
            cout<<"Enter the new Faculty ID"<<endl;
            cin>>facID;
            //remove student from facultys advisee list
            int oldID = masterStudent->getPerson(stuID)->getAdvisorID();
            masterFaculty->getPerson(oldID)->removeStudent(stuID);
            //change students advisor
            masterStudent->getPerson(stuID)->setAdvisorID(facID);
            //add student to new advisor list
            masterFaculty->getPerson(facID)->addStudent(stuID);

        }

        //Remove an advisee from a faculty member given the id
        if(num == 12){
            //get faculty member id
            //get student id they wish to remove
            cout<<"Enter the new Faculty ID"<<endl;
            cin>>facID;
            cout<<"Enter the Students ID you wish to remove"<<endl;
            cin>>stuID;
            //remove student from list
            masterFaculty->getPerson(facID)->removeStudent(stuID);
            //set students adviser to null
            int rootID = masterFaculty->getRoot()->key;
            masterStudent->getPerson(stuID)->setAdvisorID(rootID);
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
    facultyRollback->push(f);
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
    cout<<"2. Print all faculty and their information (sorted by ascending id #)"<<endl;
    cout<<"3. Find and display student information given the students id"<<endl;
    cout<<"4. Find and display faculty information given the faculty id"<<endl;
    cout<<"5. Given a student's id, print the name and info of their faculty advisor"<<endl;
    cout<<"6. Given a faculty id, print ALL the names and info of his/her advisees."<<endl;
    cout<<"7. Add a new student"<<endl;
    cout<<"8. Delete a student given the id"<<endl;
    cout<<"9. Add a new faculty member"<<endl;
    cout<<"10. Delete a faculty member given the id."<<endl;
    cout<<"11. Change a student's advisor given the student id and the new faculty id."<<endl;
    cout<<"12. Remove an advisee from a faculty member given the id"<<endl;
    cout<<"13. Rollback"<<endl;
    cout<<"14. Exit"<<endl;

    int val = 0;
    cin >> val;
    if(val < 1 || val > 14){
        cout<<"please enter a number listed";
        prompt();
    }
    return val;
}

#endif
