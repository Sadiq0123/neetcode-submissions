class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n2<n1) return false;
        vector<int> count1(26, 0), count2(26, 0);
        for(auto c: s1) {
            count1[c-'a']++;
        }
        int i=0;
        while(i<n2) {
            count2[s2.at(i)-'a']++;
            if (i>=(n1-1)) {
                if (isEqual(count1, count2)) return true;
                count2[s2.at(i-n1+1)-'a']--;
            }

            i++;
        }
        return false;
    }

    bool isEqual(vector<int> v1, vector<int> v2) {
        if (v1.size()!=v2.size()) return false;
        for(int i=0; i<v1.size(); i++) {
            if (v1[i]!=v2[i]) return false;
        }
        return true;
    }
};
