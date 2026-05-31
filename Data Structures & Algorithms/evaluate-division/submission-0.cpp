class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>> > graph; 
        for(int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]].push_back({equations[i][1], values[i]}); 
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]}); 
        }
        vector<double> answers(queries.size()); 
        for(int i = 0; i < queries.size(); i++)
        {
            string begin = queries[i][0]; 
            string end = queries[i][1]; 
            bool found = false; 
            if(graph.find(begin) == graph.end() || graph.find(end) == graph.end())
            {
                answers[i] = -1; 
                continue; 
            }
            queue<pair<string, double>> q; 
            unordered_set<string> visited; 
            q.push({begin, 1}); 
            visited.insert(begin); 
            while(!q.empty())
            {
                pair<string, double> curr = q.front(); 
                q.pop();
                if(curr.first == end)
                {
                    answers[i] = curr.second; 
                    found = true; 
                    break; 
                }
                for(int j = 0; j < graph[curr.first].size(); j++)
                {
                    if(!visited.count(graph[curr.first][j].first))
                    {
                        visited.insert(graph[curr.first][j].first); 
                        q.push({graph[curr.first][j].first, curr.second * graph[curr.first][j].second});
                    }
                }
            }
            if(!found)
            {
                answers[i] = -1; 
            }
        }
        return answers; 
    }
};