// Leetcode Problem 67 - Add Binary

// Given two binary strings a and b, return their sum as a binary string.

class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        string result = "";
        if(a.size()>b.size()){
            while(a.size() != b.size()){
                b = "0" + b;
            }
        }if(b.size()>a.size()){
            while(a.size() != b.size()){
                a = "0" + a;
            }
        }
 
        for(int i = a.size(); i>=0; i--){
            //cout << "in for loop\n";
        
            if(a[i] == '0' && b[i] == '0'){
                if(!carry){
                    result = '0' + result;
                    carry = false;
                }else if(carry){
                    result = '1' + result;
                    carry = false;
                }
            }else if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')){
                if(!carry){
                    result = '1' + result;
                    carry = false;
                }else if(carry){
                    result = '0' + result;
                    carry = true;
                }
            }else if(a[i] == '1' && b[i] == '1'){
                if(!carry){
                    result = '0' + result;
                    carry = true;
                }else if(carry){
                    result = '1' + result;
                    carry = true;
                }
            }
        }
        if(carry){
            result = '1' + result;
        }

        return result;
    }
};