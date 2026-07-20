class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto str: strs) {
            string delimiter = format_delimiter(str.length());
            ans = delimiter + str + ans;
        }
        return ans;
    }

    string format_delimiter(int i) {
        string ans = to_string(i);
        if(ans.length()==1) ans = "00" + ans;
        else if(ans.length()==2) ans = "0" + ans;
        else if(ans.length()==0) ans = "000";
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.length()==0) return ans;

        while(s.length()>0) {
            string temp = s.substr(0, 3);
            int strlen = stoi(temp);
            ans.push_back(s.substr(3, strlen));
            if (s.length() == 3 + strlen) break;
            s = s.substr(3 + strlen);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
