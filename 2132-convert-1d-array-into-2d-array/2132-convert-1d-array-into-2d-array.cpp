class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int z = original.size();
        if(m*n != z ){
            return {};
        }
        vector<vector<int>>newArr(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                newArr[i][j] = original[i * n + j];
            }
        }
        return newArr;
    }
};