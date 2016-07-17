/**
 * Question: 024.Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
		ListNode* swapPairs(ListNode* head) {
			if (!head || !head->next)
				return head;
			ListNode* p = head;
			head = head->next;
			ListNode* q = NULL;
			ListNode* prev = NULL;
			while (p->next){
				q = p->next;
				p->next = q->next;
				q->next = p;
				prev = p;
				if (p->next && p->next->next){
					p = p->next;
					prev->next = p->next;
				} else 
					break;
			}
			return head;
		}
};

void printListNode(ListNode* l){
	ListNode* p = l;

	while (p){
        p=p->next;
	}
	cout<<endl;
}

int main(){
	int array[3] = {1,2,3};
	ListNode* head = new ListNode(array[0]);
	ListNode* p = head;
	for (int i=1; i<3; i++){
		cout<<array[i]<<endl;
		p->next = new ListNode(array[i]);
		p = p->next;
	}
	printListNode(head);
	Solution s;
	ListNode* q = s.swapPairs(head);
	printListNode(q);
	return 0;
}
