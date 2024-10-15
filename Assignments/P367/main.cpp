// leetcode 367 - Valid Perfect Square

//Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is 
//  the product of some integer with itself.
// You must not use any built-in library function, such as sqrt.

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0){
            return false;
        }
        if (num == 1){
            return true;
        }
        for (long long i = 1; i <= num/2; i++){
            if(i*i == num){
                return true;
            }
        }
        return false;
    }
};