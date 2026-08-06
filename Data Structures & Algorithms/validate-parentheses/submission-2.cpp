class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
        for(auto c: s) {
            if (mp.find(c) != mp.end()) {
                if (stk.empty() || stk.top() != mp[c]) return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        // for(auto c: s) {
        //     if (c==')') {
        //         if (!stk.empty() && stk.top()=='(') {
        //             stk.pop();
        //             continue;
        //         } else return false;
        //     }
        //     else if (c=='}') {
        //         if (!stk.empty() && stk.top()=='{') {
        //             stk.pop();
        //             continue;
        //         } else return false;
        //     }
        //     else if (c==']') {
        //         if (!stk.empty() && stk.top()=='[') {
        //             stk.pop();
        //             continue;
        //         } else return false;
        //     }
        //     else {
        //         stk.push(c);
        //     }
        // }
        return stk.empty();
    }
};
