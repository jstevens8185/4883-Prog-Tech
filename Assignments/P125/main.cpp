// Leetecode - 125. Valid Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty() || s == " "){
            return true;
        }
        string newString = "";
        for (int i = 0; i < s.size(); i++){
            if (isalnum(s[i])){
                newString.push_back(tolower(s[i]));
            }
        }

        int frontIndex = 0;
        int backIndex = newString.size()-1;

        while(frontIndex < backIndex){
            //cout << "frontIndex: " << newString[frontIndex] << " ";
            //cout << "backIndex: " << newString[backIndex] << endl << endl;
            if(newString[frontIndex] != newString[backIndex]){
                return false;
            }
            frontIndex++;
            backIndex--;
        }

        cout << newString;
        return true;
    }
};