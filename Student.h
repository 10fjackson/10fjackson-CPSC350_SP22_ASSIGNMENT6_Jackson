#ifndef Student_H
#define Student_H
#include "Person.h"
using namespace std;
class Student : public Person
{
    public:
	    Student();
        ~Student();
        Student(int id, string name, string level, string major, double gpa, int advisorID);
        int getAdvisorID();
        void setAdvisorID(int a);
        int getID();
        string toString();
        bool operator<(const Student &s); 
        bool operator>(const Student &s);
        bool operator==(const Student &s);
        bool operator!=(const Student &s);
    private:
        string m_major;
        double m_gpa;
        int m_advisorID;
};
Student::Student(){
    m_id = 0;
    m_name = "";
    m_level = "";
    m_major = "";
    m_gpa = 0.0;
    m_advisorID = 0;
}

Student::~Student(){}

Student::Student(int id, string name, string level, string major, double gpa, int advisorID){
    m_id = id;
    m_name = name;
    m_level = level;
    m_major = major;
    m_gpa = gpa;
    m_advisorID = advisorID;
}

int Student::getAdvisorID(){
    return m_advisorID;
}

void Student::setAdvisorID(int a){
    m_advisorID = a;
}

int Student::getID(){
    return m_id;
}

string Student::toString(){
    return "ID: " + to_string(m_id) + ", Name: " + m_name + ", Year: " + m_level + ", Major: " + m_major + ", GPA: " + to_string(m_gpa) + ", Advisor: " + to_string(m_advisorID);
}

//Boolean that compares the values id to sort BST
bool Student::operator<(const Student &s){
    return ((this->m_id < s.m_id) ? true : false);
}
bool Student::operator>(const Student &s){
    return ((this->m_id > s.m_id) ? true : false);
}
bool Student::operator==(const Student &s){
    return ((this->m_id == s.m_id) ? true : false);
}
bool Student::operator!=(const Student &s){
    return ((this->m_id != s.m_id) ? true : false);
}

#endif