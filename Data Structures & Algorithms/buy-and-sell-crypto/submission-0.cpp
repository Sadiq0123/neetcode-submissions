class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n==1) return 0;
        int ans = 0, minimum = prices[0];
        for(int i=0; i<n; i++) {
            if (prices[i]>minimum+ans) ans = prices[i] - minimum;
            minimum = min(minimum, prices[i]); 
        }
        return ans;
    }
};
