class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, pair<string, int>> graph; 
        unordered_set<string> words; 
        for(int i = 0; i < wordList.size(); i++)
        {
            words.insert(wordList[i]); 
        }
        unordered_set<string> visited; 
        queue<pair<string, int>> q; 
        q.push({beginWord, 1}); 
        while(!q.empty())
        {
            pair<string, int> curr = q.front();
            q.pop(); 
            string curr_string = curr.first;
            visited.insert(curr_string);  
            if(curr_string == endWord)
            {
                return curr.second; 
            }
            for(int a = 0; a < beginWord.size(); a++)
            {
                string curr_word = curr_string; 
                for(int i = 0; i < 26; i++)
                {
                    curr_word[a] = 'a' + i;
                    if(curr_word != curr_string && words.count(curr_word) && visited.find(curr_word) == visited.end())
                    {
                        q.push({curr_word, curr.second + 1});
                    }
                } 
            }
        }
        return 0; 
         
        
    }
};
