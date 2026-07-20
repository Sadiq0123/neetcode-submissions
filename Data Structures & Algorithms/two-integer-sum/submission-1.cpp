class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        vector<int> ans;
        // int i=0, j=nums.size()-1;
        // while (i<j) {
        //     if (nums[i]+nums[j]==target) {
        //         ans.push_back(i);
        //         ans.push_back(j);
        //         return ans;
        //     } else if (nums[i]+nums[j]<target) i++;
        //     else j--;
        // }

        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if (nums[i]+nums[j]==target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
                }
            }
        }

        return ans;
    }
};
