/**
 * Question: 023.Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution{
	private:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
			if (l1 == l2) return l1;
			if (!l1 && !l2) return NULL;
			if (l1 == NULL) return l2;
			if (l2 == NULL) return l1;
			
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
				if (!p || (q &&q->val <= p->val)){
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
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if (lists.empty()) return NULL;
			while (lists.size()>1) {
				int left = 0;
				int right = lists.size() - 1;
				while (left<=right){
					lists[left] = mergeTwoLists(lists[left], lists[right]);
					left ++;
					right --;
				}
				lists.resize(left);
			}
			return lists[0];
		}
};

int main(){
	
	Solution s;

	return 0;
}
