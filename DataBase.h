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
        void addStudent(Student s);
        void addFaculty(Faculty f);
        void removeStudent(Student s);
        void removeFaculty(Faculty f);
        void rollback();
        void serialize();
        void deserialize();
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
            masterFaculty->printPerson(id);
        }

        //Given a student's id, print the name and info of their faculty advisor
        if(num == 5){
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
            int advisorID = masterStudent->getPerson(id)->key.getAdvisorID();
            masterFaculty->printPerson(advisorID);
        }

        //Given a faculty id, print ALL the names and info of his/her advisees
        if(num == 6){
            cout<<"Enter the Facultys ID number"<<endl;
            cin>>facID;
            int id = stoi(facID);
            int ls = masterFaculty->getPerson(id)->key.getListSize();
            for(int i = 0; i < ls; ++i){
                int temp = masterFaculty->getPerson(id)->key.getList()->removeFront();
                masterStudent->printPerson(temp);
                masterFaculty->getPerson(id)->key.getList()->insertBack(temp);
            }
        }

        //Add a new student
        if(num == 7){
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
            cout<<"Enter the Student's name."<<endl;
            cin>>name;
            cout<<"Enter the Students level."<<endl;
            cin>>level;
            cout<<"Enter the Student's major.(No space)"<<endl;
            cin>>major;
            cout<<"Enter the Student's GPA."<<endl;
            cin>>stuGpa;
            double gpa = stof(stuGpa);
            cout<<"Enter the Student's advisor's ID."<<endl;
            cin>>advID;
            int advisorID = stoi(advID);
            Student s(id, name, level, major, gpa, advisorID);
            addStudent(s);
            rollbackStack->push(num);
        }

        //Delete a student given the id
        if(num == 8){
            cout<<"Enter the Student's ID number."<<endl;
            cin>>stuID;
            int id = stoi(stuID);
            Student temp = masterStudent->getPerson(id)->key;
            bool deleted = masterStudent->deleteNode(temp);
            studentRollback->push(temp);

        }

        //Add a new faculty member
        if(num == 9){
            DoublyLinkedList<int> *studentIDList;
            cout<<"Enter the Faculty's ID number."<<endl;
            cin>>facID;
            int id = stoi(facID);
            cout<<"Enter the Faculty's name."<<endl;
            cin>>name;
            cout<<"Enter the Faculty's level."<<endl;
            cin>>major;
            cout<<"Enter the Faculty's department."<<endl;
            cin>>department;

            //go through tree of students to find matching advisor ID
            //studentIDList->insertBack(masterStudent->getPerson(facID));

            Faculty f(id, name, level, department, studentIDList);
            addFaculty(f);
            rollbackStack->push(num);
        }

        //Delete a faculty member given the id
        if(num == 10){
            cout<<"Enter the Faculty's ID number."<<endl;
            cin>>facID;
            int id = stoi(facID);
            Faculty temp = masterFaculty->getPerson(id)->key;
            bool deleted = masterFaculty->deleteNode(temp);
            //studentRollback->push(temp);
        }

        //Change a student's advisor given the student id and the new faculty id
        if(num == 11){
            cout<<"Enter the Students ID you wish to edit"<<endl;
            cin>>stuID;
            cout<<"Enter the new Faculty ID"<<endl;
            cin>>facID;
            int fid = stoi(facID);
            int sid = stoi(stuID);
            //remove student from facultys advisee list
            int oldID = masterStudent->getPerson(sid)->key.getAdvisorID();
            cout<<"179"<<endl;
            masterFaculty->getPerson(oldID)->key.removeStudent(sid);
            //change students advisor
            cout<<"182"<<endl;
            masterStudent->getPerson(sid)->key.setAdvisorID(fid);
            //add student to new advisor list
            cout<<"185"<<endl;
            masterFaculty->getPerson(fid)->key.addStudent(sid);

        }

        //Remove an advisee from a faculty member given the id
        if(num == 12){
            //get faculty member id
            //get student id they wish to remove
            cout<<"Enter the new Faculty ID"<<endl;
            cin>>facID;
            cout<<"Enter the Students ID you wish to remove"<<endl;
            cin>>stuID;
            int fid = stoi(facID);
            int sid = stoi(stuID);
            //remove student from list
            masterFaculty->getPerson(fid)->key.removeStudent(sid);
            //set students adviser to null
            //int rootID = masterFaculty->getRoot()->key.getID();
            //masterStudent->getPerson(sid)->setAdvisorID(rootID);
        }

        //Rollback
        if(num == 13){
            /*
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
            */
        }

        //Exit
        if(num == 14){
            exit = true;
        }



    }

}


void DataBase::addStudent(Student s){
    masterStudent->insert(s);
    studentRollback->push(s);
}

void DataBase::addFaculty(Faculty f){
    masterFaculty->insert(f);
    facultyRollback->push(f);
}

void DataBase::removeStudent(Student s){
    masterStudent->deleteNode(s);
    studentRollback->push(s);
}

void DataBase::removeFaculty(Faculty f){
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
