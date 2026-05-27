class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited, stops(deadends.begin(), deadends.end()); 
        queue<pair<string, int>> q;
        q.push(make_pair("0000", 0)); 
        visited.insert("0000"); 
        if(stops.find("0000") != stops.end())
        {
            return -1; 
        }
        while(!q.empty())
        {
            pair<string, int> curr_pair = q.front();
            q.pop();
            string curr = curr_pair.first; 
            //cout << curr << " " << curr_pair.second << endl; 
            for(int i = 0; i < 4; i++)
            {
                for(int j = 1; j >= -2; j -= 2)
                {
                    curr = curr_pair.first; 
                    int curr_char = curr[i] - '0';
                    curr_char = (10 + curr_char + j)%10; 
                    curr[i] = curr_char + '0';
                    //cout << curr << " " << curr_pair.second << endl; 
                    if(curr == target) 
                    {
                        return curr_pair.second + 1; 
                    }
                    if(!stops.count(curr) && !visited.count(curr))
                    {
                        visited.insert(curr); 
                        q.push(make_pair(curr, curr_pair.second + 1)); 
                    }
                }
            }
            
        }
        return -1; 
        
    }
};