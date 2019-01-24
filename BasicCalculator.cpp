//https://leetcode.com/problems/basic-calculator/
//recursion
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1;
        for(int i = 0; i < s.size(); ++i){
        	char c = s[i];
        	if(c >= '0' && c <= '9'){
        		num = 10*num + (c - '0');
        	}
        	else if(c == '('){
        		int j = i, cnt = 0;
        		for(; i < s.size(); ++i){
        			if(s[i] == '(')++cnt;
        			if(s[i] == ')')--cnt;
        			if(cnt == 0)break;
        		}
        		num = calculate(s.substr(j + 1, i - j - 1));
        	}
        	if(c == '+' || c == '-'|| i == s.size() - 1){
        		res += num * sign;
        		num = 0;
        		sign = (c == '+')?1:-1;
        	}
        }
        return res;
    }
};

//stack
class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1;
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
        	char c = s[i];
        	if(c >= '0' && c <= '9'){
        		num = 10*num + (c - '0');
        	}
        	else if(c == '+' || c == '-'){
        		res += num * sign;
        		num = 0;
        		sign = (c == '+')?1:-1;
        	}
        	else if(c == '('){
        		st.push(res);
        		st.push(sign);
        		res = 0;
        		sign = 1;
        	}
        	else if(c == ')'){
        		res += num * sign;
        		num = 0;
        		res *= st.top();st.pop();
        		res += st.top();st.pop();
        	}
        }
        res += num * sign;
        return res;
    }
};

//Basic Calculator II
class Solution {
public:
    int calculate(string s) {
    	int res = 0;
    	int num = 0;
    	char presign = '+';
    	stack<int> st;
    	for(int i = 0; i < s.size(); ++i){
    		char c = s[i];
    		if(c <= '9' && c >= '0'){
    			num = 10 * num + c -'0';
    		}
    		if(c == '+'||c == '-'||c == '*'||c == '/'|| i == s.size() - 1){
    			if(presign == '+')st.push(num);
    			if(presign == '-')st.push(-num);
    			if(presign == '/'||presign == '*'){
    				int tmp = (presign == '*') ? st.top()*num : st.top()/num;
    				st.pop();
    				st.push(tmp);
    			}
    			presign = c;
    			num = 0;
    		}
    	}
    	while(!st.empty()){
    		res += st.top();
    		st.pop();
    	}
    	return res;
    }
};

class Solution {
public:
    int calculate(string s) {
        int res = 0, curRes = 0, num = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            } 
        }
        return res;
    }
};


//Basic Calculator III

class Solution {
public:
    int calculate(string s) {
        int n = s.size(), num = 0, curRes = 0, res = 0;
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '(') {
                int j = i, cnt = 0;
                for (; i < n; ++i) {
                    if (s[i] == '(') ++cnt;
                    if (s[i] == ')') --cnt;
                    if (cnt == 0) break;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) {
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                if (c == '+' || c == '-' || i == n - 1) {
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};
















