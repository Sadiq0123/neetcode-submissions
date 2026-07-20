class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if (nums.size()<2) return false;
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size()-1; i++) {
        //     if(nums[i]==nums[i+1]) return true;
        // }
        // return false;
        unordered_set<int> sett;
        for(int i=0; i<nums.size(); i++) {
            if (sett.find(nums[i]) != sett.end()) return true;
            sett.insert(nums[i]);
        }
        return false;
    }
};