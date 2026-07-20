class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()<2) return nums.size(); 
        unordered_map<int, int> linkExists;
        for(auto i: nums) {
            linkExists[i]++;
        }
    
        int ans = 0;
        for(auto i: nums) {
            ans = max(ans, getLength(linkExists, i));
        }
        return ans;
    }

    int getLength(unordered_map<int, int> linkExists, int k) {
        int ans = 0;
        int current = k;
        while(linkExists[current]>0) {
            ans++;
            current++;
        }
        return ans;
    }
};
