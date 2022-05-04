#include "Person.h"
using namespace std;
class Faculty : public Person
{
    public:
	    Faculty();
        ~Faculty();
        Faculty(int id, string name, string level, string department, DoublyLinkedList<int> *studentIDList);
    private:
        string m_department;
        DoublyLinkedList<int> *m_studentIDList;
};
Faculty::Faculty(){
    m_id = 0;
    m_name = "";
    m_level = "";
    m_department = "";
    m_studentIDList = new DoublyLinkedList<int>();
}

Faculty::~Faculty(){}

Faculty::Faculty(int id, string name, string level, string department, DoublyLinkedList<int> *studentIDList){
    m_id = id;
    m_name = name;
    m_level = level;
    m_department = "";
    m_studentIDList = studentIDList;
}
