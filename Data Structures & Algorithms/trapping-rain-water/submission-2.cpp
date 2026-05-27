class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prevMaxes(height.size()); 
        vector<int> futureMaxes(height.size()); 
        int leftMax = 0;
        int rightMax = 0;  
        for(int i = 0; i < height.size(); i++)
        {
            if(height[i] > leftMax)
            {
                prevMaxes[i] = height[i]; 
                leftMax = height[i]; 
            }
            else
            {
                prevMaxes[i] = leftMax; 
            }
            int currIdx = height.size() - 1 - i;
            if(height[currIdx] > rightMax)
            {
                futureMaxes[currIdx] = height[currIdx]; 
                rightMax = height[currIdx];
            }
            else
            {
                futureMaxes[currIdx] = rightMax; 
            }
        }
        int total_area = 0; 
        for(int i = 0; i < height.size(); i++)
        {
            cout << i << " " << prevMaxes[i] << " " << futureMaxes[i] << endl; 
            total_area += (min(prevMaxes[i], futureMaxes[i]) - height[i]); 
        }
        return total_area; 
    }
};
