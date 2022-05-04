#include "Person.h"
using namespace std;
class Faculty : public Person
{
    public:
	    Faculty();
        ~Faculty();
        Faculty(int id, string name, string level, string major, double gpa, int advisorID);
    private:
        string m_department;
        //list of student ID nums
};
Faculty::Faculty(){
    m_id = 0;
    m_name = "";
    m_level = "";
    m_department = "";
    //list of student ID nums
}

Faculty::~Faculty(){}

Faculty::Faculty(int id, string name, string level, string department, /*list of student ID nums*/){
    m_id = id;
    m_name = name;
    m_level = level;
    m_department = "";
    //list of student ID nums
}