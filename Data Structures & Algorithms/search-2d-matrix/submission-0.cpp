class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int total_size = matrix.size() * matrix[0].size(); 
        return binarySearch(matrix, target, 0, total_size - 1); 
    }

    bool binarySearch(vector<vector<int>>& matrix, int target, int lower, int upper)
    {
        if(lower > upper)
        {
            return false; 
        }
        int median = (upper + lower)/2; 
        int row = median/matrix[0].size();  
        int column = median%matrix[0].size(); 
        
        if(matrix[row][column] == target)
        {
            return true; 
        }
        else if(matrix[row][column] > target) 
        {
            return binarySearch(matrix, target, lower, median -1); 
        }
        else 
        {
            return binarySearch(matrix, target, median + 1, upper); 
        }
    }

};
