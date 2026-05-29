class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int num_components = 0; 
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]); 
            graph[edges[i][1]].push_back(edges[i][0]); 
        } 
        unordered_set<int> visited; 
        for(int i = 0; i < n; i++)
        {
            if(visited.find(i) == visited.end())
            {
                num_components+=1; 
                queue<int> q; 
                q.push(i); 
                visited.insert(i); 
                while(!q.empty())
                {
                    int curr = q.front(); 
                    q.pop(); 
                    for(int j = 0; j < graph[curr].size(); j++)
                    {
                        if(visited.find(graph[curr][j]) == visited.end())
                        {
                            q.push(graph[curr][j]); 
                            visited.insert(graph[curr][j]); 
                        }
                    }
                }
            }
        }
        return num_components; 
    }
};
