#include<stdio.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* swapPairs(struct ListNode* head){
	ListNode *p = NULL;//定义临时结点
	if(head && head->next){
		head->next->next = swapPairs(head->next->next);//递归交换后面的链表
		p = head->next;
		head->next = p->next;
		p->next = head;
		return p;
	}//如果相邻两个结点不为空
	else return head;
}