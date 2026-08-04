class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> pq;
        int n = nums.size();
        vector<int> ans;
        if (n<k) return ans;

        for(int i=0; i<n; i++) {
            pq.insert(nums[i]);
            if (i<k-1) {
                continue;
            } else {
                auto it = pq.end();
                it--;
                ans.push_back(*it);
                pq.erase(pq.find(nums[i-k+1]));
            }
        }

        return ans;
    }
};
