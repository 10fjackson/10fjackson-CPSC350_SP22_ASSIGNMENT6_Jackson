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
        DoublyLinkedList<int> *studentIDList
};
Faculty::Faculty(){
    m_id = 0;
    m_name = "";
    m_level = "";
    m_department = "";
    studentIDList = new DoublyLinkedList<int>();
}

Faculty::~Faculty(){}

Faculty::Faculty(int id, string name, string level, string department, /*list of student ID nums*/){
    m_id = id;
    m_name = name;
    m_level = level;
    m_department = "";
    DoublyLinkedList<int> *studentIDList = new DoublyLinkedList<int>();
}
