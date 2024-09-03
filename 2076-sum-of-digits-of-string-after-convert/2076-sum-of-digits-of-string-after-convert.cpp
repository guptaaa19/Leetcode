class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char ch: s){
            num = num + to_string(ch-'a'+1);
        }
        while(k-- > 0){
            int digitSum = 0;
            for(char digit : num){
                digitSum = digitSum + (digit-'0');
            }
            num = to_string(digitSum);
        }
        return stoi(num);
    }
};