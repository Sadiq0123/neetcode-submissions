class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans{1, 2};
        if (numbers.size()<=2) return ans;
        int i=0, j=numbers.size()-1;
        while(i<j) {
            int current = numbers[i] + numbers[j];
            if (current==target) {
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }
            else if (current<target) {
                while(i<j && numbers[i]==numbers[i+1]) i++;
                i++;
            }
            else {
                while(i<j && numbers[j]==numbers[j-1]) j--;
                j--;
            }
        }
        return ans;
    }
};
