// leetcode 9 - Palindrome Number
// Given an integer x, return true if x is a palindrome and false otherwise.

class Solution {
public:
    bool isPalindrome(int x) {
        string number = to_string(x);
        
        for (int i = 0, j = number.length()-1; i < j; i++, j--){
            if(number[i] != number[j])
                return false;
        }
        return true;
    }
};