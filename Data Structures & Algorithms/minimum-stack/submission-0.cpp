class MinStack {
public:
    vector<int> v;
    int current_ind;
    multiset<int> pq;

    MinStack() {
        v = vector<int>(30000, 0);
        current_ind = 0;
    }
    
    void push(int val) {
        v[current_ind++] = val;
        pq.insert(val);
    }
    
    void pop() {
        pq.erase(pq.find(v[current_ind-1]));
        if (current_ind>0) current_ind--;
    }
    
    int top() {
        if (current_ind>0) return v[current_ind - 1];
        else return 0;
    }
    
    int getMin() {
        auto it = pq.begin();
        return *it;
    }
};
