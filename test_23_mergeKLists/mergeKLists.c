#include<stdio.h>
#include<malloc.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

ListNode* merge2Lists(ListNode *l, ListNode *lk){
	ListNode *ret = NULL;//每次合并要返回的链表
	ListNode *rear = NULL;//尾指针
	ListNode *p = NULL;//当前要插入的结点
	while(l && lk){
		if(l->val > lk->val){
			p = lk;
			lk = lk->next;
		}//比较
		else{
			p = l;
			l = l->next;
		}
		if(ret == NULL){
			ret = rear = p;
			rear->next = NULL;
		}//如果r为插入的第一个元素
		else{
			rear->next = p;
			rear = rear->next;
			rear->next = NULL;
		}//如果不为插入的第一个元素
	}//如果两个链表都不为空，则执行比较并合并
	p = l;
	if(!l){
		p = lk;
	}//处理剩下的可能不为空的链表
	if(ret == NULL)
		return p;//如果ret没插入任何元素，可直接返回p
	else if(p){
		rear->next = p;
	}//如果p不为空，将p接在ret后面
	return ret;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
	ListNode *l = NULL;//定义要返回的链表
	int i = 0;//循环变量
	for(i = 0; i < listsSize; i++){
		l = merge2Lists(l, lists[i]);//两两合并
	}
	return l;
}