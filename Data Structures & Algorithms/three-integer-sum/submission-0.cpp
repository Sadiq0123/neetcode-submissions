class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto num: nums) {
            mp[num]++;
        }
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++) {
            mp[nums[i]]--;
            if (i>0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1; j<n; j++) {
                mp[nums[j]]--;
                if (j>i+1 && nums[j]==nums[j-1]) continue;

                int target = (nums[i] + nums[j]) * -1;
                if (mp[target]) {
                    ans.push_back({nums[i], nums[j], target});
                }
            }

            for(int j=i+1; j<n; j++) {
                mp[nums[j]]++;
            }
        }

        return ans;

        // int i=0;
        // while(i<n-2) {
        //     mp[nums[i]]--;
        //     int l=i+1;
        //     while(l<n) {
        //         mp[nums[l]]--;
        //         if(l>i+1 && l<n && nums[l]==nums[l-1]) {
        //             l++;
        //             continue;
        //         }
        //     }


        //     mp[nums[i]]++;

        //     while(i<n-2 && nums[i]==nums[i+1]) i++;
        //     i++;
        // }


        // for(int i=0; i<nums.size(); i++) {
        //     vector<int> temp(nums.begin(), nums.end());
        //     temp.erase(i, 1);
        //     vector<vector
        // }

        // unordered_map<int, int> mp;
        // for(auto num: nums) {
        //     mp[num]++;
        // }

        // unordered_set<unordered_set<int>> unique;

        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size(); i++) {
        //     vector<int> current(nums.begin(), nums.end());
        //     current.erase(i, 1);
        //     unordered_set<unordered_set<int>> temp = find2sum(current, -1*nums[i]);
        //     for(auto t: temp) {
        //         unique.push(t);
        //     }
        // }

        // for(auto u: unique) {
        //     ans.push_back(vector<int>{u});
        // }
        // return ans;
    }

    // unordered_set<unordered_set<int>> find2sum(vector<int> arr, int target) {
    //     unordered_set<unordered_set<int>> ans;
    //     if (arr.size()<2) return ans;
    //     int i=0, j=arr.size()-1;
    //     while(i<j) {
    //         if (arr[i]+arr[j]==target) {
    //             unordered_set<int> currentSet{target, arr[i], arr[j]};
    //             ans.insert(currentSet);

    //         } else if (arr[i]+arr[j]<target) {
    //             i++;
    //         } else j--;
    //     }
    //     return ans;
    // }
};
