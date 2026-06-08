class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; 
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {
                int manhattan_distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
                pq.push({manhattan_distance, i, j}); 
            }
        }
        int count = 0; 
        vector<int> disjoint_set(points.size(), -1); 
        int total_dist = 0; 
        while(!pq.empty())
        {
            vector<int> curr = pq.top();
            //cout << " " << curr[1] << " " << curr[2] << " " << curr[0] << endl;  
            pq.pop();
            if(set_union(curr[1], curr[2], disjoint_set)) 
            {
                //cout << "ADDED" << endl; 
                total_dist += curr[0]; 
            }
        }
        return total_dist; 
    }
    bool set_union(int ind1, int ind2, vector<int>& disjoint_set)
    {
        int find1 = find(ind1, disjoint_set); 
        int find2 = find(ind2, disjoint_set); 
        //cout << "find1 " << find1 << " find2 " << find2 << endl; 
        if(find1 == find2)
        {
            return false; 
        }
        else
        {
            //find1 has more nodes
            if(abs(find1) > abs(find2))
            {
                int val = disjoint_set[find2];
                disjoint_set[find2] = find1; 
                disjoint_set[find1] += val; 
            }
            else
            {
                int val = disjoint_set[find1];
                disjoint_set[find1] = find2; 
                disjoint_set[find2] += val;
            }
            return true; 
        }
    }
    int find(int curr, vector<int>& disjoint_set)
    {
        //we need to get the parent
        int root = curr; 
        while(disjoint_set[root] >= 0)
        {
            root = disjoint_set[root]; 
        }

        while(disjoint_set[curr] >= 0)
        {
            int temp = disjoint_set[curr]; 
            disjoint_set[curr] = root; 
            curr = temp; 
        }
        
        return root;
    }
};
