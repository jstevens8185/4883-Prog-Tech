// leetcode 66 - Plus One
//You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. 
//The large integer does not contain any leading 0's.
//Increment the large integer by one and return the resulting array of digits.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size()-1;

        digits[index] += 1;

        while(digits[index] == 10){
            digits[index] = 0;
            if(index == 0){
                digits.insert(digits.begin(), 1, 1);
                return digits;
            }
            digits[index-1] += 1;
            index--;
        }
        return digits;
        }
};