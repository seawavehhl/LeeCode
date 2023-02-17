#include<stdio.h>
#include<malloc.h>
typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode;

struct ListNode *exchange(ListNode *temphead, ListNode *l, int k){
	ListNode *ret = (ListNode*)malloc(sizeof(ListNode));//新创一个表
	ListNode *p = temphead;//结点的临时变量
	ListNode *rear = ret;//标记该组链表尾部
	int i = 0;//循环变量
	ret->next = NULL;
	for(i = 0; i < k; i++){
		p = p->next;
		if(i == k - 1){
			rear->next = temphead->next;
		}//如果是插入最后一个元素，要连接后面的链表
		temphead->next = ret->next;
		ret->next = temphead;
		if(i == 0){
			rear = ret->next;
		}//如果是第一个结点，置rear;
		temphead = p;//更新要连接的结点
	}//头插法
	return ret->next;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){
	ListNode *l = (ListNode*)malloc(sizeof(ListNode));//标记每一次翻转子表的前一个结点
	ListNode *p = l;//循环指针
	ListNode *temphead = head;
	int i = 0;//循环变量
	ListNode *templ = NULL;
	l->next = head;
	templ = l;//l的临时变量
	while(p->next){
		for(i = 0; p->next && i < k; i++){
			p = p->next;
		}//p指针向后移动k步,为下一个头结点
		if(i == k){
			templ->next = exchange(temphead, templ, k);
			templ = temphead;
			p = templ;
			temphead = temphead->next;
		}//如果成功移动k步，则进行交换
	}//如果p不为空指针，则进行处理
	return l->next;
}
int main(){
	int input[] = {1, 2, 3, 4, 5};
	ListNode *head = NULL;
	ListNode *rear = NULL;
	int k = 3;
	int size = sizeof(input)/sizeof(int);
	int i = 0;
	while(i < size){
		if(i == 0){
			head = (ListNode*)malloc(sizeof(ListNode));
			rear = head;
			rear->val = input[i];
			rear->next = NULL;
		}
		else{
			rear->next = (ListNode*)malloc(sizeof(ListNode));
			rear = rear->next;
			rear->val = input[i];
			rear->next = NULL;
		}
		i++;
	}
	head = reverseKGroup(head, k);
	for(i = 0; i < size; i++){
		printf("%d", head->val);
		head = head->next;
	}
	return 0;
}