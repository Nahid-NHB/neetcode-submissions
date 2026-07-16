class Solution {
public:
    int dfs(int i, string& s) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        
        int res = dfs(i + 1, s);
        if (i < s.size() - 1) {
            if (s[i] == '1' || 
               (s[i] == '2' && s[i + 1] < '7')) {
                res += dfs(i + 2, s);
            }
        }
        return res;
    }

    int numDecodings(string s) {
    // dfs(i, s) = number of ways to decode s[i:]
    // dfs(0, s) = total number of ways to decode the entire string from the start
    return dfs(0, s);
    }
};