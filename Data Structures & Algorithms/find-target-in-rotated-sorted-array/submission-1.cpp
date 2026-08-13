class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n==1) return nums[0]==target ? 0 : -1;
        int left = nums[0];
        int right = nums[n-1];
        if (left<right) return binarySearch(nums, target, INT_MIN, INT_MAX);
        else if (target>=left) return binarySearch(nums, target, left, INT_MAX);
        else if (target<=right) return binarySearch(nums, target, INT_MIN, right);
        else return -1;
    }

    int binarySearch(vector<int> arr, int target, int low, int high) {
        int n=arr.size();
        int l=0, r=n-1;
        if (n==1) return target==arr[0] ? 0 : -1;
        while(l<=r) {
            int mid = (l+r)/2;
            if (arr[mid]==target) return mid;
            if (arr[mid]<low) {
                r=mid-1;
                continue;
            } else if (arr[mid]>high) {
                l=mid+1;
                continue;
            }

            if (arr[mid]<target) {
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        return -1;
    }
};
