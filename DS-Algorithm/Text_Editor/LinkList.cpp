#include "pch.h"


doubleLinkList::doubleLinkList() {
	init();
}
doubleLinkList::~doubleLinkList() {
	clear();			// �������
	delete head;		
}

void doubleLinkList::clear() {
	while (length()> 0)
	{
		Delete(1);
	}
}

void doubleLinkList::init()
{
	head = new dbNode;	// ����ͷָ��
	head->next = head;				
	head->back = head;				
	curPtr = head;	
	curPosition = 0;	// ��ʼ����ǰλ��
	count = 0;			// ��ʼ��Ԫ�ظ���
}

dbNode*doubleLinkList::getElemPtr(int position) const{
	if (curPosition < position)
	{
		for (; curPosition < position; curPosition++)
			curPtr = curPtr->next;
	}
	else if (curPosition > position)
	{
		for (; curPosition > position; curPosition--)
			curPtr = curPtr->back;
	}
	return curPtr;
}

string doubleLinkList::getElem(int position) {
	return getElemPtr(position)->data;
}

void doubleLinkList::setElem(int position, string s) {
	dbNode* tmpPtr;
	tmpPtr = getElemPtr(position);
	tmpPtr->data = s;
}

int doubleLinkList::length() const {
	return count;
}

bool doubleLinkList::empty() const{
	return head->next == head;
}

bool doubleLinkList::view() {
	if (count < 1)return 0;
	dbNode* temPtr = head->next;
	while (temPtr != head)
	{
		cout << temPtr->data << endl;
		temPtr = temPtr->next;
	}
	return 1;
}
int doubleLinkList::statistic() {    //a
	dbNode* temPtr = head->next;
	int cnt = 0;
	while (temPtr != head)
	{
		cnt += (temPtr->data).size();
		temPtr = temPtr->next;
	}
	return cnt;
}

bool doubleLinkList::Delete(int position) {
	if (position < 1 || position > length())
	{	// position��Χ��
		return 0;
	}
	else
	{	
		dbNode *tmpPtr;
		tmpPtr = getElemPtr(position - 1);		
		tmpPtr = tmpPtr->next;					
		tmpPtr->back->next = tmpPtr->next;		// �޸�ǰһ��ָ��
		tmpPtr->next->back = tmpPtr->back;		// �޸ĺ�һ��ָ��
		if (position == length())
		{	
			curPosition = 0;					// ���õ�ǰλ�õ����
			curPtr = head;						// ����ָ��ǰλ�õ�ָ��
		}
		else
		{	
			curPosition = position;				
			curPtr = tmpPtr->next;				
		}
		count--;								 
		delete tmpPtr;							// �ͷű�ɾ���
		return 1;
	}
}
bool doubleLinkList::insert(int position,string s){
	if (position < 1 || position > length() + 1)
	{	
		return 0; 
	}
	else
	{	
		dbNode* tmpPtr, *nextPtr, *newPtr;
		tmpPtr = getElemPtr(position - 1);	// ǰһ��λ��
		nextPtr = tmpPtr->next;				// ��һ��
		newPtr = new dbNode(s, tmpPtr, nextPtr); //(elem , back , next)
		tmpPtr->next = newPtr;				// �޸����ҵ�ָ��
		nextPtr->back = newPtr;				// �޸������ָ��
		curPosition = position;				// ���õ�ǰλ�õ����
		curPtr = newPtr;					// ָ��ǰλ�õ�ָ��
		count++;							// ����ɹ���Ԫ�ظ�����1 
		return 1;
	}
}