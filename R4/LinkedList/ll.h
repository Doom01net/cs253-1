#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_ 

class LinkedList {
  public:
    void initialize();
    bool insert(unsigned int uiData);
    bool remove(unsigned int *pData);

  private:
    struct Link {
	unsigned int m_uiData;
	Link *m_pNext;
	void initialize(unsigned int uiData, Link *pNext);
    } *m_pHead;
};

#endif /* _LINKED_LIST_H_ */ 
