#include "Person.h"
using namespace std;
class Student : public Person
{
    public:
	    Student();
        ~Student();
        Student(int id, string name, string level, string major, double gpa, int advisorID);
        getAdvisor();
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