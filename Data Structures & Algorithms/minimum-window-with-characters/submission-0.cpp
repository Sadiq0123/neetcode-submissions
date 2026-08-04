class Solution {
public:
    string minWindow(string s, string t) {
        int ans_length=s.size()+1;
        string ans = "";
        int n = s.size();
        if (s.size()<t.size()) return "";
        unordered_map<char, int> count1, count2;
        for( auto c: t) {
            count1[c]++;
        }

        int l=0, r=0;
        while(r<n) {
            count2[s.at(r)]++;
            r++;
            if (isValidSolution(count1, count2)) {
                while(l<r && count2[s.at(l)]>count1[s.at(l)]) {
                    count2[s.at(l)]--;
                    l++;
                }
                if (ans_length > r-l) {
                    ans_length = r-l;
                    ans = s.substr(l, r-l);
                }
            }
        }

        return ans;
    }

    bool isValidSolution(unordered_map<char, int> count1, unordered_map<char, int> count2) {
        for (auto item: count1) {
            if (count2[item.first] < item.second) return false;
        }
        return true;
    }
};
