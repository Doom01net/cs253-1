#include <cstdlib>
#include "ll.h" 

void LinkedList::Link::initialize(unsigned int uiData, Link *pNext) {
    m_uiData = uiData;
    m_pNext = pNext;
}

void LinkedList::initialize() {
    this->m_pHead = nullptr;
}

bool LinkedList::insert(unsigned int uiData) {
    Link* new_link = new Link;

    new_link->initialize(uiData, this->m_pHead);
    this->m_pHead = new_link;

    return true;
}

bool LinkedList::remove(unsigned int *pData) {

    bool ret_val = false;

    if (this->m_pHead != nullptr) {
	Link *temp = this->m_pHead;
	this->m_pHead = this->m_pHead->m_pNext;
	*pData = temp->m_uiData;

	ret_val = true;
    }

    return ret_val;
}
