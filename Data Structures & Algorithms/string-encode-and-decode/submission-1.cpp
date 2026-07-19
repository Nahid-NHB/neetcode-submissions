class Solution {
public:

    string encode(vector<string>& strs) {
        string res ="";
        for(auto &s:strs){
            res+=to_string(s.length())+"#"+s;
            
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>final;
        int n=s.length(); int i=0;
        while( i<n){
            int f_idx=s.find("#",i);
            int len=stoi(s.substr(i,f_idx-i));
            
            i = f_idx + 1;
            final.push_back(s.substr(i,len));
            i += len;
        }
        return final;
    }
};