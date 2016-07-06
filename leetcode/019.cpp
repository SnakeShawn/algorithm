/**
 * Question: 019.Remove Nth Node From End of List 
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *		Given linked list: 1->2->3->4->5, and n = 2.
 *		After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 */
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{

	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* begin = head;
			ListNode* end = head;
			for (int i=0; i<n; i++){
				if (end == NULL) return head;
				end = end->next;
			}
			if (end == NULL) return head->next;
			while (end->next != NULL){
				end = end->next;
				begin = begin->next;
			}
			begin->next = begin->next->next;
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
	
	Solution s;
	ListNode* head = NULL;
	ListNode* p;
	for (int i=0; i<4; i++) {
		if (head == NULL){
			head = new ListNode(0);
			p = head;
		} else {
			p->next = new ListNode(i);
			p = p->next;
		}
	}
	printListNode(head);
	s.removeNthFromEnd(head,2);
	printListNode(head);
	return 0;
}
