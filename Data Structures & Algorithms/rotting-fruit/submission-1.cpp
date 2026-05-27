class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> rotten; 
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {   
                if(grid[i][j] == 2)
                {
                    pair<int, int> val(i, j); 
                    rotten.push_back(val); 
                }
            }
        }
        

        int count = 0; 
        while(rotten.size() != 0)
        {
            vector<pair<int, int>> new_queue; 
            for(int i = 0; i < rotten.size(); i++)
            {
                int curr_row = rotten[i].first; 
                int curr_col = rotten[i].second;
                cout << curr_row << " " << curr_col << endl;  
                if(curr_row + 1 < grid.size() && grid[curr_row + 1][curr_col] == 1)
                {
                    grid[curr_row + 1][curr_col] = 2; 
                    pair<int, int> val(curr_row + 1, curr_col); 
                    new_queue.push_back(val); 
                }
                if(curr_row - 1 >= 0 && grid[curr_row - 1][curr_col] == 1)
                {
                    grid[curr_row - 1][curr_col] = 2;
                    pair<int, int> val(curr_row - 1, curr_col); 
                    new_queue.push_back(val);  
                }
                if(curr_col + 1 < grid[0].size() && grid[curr_row][curr_col + 1] == 1)
                {
                    grid[curr_row][curr_col + 1] = 2; 
                    pair<int, int> val(curr_row, curr_col + 1); 
                    new_queue.push_back(val); 
                }
                if(curr_col - 1 >= 0 && grid[curr_row][curr_col - 1] == 1)
                {
                    grid[curr_row][curr_col - 1] = 2; 
                    pair<int, int> val(curr_row, curr_col - 1); 
                    new_queue.push_back(val); 
                }
            }
            cout << "\n"; 
            if(new_queue.size() != 0)
            {
                count++;
            } 
            rotten = new_queue; 
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1; 
                }
            }
        }
        return count; 
    }

    

};
