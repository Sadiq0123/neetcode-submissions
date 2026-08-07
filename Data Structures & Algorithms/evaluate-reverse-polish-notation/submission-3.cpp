class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
        // stack<int> stk;
        // for(int i=0; i<tokens.size(); i++) {
        //     string operation = tokens[i];
        //     if (operation == "+") {
        //         int first = stk.top();
        //         stk.pop();
        //         int second = stk.top();
        //         stk.pop();
        //         stk.push(second + first);
        //     } else if (operation == "-") {
        //         int first = stk.top();
        //         stk.pop();
        //         int second = stk.top();
        //         stk.pop();
        //         stk.push(second - first);
        //     }else if (operation == "*") {
        //         int first = stk.top();
        //         stk.pop();
        //         int second = stk.top();
        //         stk.pop();
        //         stk.push(second * first);
        //     }else if (operation == "/") {
        //         int first = stk.top();
        //         stk.pop();
        //         int second = stk.top();
        //         stk.pop();
        //         stk.push(second / first);
        //     } else {
        //         stk.push(stoi(operation));
        //     }
        // }

        // return stk.top();
    }


    int dfs(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back();
        if ((token=="+") || (token=="-") || (token=="*") || (token=="/")) {
            int right = dfs(tokens);
            int left = dfs(tokens);

            if (token == "+") {
                return left + right;
            } else if (token == "-") {
                return left - right;
            } else if (token == "*") {
                return left * right;
            } else if (token == "/") {
                return left / right;
            } 
        } else {
            return stoi(token);
        }
    }
};
