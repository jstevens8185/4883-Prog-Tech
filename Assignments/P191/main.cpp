// leetcode 191 - Number of 1 Bits

// Write a function that takes the binary representation of a positive integer and returns the number of 
// set bits it has (also known as the Hamming weight).

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0){
            if(1 & n){
                count++;
            }
            n = n>>1;
        }
        return count;
    }
};