#include<stdio.h>
#include<malloc.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	ListNode *L = NULL;//所求链表
	ListNode *r = NULL;//尾插法
	ListNode *p = NULL;//每次选定要插入的结点
	while(list1 && list2){
		if(list1->val < list2->val){
			p = list1;
			list1 = list1->next;
		}
		else{
			p = list2;
			list2 = list2->next;
		}
		if(r == NULL){
			L = p;//
			r = p;//
		}//如果插入的是第一个元素
		else{
			r->next = p;
			r = p;
		}
		r->next = NULL;//尾指针置空
	}//如果两个链表都还有数，则执行循环
	if(!list1){
		list1 = list2;
	}//如果有链表还有元素没排序，统一标记为List1;
	if(r == NULL) {
        L = list1; 
    }
    else r->next = list1;
	return L;
}