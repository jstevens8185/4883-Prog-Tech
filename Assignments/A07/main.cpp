// LeetCode 215: Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       
        priority_queue<int> pQueue;
        for (int i = 0; i < nums.size(); i++) {
            pQueue.push(nums[i]);
        }

        for (int i =0; i < k-1; i++){
            pQueue.pop();
        }

        return pQueue.top();
    }
};