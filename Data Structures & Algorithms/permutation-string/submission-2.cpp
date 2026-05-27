class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> string_map; 
        for(int i = 0; i < s1.size(); i++)
        {
            string_map[s1[i]]++;  
        }
        unordered_map<char, int> iterative_map; 
        for(int i = 0; i < s1.size(); i++)
        {
            iterative_map[s2[i]]++; 
        }
        for(int i = 0; i < s2.size() - s1.size() + 1; i++)
        {
            bool permutation = true; 
            for(const auto it: iterative_map)
            {
                cout << string_map[it.first] << " " << iterative_map[it.first] << endl; 
                if(string_map[it.first] != iterative_map[it.first])
                {
                    permutation = false; 
                    break; 
                }
            }
            if(permutation)
            {
                return true; 
            }
            iterative_map[s2[i+s1.size()]]++; 
            iterative_map[s2[i]]--; 
        }
        return false; 
    }
};
