class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> maxes(grid.size(), vector<int>(grid[0].size(), INT_MAX)); 
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0}); 
        maxes[0][0] = grid[0][0]; 
        while(!pq.empty())
        {
            vector<int> curr = pq.top(); 
            pq.pop(); 
            int curr_max = curr[0]; 
            int row = curr[1]; 
            int col = curr[2]; 
            
            if(row + 1 < grid.size() && max(grid[row + 1][col], curr_max) < maxes[row + 1][col])
            {
                maxes[row + 1][col] = max(grid[row + 1][col], curr_max); 
                pq.push({maxes[row + 1][col], row + 1, col}); 
            }
            if(row - 1 >= 0 && max(grid[row - 1][col], curr_max) < maxes[row - 1][col])
            {
                maxes[row - 1][col] = max(grid[row - 1][col], curr_max); 
                pq.push({maxes[row - 1][col], row - 1, col}); 
            }
            if(col + 1 < grid[0].size() && max(grid[row][col + 1], curr_max) < maxes[row][col + 1])
            {
                maxes[row][col + 1] = max(grid[row][col + 1], curr_max); 
                pq.push({maxes[row][col + 1], row, col + 1}); 
            }
            if(col - 1 >= 0 && max(grid[row][col - 1], curr_max) < maxes[row][col - 1])
            {
                maxes[row][col - 1] = max(grid[row][col - 1], curr_max); 
                pq.push({maxes[row][col - 1], row, col - 1});
            }
        }
        return maxes[grid.size() - 1][grid[0].size() - 1]; 
    }
};
