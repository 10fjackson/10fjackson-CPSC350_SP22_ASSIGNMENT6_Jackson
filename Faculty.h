#ifndef Faculty_H
#define Faculty_H
#include "Person.h"
using namespace std;
class Faculty : public Person
{
    public:
	    Faculty();
        ~Faculty();
        Faculty(int id, string name, string level, string department, DoublyLinkedList<int> *studentIDList);
        void removeStudent(int id);
        DoublyLinkedList<int>* getList();
        int getListSize();
        void addStudent(int id);
        int getID();
        string toString();
        bool operator<(const Faculty &s); 
        bool operator>(const Faculty &s);
        bool operator==(const Faculty &s);
        bool operator!=(const Faculty &s);
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
    m_department = department;
    m_studentIDList = studentIDList;
}

int Faculty::getID(){
    return m_id;
}

int Faculty::getListSize(){
    return m_studentIDList->getSize();
}

DoublyLinkedList<int>* Faculty::getList(){
    return m_studentIDList;
}

void Faculty::removeStudent(int id){
    for(int i = 0; i < m_studentIDList->getSize(); ++i){
        int s = m_studentIDList->removeFront();
        if(s == id){
            break;
        }
        m_studentIDList->insertBack(s);
    }
}

void Faculty::addStudent(int id){
    m_studentIDList->insertBack(id);
}

string Faculty::toString(){
    return "ID: " + to_string(m_id) + ", Name: " + m_name + ", Level: " + m_level + ", Department: " + m_department; //+ ", Advisees: " + to_string(getAdvisees());;
}

bool Faculty::operator<(const Faculty &s){
    return ((this->m_id < s.m_id) ? true : false);
}
bool Faculty::operator>(const Faculty &s){
    return ((this->m_id > s.m_id) ? true : false);
}
bool Faculty::operator==(const Faculty &s){
    return ((this->m_id == s.m_id) ? true : false);
}
bool Faculty::operator!=(const Faculty &s){
    return ((this->m_id != s.m_id) ? true : false);
}

#endif