class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     map<int,int>mp;
     for(auto e:nums){
        mp[e]++;
     }
     vector<pair<int, int>> v(mp.begin(), mp.end());
     sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
         return a.second > b.second;
     });
     
     vector<int> res;
     for(int i = 0; i < k; i++) res.push_back(v[i].first);
     return res;
    }
};