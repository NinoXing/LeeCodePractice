/**
A linked list is given such that 
each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode* res = new RandomListNode(head->label);
        RandomListNode* node = res;
        RandomListNode* cur = head->next;
        map<RandomListNode*, RandomListNode*> m;
        m[head] = res;
        while(cur){
        	RandomListNode* tmp = new RandomListNode(cur->label);
        	node->next = tmp;
        	m[cur] = tmp;
        	node = node->next;
        	cur = cur->next;
        }

        node = res;
        cur = head;
        while(node){
        	node->random = m[cur->random];
        	node = node->next;
        	cur = cur->next;
        }
        return res;
    }
};