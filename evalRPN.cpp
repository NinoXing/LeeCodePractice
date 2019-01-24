class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> RPN;
        int res = 0;
        for(string s : tokens){
        	if(s == "+"){
        		int num1 = RPN.top();
        		RPN.pop();
        		int num2 = RPN.top();
        		RPN.pop();
        		int num3 = num1 + num2;
        		RPN.push(num3);
        		res += num3;
        	}
        	else if(s == "-"){
        		int num1 = RPN.top();
        		RPN.pop();
        		int num2 = RPN.top();
        		RPN.pop();
        		int num3 = num1 - num2;
        		RPN.push(num3 );
        		res += num3;
        	}
        	else if(s == "*"){
        		int num1 = RPN.top();
        		RPN.pop();
        		int num2 = RPN.top();
        		RPN.pop();
        		int num3 = num1 * num2;
        		RPN.push(num3);
        		res += num3;
        	}
        	else if(s == "/"){
        		int num1 = RPN.top();
        		RPN.pop();
        		int num2 = RPN.top();
        		RPN.pop();
        		int num3 = num2 / num1;
        		RPN.push(num3);
        		res += num3;
        	}
        	else
        		RPN.push(stoi(s));
        }
        return res;
    }
};