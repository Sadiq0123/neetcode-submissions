class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> count;
        int ans = 0;
        int i=0, j=0;
        while(j<n) {
            if (count.find(s.at(j))!=count.end()) {
                do {
                    count.erase(s.at(i));
                    i++;
                } while((i<j) && (s.at(i-1)!=s.at(j)));
            }
            count.insert(s.at(j));
            j++;
            ans = std::max(ans, static_cast<int>(count.size()));
        }
        return ans;
    }
};
