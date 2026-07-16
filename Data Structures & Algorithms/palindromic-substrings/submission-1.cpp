class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        auto expandFromCenter = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            expandFromCenter(i, i);     // Odd-length palindromes
            expandFromCenter(i, i + 1); // Even-length palindromes
        }

        return count;
    }
};
