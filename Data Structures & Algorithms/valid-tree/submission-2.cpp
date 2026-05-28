class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
        {
            return false; 
        } 
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            vector<int> curr = edges[i]; 
            graph[curr[0]].push_back(curr[1]); 
            graph[curr[1]].push_back(curr[0]); 
        }
        cout << "yippee" << endl; 
        unordered_set<int> visited; 
        queue<pair<int, int>> q; 
        q.push({0, -1});
        visited.insert(0); 
        while(q.empty() == false)
        {
            pair<int, int> curr_pair = q.front();
            int curr = curr_pair.first;  
            q.pop(); 
            cout << curr_pair.first << " " << curr_pair.second << endl; 
            for(int i = 0; i < graph[curr].size(); i++)
            {
                if(graph[curr][i] != curr_pair.second)
                {
                    if(visited.find(graph[curr][i]) != visited.end())
                    {
                        return false; 
                    }
                    q.push({graph[curr][i], curr});
                    visited.insert(graph[curr][i]); 
                }
            }
        }
        if(visited.size() == n)
        {
            return true; 
        }
        return false; 
    }
};
