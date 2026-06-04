class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> min_edges(heights.size(), vector<int> (heights[0].size(), INT_MAX)); 
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; 
        min_edges[0][0] = 0; 
        pq.push({0, 0, 0}); 
        //row, col, edge weight
        while(!pq.empty())
        {
            vector<int> curr = pq.top(); 
            pq.pop(); 
            int curr_diff = curr[2]; 
            //so we basically check each surrounding node and see if there's a new maximum edge weight
            //check all four sides, we look at max difference in edge weight, either current state if its greater
            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};  
            for(int i = 0; i < 4; i++)
            {
                if((curr[0] + dr[i] >= 0 && curr[0] + dr[i] < heights.size()) && (curr[1] + dc[i] >= 0 && curr[1] + dc[i] < heights[0].size()))
                {
                    int diff = abs(heights[curr[0] + dr[i]][curr[1] + dc[i]] - heights[curr[0]][curr[1]]); 
                    diff = max(diff, curr_diff); 
                    if(diff < min_edges[curr[0] + dr[i]][curr[1] + dc[i]])
                    {
                        min_edges[curr[0] + dr[i]][curr[1] + dc[i]] = diff; 
                        pq.push({curr[0] + dr[i], curr[1] + dc[i], diff}); 
                    }
                }
            }
        }
        return min_edges[heights.size() - 1][heights[0].size() - 1]; 

    }
};