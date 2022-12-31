#include<stdio.h>
#include<malloc.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int temp1 = 0, temp2 = 0;//temp2为进位位
	ListNode *p, *l3 = NULL, *rear = NULL;
	while(l1 != NULL && l2 != NULL){//从头开始遍历
        temp1 = l1->val + l2->val + temp2;
		p = (ListNode *)malloc(sizeof(ListNode));
		p->next = NULL;//结构体里的指针必须初始化
		p->val = temp1 % 10;
		temp2 = temp1 /10;
		if(l3 == NULL){
			l3 = p;
			rear = p;
		}
		else{
			rear->next = p;
			rear = rear->next;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	if(l1) l2 = l1;//如果链表l1或l2还有数字没遍历完，则继续遍历该链表
	while(l2){
		p = (ListNode *)malloc(sizeof(ListNode));
		p->next = NULL;
		p->val = (l2->val + temp2) % 10;
		temp2 = (l2->val + temp2) / 10;
		rear->next = p;
		rear = p;
		l2 = l2->next;
	}
	if(temp2){//如果最后一次加法进位位不为0
		p = (ListNode *)malloc(sizeof(ListNode));
		p->next = NULL;
		p->val = temp2;
		rear->next = p;
		rear = p;
	}
	return l3;
}