class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freqMp;
        for (char c : s) {
            freqMp[c]++;
        }

        int res = 0;
        bool hasOddFreq = false;
        for (auto& entry : freqMp) {
            int freq = entry.second;
            if (freq % 2 == 0) {
                res += freq;
            } else {
                res += freq - 1;
                hasOddFreq = true;
            }
        }
        if (hasOddFreq) {
            return res + 1;
        }
        return res;
    }
};