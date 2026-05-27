class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0; 
        int maxSum = -1000; 
        for(int i = 0; i < nums.size(); i++)
        {
            cout << curSum << " " << maxSum << endl; 
            if(curSum < 0 && curSum < nums[i])
            {
                curSum = nums[i];
            }
            else 
            {
                curSum+=nums[i];
            }
            if(curSum > maxSum)
            {
                maxSum = curSum; 
            }
        }
        return maxSum; 
    }
};
