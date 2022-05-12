#include "Person.h"
using namespace std;
class Faculty : public Person
{
    public:
	    Faculty();
        ~Faculty();
        Faculty(int id, string name, string level, string department, DoublyLinkedList<int> *studentIDList);
        void removeStudent(int id);
        DoublyLinkedList<int> getList();
        int getListSize();
        void addStudent(int id);

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

int Faculty::getListSize(){
    return m_studentIDList->getSize();
}

DoublyLinkedList<int> Faculty::getList(){
    return m_studentIDList;
}

void Faculty::removeStudent(int id){
    for(int i = 0; i < m_studentIDList->getSize(); ++i){
        Student *s = m_studentIDList->removeFront();
        if(s->key->getID() == id){
            break;
        }
        m_studentIDList->insertBack(s);
    }
}

void Faculty::addStudent(int id){
    m_studentIDList->insertBack(id);
}
