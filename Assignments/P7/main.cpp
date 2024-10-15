// Leetcode 7 - Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

class Solution {
    #include <algorithm>
public:
    int reverse(int x) {
        string result;
        bool isNegative = false;
        if(x == INT_MIN){
            return 0;
        }
        if(x<0){
            isNegative = true;
            x *= -1;
            
        }
        if(isNegative){
            result = "-";
        }

        string strX = to_string(x);
        string reversed(strX.rbegin(), strX.rend());
        result += reversed;
        try{
            stoi(result);
        }catch(exception e){
            return 0;
        }
        
        return stoi(result);
    }
};