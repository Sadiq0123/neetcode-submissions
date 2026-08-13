class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto& arr = mp[key];
        int n = arr.size();
        int l=0, r=n-1;
        // if (n==0 || arr[0].first>timestamp) return "";
        // return arr[n-1].second;
        string ans = "";

        while(l<=r) {
            // if (l==r) return arr[l].second;
            int mid = (l+r)/2;
            if (arr[mid].first<=timestamp) {
                ans = arr[mid].second;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return ans;
    }
};
