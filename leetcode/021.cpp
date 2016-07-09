/**
 * Question: 021.Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 */
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution{

	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (!l1 && !l2) return NULL;
			if (!l1) return l2;
			if (!l2) return l1;
			
			ListNode* head = NULL;
			
			ListNode* p = l1;
			ListNode* q = l2;
			if (p->val >= q->val){
				head = q;
				q = q->next;
			} else {
				head = p;
				p = p->next;
			}
			
			ListNode* l = head;
			while (p||q){
				if (!p || (q&&q->val<=p->val)){
					l->next = q;
					q = q->next;
				} else {
					l->next = p;
					p = p->next;
				}
				l = l->next;
			}
			return head;
		}
};

void printListNode(ListNode* l){
	ListNode* p = l;
	while(p){
		cout<<p->val<<"->";
		p = p->next;
	}
	cout<<endl;
}

int main(){
	int arr1[6] = {2,14,16,34,88,100};
	ListNode* l1 = NULL;
	ListNode* p1;
	for (int i=0; i<6; i++){
		if (l1 == NULL){
			l1 = new ListNode(arr1[i]);
			p1 = l1;
		} else {
			p1->next = new ListNode(arr1[i]);
			p1 = p1->next;
		}
	}
	int arr2[4] = {3, 29,45,66};
	ListNode* l2 = NULL;
	ListNode* p2;
	for (int i=0; i<4; i++){
		if (l2 == NULL){
			l2 = new ListNode(arr2[i]);
			p2 = l2;
		} else {
			p2->next = new ListNode(arr2[i]);
			p2 = p2->next;
		}
	}
	printListNode(l1);
	printListNode(l2);

	Solution s;
	ListNode* l = s.mergeTwoLists(l1, l2);
	printListNode(l);
	
	return 0;
}
