#include<stdio.h>
#include<malloc.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	ListNode *L = NULL;//��������
	ListNode *r = NULL;//β�巨
	ListNode *p = NULL;//ÿ��ѡ��Ҫ����Ľ��
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
		}//���������ǵ�һ��Ԫ��
		else{
			r->next = p;
			r = p;
		}
		r->next = NULL;//βָ���ÿ�
	}//���������������������ִ��ѭ��
	if(!list1){
		list1 = list2;
	}//�����������Ԫ��û����ͳһ���ΪList1;
	if(r == NULL) {
        L = list1; 
    }
    else r->next = list1;
	return L;
}