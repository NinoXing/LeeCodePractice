/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *curA = headA, *curB = headB;

        while(curA){
        	lenA++;
        	curA = curA->next;
        }
        while(curB){
        	lenB++;
        	curB = curB->next;
        }

        if(lenB >= lenA){
        	curB = headB;
        	curA = headA;
        }
        else{
        	curB = headA;
        	curA = headB;
        }
        
       	int cnt = abs(lenB - lenA);

       	while(cnt>0){
       		curB = curB->next;
       		cnt--;
        }

        while(curA && curB && curB!=curA){
        	curA = curA->next;
        	curB = curB->next;
        }
        return (curA && curB)?curA : NULL;
        
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};