class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
         unordered_set<int>seta(nums.begin(),nums.end());
         return nums.size()>seta.size();

    }
};