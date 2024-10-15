// LeetCode problem 451 - Sort Characters by frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters. 
// The frequency of a character is the number of times it appears in the string.
//
// Return the sorted string. If there are multiple answers, return any of them.


class Solution {
public:

    bool ArrayNotEmpty(int arr[], int size){
        for (int i = 0; i < size; i++) {
            if (arr[i] != 0) {
                return true;  // Found a non-zero element
            }
        }
        return false;  // No non-zero elements found
    }

    int FindLargest(int arr[], int size) {
        int max = 0;  // Initialize to the smallest possible integer value
        int index = 0;
        int i;
        for (i = 0; i < size; i++) {
                if (arr[i] > max) {
                    max = arr[i];  // Update max_value if current element is larger
                    index = i;
                }
        }
    //cout << "largest value is: " << max << "\n";
    //cout << "found at occurences[" << index <<"]\n";
    // Return the largest non-zero value found, or INT_MIN if no non-zero value exists
    return index;
}
    string frequencySort(string s) {
        if(s.length() == 0){
            return "";
        }
        string output = "";       
        int occurences[62];
        for(int i=0;i<62;i++){
            occurences[i]=0;
        }
        int letterVal;
        for(int i = 0; i< s.length();i++){
            letterVal = s[i];
            if (letterVal >= 'A' && letterVal <= 'Z') {
                letterVal -= 'A';  // 0-25 for 'A'-'Z'
            } else if (letterVal >= 'a' && letterVal <= 'z') {
                    letterVal = letterVal - 'a' + 26;  // 26-51 for 'a'-'z'
            } else if (letterVal >= '0' && letterVal <= '9') {
                 letterVal = letterVal - '0' + 52;  // 52-61 for '0'-'9'
            }
            occurences[letterVal]++;
        }
        
        int index=0;
        int outputCount = 0;
        string printChar;
        cout << "ArrayNotEmpty is returning " << ArrayNotEmpty(occurences, 62);
        while(ArrayNotEmpty(occurences, 62)){
            index = FindLargest(occurences, 62);
            cout << "index is: " << index << "\n";
            
            if (index >= 0 && index < 26) {
                printChar = 'A' + index;
            } else if (index >= 26 && index < 52) {
                printChar = 'a' + (index - 26);
            } else {
                printChar = '0' + (index - 52);
            }
            cout << "occurences[" << index <<"] is: " << occurences[index] << endl;
            while(occurences[index]> 0){

                output += printChar;
                occurences[index]--;
                outputCount++;
            }
        }

        return output;
    }
};