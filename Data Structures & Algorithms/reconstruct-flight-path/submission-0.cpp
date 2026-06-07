class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph; 
        for(int i = 0; i < tickets.size(); i++)
        {
            vector<string> curr = tickets[i]; 
            graph[curr[0]].push_back(curr[1]); 
        }
        for(auto &[k,v]: graph)
        {
            sort(v.begin(), v.end()); 
        }
        vector<string> answer;
        //set<pair<string, string>> visited_edges; 
        dfs("JFK", graph, answer, tickets.size());  
        reverse(answer.begin(), answer.end()); 
        return answer; 
    }
    void dfs(string start, unordered_map<string, vector<string>>& graph, vector<string>& answer, int total_size)
    {
        cout << start << endl; 
        if(graph[start].size() == 0)
        {
            cout << "WE DID IT!" << endl;
            answer.push_back(start); 
            return; 
        }
        while(graph[start].size() > 0)
        {
            string curr = graph[start][0];
            graph[start].erase(graph[start].begin() + 0);
            dfs(curr, graph, answer, total_size);
        }
        answer.push_back(start); 
        
    }
};
