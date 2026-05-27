class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxHeight = 0; 
        int index1 = 0; 
        int index2 = heights.size() - 1; 
        while(index2 > index1)
        {
            int height = (index2 - index1) * min(heights[index1], heights[index2]); 
            if(height > maxHeight)
            {
                maxHeight = height; 
            }
            if(heights[index1] < heights[index2])
            {
                index1++; 
            }
            else 
            {
                index2--; 
            }
        }
        return maxHeight;
    }
};
