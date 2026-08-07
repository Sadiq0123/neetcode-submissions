class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0; i<tokens.size(); i++) {
            string operation = tokens[i];
            if (operation == "+") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(second + first);
            } else if (operation == "-") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(second - first);
            }else if (operation == "*") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(second * first);
            }else if (operation == "/") {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                stk.push(second / first);
            } else {
                stk.push(stoi(operation));
            }
        }

        return stk.top();
    }
};
