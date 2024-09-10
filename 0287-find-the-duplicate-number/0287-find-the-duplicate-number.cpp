class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        for (auto i : mp) {
            if (i.second > 1)
                return i.first;
        }
        return -1; // No duplicate found
    }
};