#include<stdio.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* swapPairs(struct ListNode* head){
	ListNode *p = NULL;//������ʱ���
	if(head && head->next){
		head->next->next = swapPairs(head->next->next);//�ݹ齻�����������
		p = head->next;
		head->next = p->next;
		p->next = head;
		return p;
	}//�������������㲻Ϊ��
	else return head;
}