class MinStack {
public:
    // vector<int> v;
    // int current_ind;
    // multiset<int> pq;
    stack<int> stk, stkMin;

    MinStack() {
    }
    
    void push(int val) {
        if (stk.empty()) stkMin.push(val);
        else stkMin.push(min(stkMin.top(), val));
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
        stkMin.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return stkMin.top();
    }
};
