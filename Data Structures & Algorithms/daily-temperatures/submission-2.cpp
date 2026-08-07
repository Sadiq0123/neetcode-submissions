class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.begin(), temperatures.end());
        int n = temperatures.size();
        int arrMax = arrayMax(temperatures);
        stack<int> stk1, stk2;
        bool isStk1 = true;
        for(int i=0; i<n; i++) {
            if(isStk1) {
                isStk1 = false;
                while(!stk1.empty()) {
                    int temp = stk1.top();
                    stk1.pop();
                    if(temperatures[temp]<temperatures[i]) {
                        ans[temp] = i - temp;
                    } else stk2.push(temp);
                }
            } else {
                isStk1 = true;
                while(!stk2.empty()) {
                    int temp = stk2.top();
                    stk2.pop();
                    if(temperatures[temp]<temperatures[i]) {
                        ans[temp] = i - temp;
                    } else stk1.push(temp);
                }
            }
            if (temperatures[i]>=arrMax) {
                ans[i] = 0;
                continue;
            }
            if(isStk1) stk1.push(i);
            else stk2.push(i);
        }
        if (isStk1) {
            while(!stk1.empty()) {
                int temp = stk1.top();
                stk1.pop();
                ans[temp] = 0;
            }
        } else {
            while(!stk2.empty()) {
                int temp = stk2.top();
                ans[temp] = 0;
                stk2.pop();
            }
        }
        return ans;
    }

    int arrayMax(vector<int> arr) {
        if (arr.size()==0) return 0;
        int maxx = arr[0];
        for(int i=1; i<arr.size(); i++) {
            maxx = max(maxx, arr[i]);
        }
        return maxx;
    }
};
