class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1, zeroCount = 0;
        for(int i=0; i<nums.size(); i++) {
            if (nums[i]==0) zeroCount++;
            else totalProduct *= nums[i];
        }
        if (zeroCount > 1) {
            return vector<int>(nums.size(), 0);
        }
        vector<int> ans(nums);
        for (int i=0; i<ans.size(); i++) {
            if (zeroCount > 0) {
                ans[i] = (nums[i]==0)? totalProduct : 0;
            } else {
                ans[i] = totalProduct / nums[i];
            }
        }
        return ans;
    }
};
