class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<26; i++) {
            char currentChar = 'A' + i;
            int modified = 0;
            int l=0, r=0;
            while(r<n) {
                if (s.at(r)!=currentChar) {
                    modified++;
                    r++;
                    if (modified>k) {
                        while(l<=r && s.at(l)==currentChar) l++;
                        l++;
                        modified--;
                    }
                } else {
                    r++;
                }
                ans = max(ans, r-l);
            }
        }
        return ans;
    }
};
