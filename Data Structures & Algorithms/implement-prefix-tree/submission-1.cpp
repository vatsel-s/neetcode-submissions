class TreeNode 
{
    public: 
    TreeNode(char letter, bool end)
    {
        val = letter; 
        end = wordEnd;
    } 
    char val; 
    unordered_map<char, TreeNode*> children; 
    bool wordEnd; 
};

class PrefixTree {
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TreeNode* curr; 
        if(startingLetters.find(word[0]) == startingLetters.end())
        {
            curr = new TreeNode(word[0], false);
            startingLetters[word[0]] = curr;  
        }
        else 
        {
            curr = startingLetters[word[0]]; 
        }
        for(int i = 1; i < word.size(); i++)
        {
            if(curr->children.find(word[i]) == curr->children.end())
            {
                TreeNode* temp = new TreeNode(word[i], false); 
                curr->children[word[i]] = temp; 
                curr = temp; 
            }   
            else 
            {
                curr = curr->children[word[i]]; 
            }
            if(i == word.size() -1)
            {
                curr->wordEnd = true; 
            }
        }
    }
    
    bool search(string word) {
        if(startingLetters.find(word[0]) == startingLetters.end())
        {
            return false; 
        }
        if(word.size() == 1)
        {
            return true; 
        }
        TreeNode* start = startingLetters[word[0]]; 
        for(int i = 1; i < word.size(); i++)
        {
            if(start->children.find(word[i]) == start->children.end())
            {
                return false; 
            }
            else 
            {
                start = start->children[word[i]]; 
            }
        }
        if(start->wordEnd == false)
        {
            return false; 
        }
        return true; 
    }
    
    bool startsWith(string prefix) {
        if(startingLetters.find(prefix[0]) == startingLetters.end())
        {
            return false; 
        }
        TreeNode* start = startingLetters[prefix[0]]; 
        for(int i = 1; i < prefix.size(); i++)
        {
            if(start->children.find(prefix[i]) == start->children.end())
            {
                return false; 
            }
            else 
            {
                start = start->children[prefix[i]]; 
            }
        }
        return true; 
    }
private: 
    unordered_map<char, TreeNode*> startingLetters; 
};
