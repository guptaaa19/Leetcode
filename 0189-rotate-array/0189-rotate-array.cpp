class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;   // if k is greater than the size of nums
        std::rotate(nums.begin(), nums.begin()+(n-k), nums.end());
    }
};
