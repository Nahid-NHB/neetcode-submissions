class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(auto s:strs){
            string sorted_s=s;
            sort(sorted_s.begin(),sorted_s.end());
            mp[sorted_s].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &[fi,se]:mp){
            res.push_back(se);
        }

        return res;
    }
};
