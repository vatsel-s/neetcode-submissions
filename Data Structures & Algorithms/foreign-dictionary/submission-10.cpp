class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, set<char>> graph; 
        unordered_map<char, int> degree; 

        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                graph[words[i][j]] = {}; 
                degree[words[i][j]] = 0; 
            }
        }

        string word = words[0]; 
        for(int i = 1; i < words.size(); i++)
        {
            string curr_word = words[i]; 
            if(word.find(curr_word) != -1 && word.size() > curr_word.size())
            {
                return ""; 
            }
            for(int j = 0; j < min(curr_word.size(), word.size()); j++) 
            {
                if(curr_word[j] != word[j])
                {
                    if(graph[word[j]].count(curr_word[j]) == 0)
                    {
                        cout << i << " " << j << " " << word[j] << " " << curr_word[j] << " Ananya" << endl;  
                        degree[curr_word[j]] += 1; 
                        graph[word[j]].insert(curr_word[j]); 
                    }
                    break; 
                }
            }

            word = curr_word; 
        }
        cout << "REACHED!\n\n\n"; 

        queue<char> q; 
        for(auto [key, val]: degree)
        {
            cout << key << " " << val << endl; 
            if(val == 0)
            {
                q.push(key); 
            }
        }
        cout << "REACHED!" << endl; 
        unordered_set<char> visited;
        string output = "";  
        while(!q.empty())
        {
            char curr = q.front();
            cout << "current char " << curr << endl; 
            q.pop(); 
            if(visited.find(curr) != visited.end())
            {
                return ""; 
            }
            visited.insert(curr); 
            output = output + curr; 
            for(auto it: graph[curr])
            {
                cout << it << " " << degree[it] << " "; 
                degree[it]-=1; 
                if(degree[it] == 0)
                {
                    q.push(it);
                }
            }
            cout << endl; 
        }
        if(output.size() == graph.size())
        {
            return output; 
        }
        return ""; 



        
    }
};
