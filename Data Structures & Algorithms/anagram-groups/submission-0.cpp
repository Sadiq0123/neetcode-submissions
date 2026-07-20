class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(auto s: strs) {
            string temp = s; 
            sort(temp.begin(), temp.end());
            hash[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it: hash) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
