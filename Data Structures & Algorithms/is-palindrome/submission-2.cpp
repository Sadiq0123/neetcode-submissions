class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        if (s.size()<2) return true;
        while(i<s.size()) {
            if (s.size()==0) return true;
            if ((s[i]>='a' && s[i]<='z') ||
            (s[i]>='A' && s[i]<='Z') ||
            (s[i]>='0' && s[i]<='9')) {
                i++;
            } else {
                s.erase(i, 1);
            }
        }

        i=0;
        int j=s.size()-1;
        while(i<j) {
            if (isEqual(s[i], s[j])) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isEqual(char c1, char c2) {
        if (c1==c2) return true;
        int c1offset=getOffset(c1), c2offset=getOffset(c2);

        if (c1offset == c2offset) return true;
        return false;
    }

    int getOffset(char c) {
        int ans;
        if ((c>='a')&&(c<='z')) ans = c-'a';
        if ((c>='A')&&(c<='Z')) ans = c-'A';
        if ((c>='0')&&(c<='9')) ans = c-'0'+26;
        return ans;
    }
};
