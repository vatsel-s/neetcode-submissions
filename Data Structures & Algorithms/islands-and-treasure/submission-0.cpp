class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0)
                {
                    search(i, j, grid); 
                }
            }
        }
    }

    void search(int row, int col, vector<vector<int>>& grid)
    {
        cout << row << " " << col << "\n" << endl; 
        vector<std::pair<int, int>> queue; 
        unordered_set<int> visited; 
        visited.insert(grid[0].size() * row + col); 
        pair<int, int> val(row, col); 
        queue.push_back(val); 
        int count = 1; 
        while(queue.size() != 0)
        {
            vector<pair<int, int>> new_queue; 
            for(int i = 0; i < queue.size(); i++)
            {
                pair<int, int> current = queue[i]; 
                int curr_row = current.first; 
                int curr_col = current.second; 
                cout << curr_row << " " << curr_col << " " << count << endl; 
                if((curr_row + 1 < grid.size() && grid[curr_row + 1][curr_col] > 0) && visited.find((curr_row + 1) * grid[0].size() + curr_col) == visited.end())
                {
                    if(count < grid[curr_row + 1][curr_col])
                    {
                        grid[curr_row + 1][curr_col] = count; 
                        pair<int, int> val(curr_row + 1, curr_col); 
                        new_queue.push_back(val); 
                        visited.insert((curr_row + 1) * grid[0].size() + curr_col); 
                    }
                }
                if((curr_row - 1 >= 0 && grid[curr_row -1][curr_col] > 0) && visited.find((curr_row - 1) * grid[0].size() + curr_col) == visited.end())
                {
                    if(count < grid[curr_row - 1][curr_col])
                    {
                        grid[curr_row - 1][curr_col] = count; 
                        pair<int, int> val(curr_row - 1, curr_col); 
                        new_queue.push_back(val); 
                        visited.insert((curr_row - 1)* grid[0].size() + curr_col); 
                    }
                }
                if((curr_col + 1 < grid[0].size() && grid[curr_row][curr_col + 1] > 0) && visited.find((curr_row) * grid[0].size() + curr_col + 1) == visited.end())
                {
                    if(count < grid[curr_row][curr_col + 1])
                    {
                        grid[curr_row][curr_col + 1] = count; 
                        pair<int, int> val(curr_row, curr_col + 1); 
                        new_queue.push_back(val); 
                        visited.insert(curr_row * grid[0].size() + curr_col + 1); 
                    }
                }
                if((curr_col - 1 >= 0 && grid[curr_row][curr_col - 1] > 0) && visited.find((curr_row) * grid[0].size() + curr_col - 1) == visited.end())
                {
                    if(count < grid[curr_row][curr_col - 1])
                    {
                        grid[curr_row][curr_col - 1] = count; 
                        pair<int, int> val(curr_row, curr_col - 1); 
                        new_queue.push_back(val); 
                        visited.insert(curr_row * grid[0].size() + curr_col - 1); 
                    }
                }
            }
            count++; 
            queue = new_queue; 
        }        
    }
};
