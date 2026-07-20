class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==k) return nums;
        unordered_map<int, int> count;
        for(auto i: nums) {
            count[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i: count) {
            pq.push(make_pair(i.second, i.first));
        }
        vector<int> ans;
        for(auto i=0; i<k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
