class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> smap(26, 0);
        vector<int> tmap(26, 0);
        for (auto c: s) {
            smap[c - 'a']++;
        }
        for (auto c: t) {
            tmap[c - 'a']++;
        }
        for(int i=0; i<26; i++) {
            if (smap[i]!=tmap[i]) return false;
        }
        return true;
    }
};
