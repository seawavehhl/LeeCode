#include<stdio.h>
#include<malloc.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

ListNode* merge2Lists(ListNode *l, ListNode *lk){
	ListNode *ret = NULL;//ÿ�κϲ�Ҫ���ص�����
	ListNode *rear = NULL;//βָ��
	ListNode *p = NULL;//��ǰҪ����Ľ��
	while(l && lk){
		if(l->val > lk->val){
			p = lk;
			lk = lk->next;
		}//�Ƚ�
		else{
			p = l;
			l = l->next;
		}
		if(ret == NULL){
			ret = rear = p;
			rear->next = NULL;
		}//���rΪ����ĵ�һ��Ԫ��
		else{
			rear->next = p;
			rear = rear->next;
			rear->next = NULL;
		}//�����Ϊ����ĵ�һ��Ԫ��
	}//�������������Ϊ�գ���ִ�бȽϲ��ϲ�
	p = l;
	if(!l){
		p = lk;
	}//����ʣ�µĿ��ܲ�Ϊ�յ�����
	if(ret == NULL)
		return p;//���retû�����κ�Ԫ�أ���ֱ�ӷ���p
	else if(p){
		rear->next = p;
	}//���p��Ϊ�գ���p����ret����
	return ret;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
	ListNode *l = NULL;//����Ҫ���ص�����
	int i = 0;//ѭ������
	for(i = 0; i < listsSize; i++){
		l = merge2Lists(l, lists[i]);//�����ϲ�
	}
	return l;
}