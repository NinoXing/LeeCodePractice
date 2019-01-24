hiwleclass MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        helper.push(x);
        while(helper.size() > 1){
            q.push(helper.front());
            helper.pop();
        }

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = helper.front();
        helper.pop();

        int size = q.size();
        if(size() > 0){
            for(int i = 0; i < size - 1; ++i){
                q.push(q.front());
                q.pop();
            }
            helper.push(q.front());
            q.pop();
        }
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return helper.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty() && helper.empty();
    }
private:
    queue<int> q;
    queue<int> helper;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */