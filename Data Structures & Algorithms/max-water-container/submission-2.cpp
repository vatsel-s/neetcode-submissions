class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0; 
        int left = 0; 
        int right = heights.size() - 1; 
        while(left < right)
        {
            //cout << left << " " << 
            int leftVal = heights[left]; 
            int rightVal = heights[right]; 
            int currArea = (right - left) * min(leftVal, rightVal); 
            area = max(area, currArea); 
            if(heights[left] > heights[right])
            {
                right--; 
            }
            else 
            {
                left++; 
            }
            /*
            if(heights[left + 1] > heights[left])
            {
                left++; 
            }
            else if(heights[right] < heights[right - 1])
            {
                right--; 
            }
            else 
            {
                if(heights[left] > heights[right])
                {
                    right--; 
                }
                else 
                {
                    left++; 
                }
            }
            */
        }
        return area; 

    }
};
