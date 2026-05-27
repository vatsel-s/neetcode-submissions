class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0; 
        string output = ""; 
        while(true)
        {
            char curr = strs[0][index];
            bool canContinue = true;  
            for(int i = 0; i < strs.size(); i++)
            {
                if(index >= strs[i].size() || strs[i][index] != curr)
                {
                    canContinue = false; 
                }
            }
            if(canContinue == false)
            {
                break; 
            }
            output += strs[0][index]; 
            index++;
        }
        return output; 
    }
};