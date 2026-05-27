class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //cycle detection
        //so topological sort
        //we have to create the graph, nodes from one course to another
        //int to int =, adjacency list, we have each one with the edges it leads to
        vector<vector<int>> graph(numCourses); 
        vector<int> indegree(numCourses, 0); 
        vector<int> outdegree(numCourses, 0); 
        for(int i = 0; i < prerequisites.size(); i++)
        {
            vector<int> curr = prerequisites[i]; 
            graph[curr[1]].push_back(curr[0]); 
            indegree[curr[0]]++; 
            outdegree[curr[1]]++; 
        }
        //find the source
        queue<int> q; 
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i); 
            }
        }
        //now we have to iterate
        int total = 0; 
        while(q.empty() == false)
        {
            int curr = q.front(); 
            q.pop(); 
            total += 1; 
            for(int i = 0; i < graph[curr].size(); i++)
            {
                indegree[graph[curr][i]]-=1; 
                if(indegree[graph[curr][i]] == 0)
                {
                    q.push(graph[curr][i]); 
                }
            }
        }
        if(total >= numCourses)
        {
            return true; 
        }
        return false; 
        
        
    }
};
