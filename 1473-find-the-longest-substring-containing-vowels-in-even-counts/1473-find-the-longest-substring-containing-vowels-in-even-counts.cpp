class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXor = 0;
        int cMap[26] = {0};
        cMap['a' - 'a'] = 1;
        cMap['e' - 'a'] = 2;
        cMap['i' - 'a'] = 4;
        cMap['o' - 'a'] = 8;
        cMap['u' - 'a'] = 16;

        vector<int> mp(32, -1);
        int longss = 0;

        for (int i = 0; i < s.length(); i++) {
            prefixXor ^= cMap[s[i] - 'a'];
            if (mp[prefixXor] == -1 && prefixXor != 0)
                mp[prefixXor] = i;

            longss = max(longss, i - mp[prefixXor]);
        }
        return longss;
    }
};