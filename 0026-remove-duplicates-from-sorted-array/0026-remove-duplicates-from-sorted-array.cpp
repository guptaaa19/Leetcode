class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(nums[0]);
        int j = 0;
        for (int i = 1; i < n; i++) {
            if (arr.back() != nums[i]) {
                arr.push_back(nums[i]);
                j++;
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            nums[i] = arr[i];
        }

        return arr.size();
    }
};