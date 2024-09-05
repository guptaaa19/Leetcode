class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int i=0;i<m;i++){
            sum+=rolls[i];
        }
        int x = (mean * (n+m))-sum;
        if(x < n || x > 6*n){
            return {};
        }
        vector<int>arr(n,x/n);
        int rem = x % n;

        for (int i = 0; i < rem; i++) {
            arr[i]++;
        }
        return arr;
    }
};