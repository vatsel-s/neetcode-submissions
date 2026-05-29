class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> disjoint_set(edges.size() + 1, -1); 
        for(auto & edge:edges)
        {
            if(!setUnion(disjoint_set, edge[0], edge[1]))
            {
                return edge; 
            }
        }
        vector<int> nothing; 
        return nothing;

    }

    int findParent(vector<int>& our_set, int child)
    {
        int curr = child;  
        while(our_set[curr] >= 0)
        {
            curr = our_set[curr]; 
        }
        cout << " \n\n\n"; 
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


