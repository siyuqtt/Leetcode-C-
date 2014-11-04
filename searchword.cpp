bool find(vector< vector<char>> &board, string word, int x, int y, vector< vector<int>> &Mark, int p ){
        if(p == word.size() -1) return true;
        int m = board.size();
        int n = board[0].size();
        Mark[x][y] = 1;
        // right
        if(x < m -1 && word[p+1] == board[x+1][y] && Mark[x+1][y] != 1){
            if(find(board,word,x+1,y,Mark,p+1)) return true;
        }
        //left
        if(x > 0 && word[p+1] == board[x-1][y] && Mark[x - 1][y] != 1){
            if(find(board,word,x-1,y,Mark,p+1)) return true;
        }
        // up
        if(y < n -1 && word[p+1] == board[x][y +1] && Mark[x][y+1] != 1){
            if(find(board,word,x,y+1,Mark,p+1)) return true;
        }
        // down
        if(y > 0 && word[p+1] == board[x][y-1] && Mark[x][y-1] != 1){
            if(find(board,word,x,y-1,Mark,p+1)) return true;
        }
        Mark[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        
        if(word.length() == 0) return true;
        if(board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<int> v(n,0);
        vector<vector<int>> Mark(m,v);
        for(int i = 0 ;i < m ;i++){
            for(int j = 0; j< n;j++){
                if(board[i][j] == word[0] ){
                    if(find(board, word, i, j,Mark, 0)) return true;
                }
            }
        }
        return false;
    }
