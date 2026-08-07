class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> sortedArr;
        int n = position.size();
        for(int i=0; i<n; i++) {
            sortedArr.push_back(make_pair(position[i], speed[i]));
        }
        sort(sortedArr.begin(), sortedArr.end());

        vector<double> timeToReach(n, 0);
        for(int i=0; i<n; i++) {
            // bool isDivisible = (target-sortedArr[i].first)%sortedArr[i].second == 0;
            timeToReach[i] = (double)(target-sortedArr[i].first)/sortedArr[i].second;
            // if (!isDivisible) timeToReach[i]++;
        }

        double maxTime = 0;
        int fleets = 0;

        for (int i = n-1; i >= 0; i--) {
            if (timeToReach[i] > maxTime) {
                fleets++;
                maxTime = timeToReach[i];
            }
        }

        return fleets;

        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int i=n-1; i>=0; i--) {
        //     if (!pq.empty() && pq.top()>timeToReach[i]) {
        //         timeToReach[i] = pq.top();
        //     } else {
        //         pq.push(timeToReach[i]);
        //     }
        // }

        // for(int i=n-1; i>=0; i--) {
        //     int next = i+1;
        //     int actualTime = timeToReach[i];
        //     while(next<n) {
        //         if (timeToReach[next]>actualTime) {
        //             actualTime = max(actualTime, timeToReach[next]);
        //             // int timeToCoincide = (sortedArr[next].first - sortedArr[i].first)/(sortedArr[i].second - sortedArr[next].second);
        //             // actualTime = max(actualTime, timeToCoincide + timeToReach[next])
        //         }
        //         next++;
        //     }
        //     timeToReach[i] = actualTime;
        // }

        // set<int> differentTimes(timeToReach.begin(), timeToReach.end());
        // return differentTimes.size();

    }
};
