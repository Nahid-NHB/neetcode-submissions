class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto s: strs){
            res += to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int found = s.find('#', i);
            int len = stoi(s.substr(i, found - i));
            res.push_back(s.substr(found + 1, len));
            i = found + 1 + len;
        }
        return res;
    }
};