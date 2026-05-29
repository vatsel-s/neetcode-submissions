class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //disjoint set, one to every current account
        //map of all emails -> current location in disjoint set
        //then we keep on adding emails, if they correspond to something that happens before
        vector<int> disjoint_set(accounts.size(), -1);
        unordered_map<string, int> email_map; 
        map<int, set<string>> answer; 
        for(int i = 0; i < accounts.size(); i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string email = accounts[i][j]; 
                if(email_map.find(email) != email_map.end())
                {
                    //now we have to set union with the one thats already there
                    int curr_parent = email_map[email]; 
                    setUnion(disjoint_set, i, curr_parent); 
                }
                else 
                {
                    //we just add it to the map
                    email_map[email] = i; 
                }
            }
        } 
        for (int i = 0; i < accounts.size(); i++) 
        {
            int rootParent = findParent(disjoint_set, i);
            for (int j = 1; j < accounts[i].size(); j++) {
                answer[rootParent].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> output; 
        for(auto it = answer.begin(); it != answer.end(); it++)
        {
            vector<string> output_line; 
            output_line.push_back(accounts[it->first][0]); 
            set<string> emails_added = it->second; 
            for(auto iter = emails_added.begin(); iter != emails_added.end(); iter++)
            {
                output_line.push_back(*iter); 
            }
            output.push_back(output_line); 
        }
        return output; 
    }
    int findParent(vector<int>& our_set, int child)
    {
        int curr = child;  
        while(our_set[curr] >= 0)
        {
            curr = our_set[curr]; 
        }

        int root = curr; 
        curr = child; 
        while(curr != root)
        {
            int temp_curr = our_set[curr]; 
            our_set[curr] = root; 
            curr = temp_curr; 
        }
        return root; 
    }
    
    bool setUnion(vector<int>& our_set, int child1, int child2)
    {
        int parent1 = findParent(our_set, child1); 
        int parent2 = findParent(our_set, child2); 
        
        if(parent1 == parent2)
        {
            return false; 
        }

        if(our_set[parent1] < our_set[parent2])
        {
            our_set[parent1]+=our_set[parent2]; 
            our_set[parent2] = parent1; 
        }
        else
        {
            our_set[parent2]+=our_set[parent1]; 
            our_set[parent1] = parent2; 
        }
        return true; 
    }   
};