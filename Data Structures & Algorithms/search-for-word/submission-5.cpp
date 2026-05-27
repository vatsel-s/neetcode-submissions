class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                //condition to start searching
                if(board[i][j] == word[0])
                {
                    //basically doing iterative recursion
                    //or maybe actual recursion is a bit easier
                    unordered_set<int> visited; 
                    visited.insert(i * board[0].size() + j); 
                    bool val = findWord(board, visited, i, j, 1, word); 
                    cout << val << endl; 
                    if(val == true)
                    {
                        return true; 
                    }
                }
            }
        }
        return false; 
    }
    bool findWord(vector<vector<char>> board, unordered_set<int> visited, int row, int col, int index, string word)
    {
        cout << board[row][col] << " " << row << " " << col << endl; 
        if(index == word.size())
        {
            cout << "reached"; 
            return true; 
        }
        bool reached = false;
        if((row + 1 < board.size() && visited.find((row + 1) * board[0].size() + col) == visited.end()) && board[row + 1][col] == word[index])
        {
            visited.insert((row + 1)* board[0].size() + col); 
            reached = reached || findWord(board, visited, row + 1, col, index + 1, word);
            visited.erase((row + 1)* board[0].size() + col); 
        }
        if((row - 1 >= 0 && visited.find((row - 1) * board[0].size() + col) == visited.end()) && board[row - 1][col] == word[index])
        {
            visited.insert((row - 1)* board[0].size() + col); 
            reached = reached || findWord(board, visited, row - 1, col, index + 1, word);
            visited.erase((row - 1)* board[0].size() + col); 
        }
        if((col + 1 < board[0].size() && visited.find(row * board[0].size() + col + 1) == visited.end()) && board[row][col + 1] == word[index])
        {
            visited.insert(row * board[0].size() + col + 1); 
            reached = reached || findWord(board, visited, row, col + 1, index + 1, word);
            visited.erase(row * board[0].size() + col + 1); 
        }
        if((col - 1 < board[0].size() && visited.find(row * board[0].size() + col - 1) == visited.end()) && board[row][col - 1] == word[index])
        {
            visited.insert(row * board[0].size() + col - 1); 
            reached = reached || findWord(board, visited, row, col - 1, index + 1, word);
            visited.erase(row * board[0].size() + col - 1); 
        }
        cout << "\n";
        return reached; 
    }
};
