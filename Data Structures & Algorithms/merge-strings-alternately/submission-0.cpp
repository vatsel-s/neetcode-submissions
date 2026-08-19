class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output; 
        for(int i = 0; i < min(word1.size(), word2.size()); i++)
        {
            output = output + word1[i] + word2[i]; 
        }
        for(int i = word2.size(); i < word1.size(); i++)
        {
            output += word1[i]; 
        }
        for(int i = word1.size(); i < word2.size(); i++)
        {
            output += word2[i]; 
        }
        return output; 
        
    }
};