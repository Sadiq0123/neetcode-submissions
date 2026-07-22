class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if (nums.size()<2) return nums.size(); 
        // unordered_map<int, int> linkExists;
        // for(auto i: nums) {
        //     linkExists[i]++;
        // }
    
        // int ans = 0;
        // for(auto i: nums) {
        //     ans = max(ans, getLength(linkExists, i));
        // }
        // return ans;

        // sort(nums.begin(), nums.end());
        // int i=0;
        // int streak = 0;
        // int ans = 0;
        // while(i<nums.size()) {
        //     if (i>0) {
        //         if (nums[i]==nums[i-1]) continue;
        //         else if (nums[i]==nums[i-1]+1) streak++;
        //         else streak=1;
        //     } else {
        //         streak++;
        //     }
        //     ans = max(ans, streak);
        //     i++;
        // }
        // return ans;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int ans = 0;

        for(auto num: nums) {
            if (numSet.find(num-1) == numSet.end()) {
                int length = 1;
                while(numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }

    // int getLength(unordered_map<int, int> linkExists, int k) {
    //     int ans = 0;
    //     int current = k;
    //     while(linkExists[current]>0) {
    //         ans++;
    //         current++;
    //     }
    //     return ans;
    // }
};
