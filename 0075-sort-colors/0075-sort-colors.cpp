class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }
        vector<int> res;
        for (auto i : mp) {
            for (int count = 0; count < i.second; count++) {
                res.push_back(i.first);
            }
        }
        nums = res;
    }
};