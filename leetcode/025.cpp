/**
 * Question: 025.Reverse Nodes in k-Group
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 */
#include<iostream>

using namespace std;

struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

class Solution{

	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if (!head || !(head->next) || k<2) return head;

			// count k nodes
			ListNode* nextgp = head;
			for (int i=0; i<k; i++){
				if (nextgp)
					nextgp = nextgp->next;
				else
					return head;
			}
			
			// reverse
			ListNode* prev = NULL;
			ListNode* cur = head;
			ListNode* next = NULL;
			while (cur != nextgp){
				next = cur->next;
				if (prev)
					cur->next = prev;
				else 
					cur->next = reverseKGroup(nextgp, k);
				prev = cur;
				cur = next;
			}
			return prev;
		}
};

void printList(ListNode* l){
	ListNode* p = l;
	while (p){
		cout<<p->val<<"->";
		p = p->next;
	}
	cout<<endl;
}

int main(){
	int a[5]={1,2,3,4,5};
	ListNode* head = new ListNode(a[0]);
	ListNode* p = head;
	for (int i=1; i<5; i++){
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	printList(head);
	Solution s;
	ListNode* r = s.reverseKGroup(head, 4);
	printList(r);
	return 0;
}
