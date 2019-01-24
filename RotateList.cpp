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
    ListNode* rotateRight(ListNode* head, int k) {
    	if(k==0 || head==NULL)return head;
        int n=0;
        ListNode *p = head;
        ListNode *q = head;
        ListNode *res;
        while(p!=NULL){
        	n++;
        	p=p->next;
        }
        p = head;
        k=k%n;
        if(k==0)return head;
        int count = 0;
        while(p->next!=NULL){
        	p=p->next;
        	count++;
        	if(count>k)q=q->next;
        }
        p->next = head;
        res=q->next;
        q->next=NULL;
        return res;

    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(k==0 || head==NULL)return head;
        int n=1;
        ListNode *p = head;
        ListNode *res;
        while(p->next!=NULL){
        	n++;
        	p=p->next;
        }
        p->next = head;
        k=n-k%n;
        for(int i=0; i<k; i++){
        	p=p->next;
        }
        res=p->next;
        p->next=NULL;
      
        return res;

    }
};