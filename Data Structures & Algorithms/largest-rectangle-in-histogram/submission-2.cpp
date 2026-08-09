class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        set<int> s;
        for(int i=0; i<n; i++) {
            if (s.find(i)!=s.end()) {
                continue;
            }
            int minHeight = INT_MAX;
            for(int j=i; j<n; j++) {
                minHeight = min(minHeight, heights[j]);
                if (minHeight>=heights[j]) {
                    s.insert(j);
                }
                int width = j-i+1;
                int area = minHeight * width;

                ans = max(ans, area);
            }
        }
        return ans;
    }
};
