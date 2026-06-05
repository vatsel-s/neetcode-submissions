class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> min_weights(n + 1, INT_MAX); 
        vector<vector<pair<int, int>>> graph(n + 1); 
        for(int i = 0; i < times.size(); i++)
        {
            vector<int> curr_edge = times[i]; 
            graph[curr_edge[0]].push_back({curr_edge[1], curr_edge[2]}); 
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        pq.push({k, 0}); 
        min_weights[k] = 0; 
        while(!pq.empty())
        {
            pair<int, int> curr = pq.top(); 
            int curr_node = curr.first; 
            int curr_weight = curr.second; 
            pq.pop(); 
            for(int i = 0; i < graph[curr_node].size(); i++)
            {
                if(graph[curr_node][i].second + min_weights[curr_node] < min_weights[graph[curr_node][i].first])
                {
                    min_weights[graph[curr_node][i].first] = graph[curr_node][i].second + min_weights[curr_node]; 
                    pq.push({graph[curr_node][i].first, min_weights[graph[curr_node][i].first]}); 
                }
            }
        }
        int max_val = 0; 
        for(int i = 1; i < min_weights.size(); i++)
        {
            if(min_weights[i] == INT_MAX)
            {
                return -1; 
            }
            max_val = max(min_weights[i], max_val); 
        }
        return max_val; 
    }
};
