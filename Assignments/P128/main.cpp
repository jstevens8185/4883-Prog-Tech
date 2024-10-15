// LeetCode problem 128 - Longest Consecutive Sequence
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int largest = 1;
        int temp = 1;
        std::sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i]){
                if((nums[i-1]+1) == nums[i]){
                    temp++;
                    cout << "temp: " << temp << endl;

                }else{
                    if(temp > largest){
                        largest = temp;
                    }
                    temp = 1;   
                }
            }
            cout << "largest: " << largest << endl << endl;
        }
        if(temp > largest){ 
            largest = temp;
        }
        
        return largest;
    }
};