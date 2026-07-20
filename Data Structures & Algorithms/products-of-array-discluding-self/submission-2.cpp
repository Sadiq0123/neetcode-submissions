class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int totalProduct = 1, zeroCount = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     if (nums[i]==0) zeroCount++;
        //     else totalProduct *= nums[i];
        // }
        // if (zeroCount > 1) {
        //     return vector<int>(nums.size(), 0);
        // }
        // vector<int> ans(nums);
        // for (int i=0; i<ans.size(); i++) {
        //     if (zeroCount > 0) {
        //         ans[i] = (nums[i]==0)? totalProduct : 0;
        //     } else {
        //         ans[i] = totalProduct / nums[i];
        //     }
        // }
        // return ans;

        // vector<int> prefix(nums), suffix(nums);
        // int n = nums.size();
        // for(int i=0; i<n; i++) {
        //     if (i==0) prefix[i] = 1;
        //     else prefix[i] = nums[i-1] * prefix[i-1];
        // }
        // for(int i=n-1; i>=0; i--) {
        //     if (i==n-1) suffix[i] = 1;
        //     else suffix[i] = nums[i+1] * suffix[i+1];
        // }
        // vector<int> ans(n, 1);
        // for(int i=0; i<n; i++) {
        //     ans[i] = suffix[i] * prefix[i];
        // }
        // return ans;

        int n = nums.size();
        vector<int> ans(n, 1);
        int temp = 1;
        for(int i=1; i<n; i++) {
            temp = temp * nums[i-1];
            ans[i] = temp;
        }
        temp = 1;
        for(int i=n-2; i>=0; i--) {
            temp = temp * nums[i+1];
            ans[i] = ans[i] * temp;
        }
        return ans;
    }
};
