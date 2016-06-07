/**
 * Question: 002
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order 
 * and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *		Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *		Output: 7 -> 0 -> 8
 */
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

ListNode* createListByNum(int num){
	if (num <= 0){
		return NULL;
	}
	int temp = num;
	ListNode* head = NULL;
	ListNode* p;
	while (temp > 0){
		int unit = temp%10;
		temp /= 10;

		if (head == NULL){
			head = new ListNode(unit);
			p = head;
		} else {
			p->next = new ListNode(unit);
			p = p->next;
		}
	}
	return head;
}

void printListNode(ListNode* l){
	ListNode* p = l;
	while (p){
		cout<<p->val<<"->";
		p = p->next;
	}
	cout << endl;
}

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
			ListNode* result = NULL;
			ListNode* p;
			ListNode* p1=l1;
			ListNode* p2=l2;
			int sum = 0;
			while (p1||p2||sum){
				sum = (p1?p1->val:0) + (p2?p2->val:0) + sum;	
				cout << sum <<endl;
				if (result == NULL){
					result = new ListNode(sum%10);
					p = result;
				} else {
					p->next = new ListNode(sum%10);
					p = p->next;
				}
				sum = sum / 10;
				p1 = p1?p1->next:p1;
				p2 = p2?p2->next:p2;
			}
			return result;
		}
};

int main(){
	int a = 465;
	int b = 342;
	ListNode* l1 = createListByNum(a);
	ListNode* l2 = createListByNum(b);
	Solution s;
	ListNode* result = s.addTwoNumbers(l1, l2);
	printListNode(result);
	return 0;
}

