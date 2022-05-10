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
            
        }

        //Delete a student given the id
        if(num == 8){
            
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

DataBase::rollback(){
    
}

int prompt(){
    cout<<"Enter the number of the item you wish to execute"<<endl;
    cout<<"1. Print all students and their information (sorted by ascending id #)"<<endl;
    cout<<"2. Print all faculty and their information (sorted by ascending id #)"<<endl:
    cout<<"3. Find and display student information given the students id"<<endl;
    cout<<"4. Find and display faculty information given the faculty id"<<endl;
    cout<<"5. Given a student's id, print the name and info of their faculty advisor"<<endl;
    cout<<"6. Given a faculty id, print ALL the names and info of his/her advisees."<<endl;
    cout<<"7. Add a new student"<<endl;
    cout<<"8. Delete a student given the id"<<endl;
    cout<<"9. Add a new faculty member"<<endl;
    cout<<"10. Delete a faculty member given the id."<<endl;
    cout<<"11. Change a student's advisor given the student id and the new faculty id."<<endl;
    cout<<"12. Remove an advisee from a faculty member given the ids"<<endl;
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
