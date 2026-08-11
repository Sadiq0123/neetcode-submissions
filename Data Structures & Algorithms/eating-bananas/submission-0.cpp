class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int pilesMax = 0;
        for(auto i: piles) {
            pilesMax = max(pilesMax, i);
        }
        if (h == n) return pilesMax;

        int l = 1, r = pilesMax;
        while(l<r) {
            int mid = (l+r)/2;
            int currentHours = hoursToComplete(piles, mid);
            if (currentHours>h) {
                l = mid+1;
            } else if (currentHours<=h) {
                r = mid;
            }
        }

        return r;

    }

    int hoursToComplete(vector<int>arr, int k) {
        int ans = 0;
        for(auto i: arr) {
            ans += i/k;
            if (i%k) ans++;
        }
        return ans;
    }
};
