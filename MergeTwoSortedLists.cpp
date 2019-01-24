/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//链表做法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode(-1);
        ListNode* cur = ans;
        while(l1 && l2){
        	if(l1->val < l2->val){
        		cur->next = l1;
        		l1 = l1->next;
        	}
        	else{
        		cur->next = l2;
        		l2 = l2->next;
        	}
        	cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return ans->next;
    }
};


//递归做法

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(!l1)return l2;
    	if(!l2)return l1;
    	if(l1->val < l2->val){
    		l1->next = mergeTwoLists(l1->next , l2);
    		return l1;
     	}
     	else{
     		l2->next = mergeTwoLists(l1 , l2->next);
     		return l2;
     	}
    }
};

//How to Merge K Sorted List

//By Divide and Conquer 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)return NULL;
        int n = lists.size();
        while(n>1){
            k = (n+1)/2;
            for(int i=0 ; i<n/2 ; ++i){
                lists[i] = mergeTwoLists(lists[i], lists[i+k]);
            }
            n = k;
        }
        
        return list[i];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next , l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1 , l2->next);
            return l2;
        }
    }
};


//use priority_queue 因为它本身自带一个排序。。
//但是要先写一个cmp

class Solution {
private:
    struct cmp{
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }

    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp>q;
        for(int i=0 ; i<lists.size() ; ++i){
            if(lists[i])q.push(lists[i]);
        }

        ListNode* cur = NULL;
        ListNode* tmp = NULL;
        ListNode* head = new ListNode(-1);
        tmp = head;

        while(!q.empty()){

            cur = q.top();
            tmp->next = cur;
            tmp = tmp->next;
            q.pop();
            if(cur->next)q.push(cur->next);
        }

        return head->next;
        
    }
};






















