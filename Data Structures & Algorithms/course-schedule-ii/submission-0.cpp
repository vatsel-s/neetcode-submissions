class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> courseList; 
        queue<int> q; 
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i); 
                courseList.push_back(i); 
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
                    courseList.push_back(graph[curr][i]); 
                }
            }
        }
        if(total >= numCourses)
        {
            return courseList; 
        }
        vector<int> return_vector; 
        return return_vector; 
    }
};
