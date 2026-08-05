class SegmentTree {
public:
    vector<int> arr;
    vector<int> tree;

    void begin(vector<int> ar) {
        arr = ar;
        int n = ar.size();
        tree = vector<int>(n*4, 0);
        fill(0, 0, n-1);
    }

    void fill(int ind, int l, int r) {
        if (l==r) {
            tree[ind] = arr[l];
            return;
        }
        int mid = (r+l)/2;
        fill(2*ind+1, l, mid);
        fill(2*ind+2, mid+1, r);
        tree[ind] = max(tree[2*ind+1], tree[2*ind+2]);
    }

    int query(int ind, int leftIndex, int rightIndex, int leftBound, int rightBound) {
        if (rightBound<leftIndex || leftBound>rightIndex) {
            return INT_MIN;
        } else if (leftIndex==rightIndex) {
            return tree[ind];
        } else {
            int mid = (leftIndex + rightIndex)/2;
            int leftMax = query(2*ind+1, leftIndex, mid, leftBound, rightBound);
            int rightMax = query(2*ind+2, mid+1, rightIndex, leftBound, rightBound);
            return max(leftMax, rightMax);
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        SegmentTree sgTree;
        int n = nums.size();
        sgTree.begin(nums);
        vector<int> ans;
        for (int i=k-1; i<n; i++) {
            ans.push_back(sgTree.query(0, 0, n-1, i-k+1, i));
        }
        return ans;
        // multiset<int> pq;
        // int n = nums.size();
        // vector<int> ans;
        // if (n<k) return ans;

        // for(int i=0; i<n; i++) {
        //     pq.insert(nums[i]);
        //     if (i<k-1) {
        //         continue;
        //     } else {
        //         auto it = pq.end();
        //         it--;
        //         ans.push_back(*it);
        //         pq.erase(pq.find(nums[i-k+1]));
        //     }
        // }

        // return ans;
    }
};
