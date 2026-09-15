class Solution {
public:
    int maxArea(vector<int>& heights) {
        //so the max area instantly is the min of the two of them times the distance 
        //between the 2, how do we go along and do this in O(n) time
        //we can either move the left or right, going to the greater one
        //does this always converge?
        //for the worst in both options, do we move both pointers?
        int left = 0; 
        int right = heights.size() - 1; 
        int maxArea = min(heights[left], heights[right]) * (right - left); 
        while(left < right)
        {
            int area = min(heights[left], heights[right]) * (right - left);
            if(area > maxArea)
            {
                maxArea = area; 
            }
            /*if(heights[left] <= heights[right] && heights[left + 1] > heights[left])
            {
                left++; 
            }
            else if(heights[right] >= heights[left] && heights[right - 1] > heights[right])
            {
                right--; 
            }*/
            if(heights[right] > heights[left])
            {
                left++; 
            }
            else
            {
                right--; 
            }
        }
        return maxArea; 
    }
};
