class Solution {
public:
    string commonPrefix(string s1, string s2) {
        string res = "";
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) {
                res = res + s1[i];
            } else {
                break;
            }
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            prefix = commonPrefix(prefix, strs[i]);
            if (prefix == "") {
                return "";
            }
        }
        return prefix;
    }
};