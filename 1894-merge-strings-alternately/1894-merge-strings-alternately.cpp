class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string res = "";
        for(int i =0;i<max(n,m);i++){
            if(i<n)
            res.push_back(word1[i]);
            if(i<m)
            res.push_back(word2[i]);
        }
        return res;
    }
};