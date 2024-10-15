// Leetcode 11 - Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0;
        int j = height.size()-1;
        int left = height[i]; 
        int right = height[j];
        cout << "left: " << left << endl;
        cout << "right: " << right << endl;
        while(j != i){
             if((j-i) * min(left, right) > max)
                max = (j-i) * min(left, right);
        
            if(left<right)
            {
                i++;
                left = height[i];
            }
            else{
                j--;
                right = height[j];
            }
        }
        return max;
    }
};