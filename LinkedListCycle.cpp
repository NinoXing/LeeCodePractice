//I
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* cur = head;
        while(cur){
            if(!set.count(cur)){
                set.insert(cur);
                cur = cur->next;
            }
            else
                return true;
        }
        return false;
    }
};

//II 返回位置
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* cur = head;
        while(cur){
            if(!set.count(cur)){
                set.insert(cur);
                cur = cur->next;
            }
            else
                return cur;
        }
        return NULL;
    }
};

//因为快指针每次走2，慢指针每次走1，快指针走的距离是慢指针的两倍。
//而快指针又比慢指针多走了一圈。所以head到环的起点+环的起点到他们相遇的点的距离 与 环一圈的距离相等。
//现在重新开始，head运行到环起点 和 相遇点到环起点 的距离也是相等的，相当于他们同时减掉了 环的起点到他们相遇的点的距离
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};