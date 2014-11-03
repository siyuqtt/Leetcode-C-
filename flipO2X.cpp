typedef pair<int, int> P;
    void toFlip(vector< vector<char>> &board, vector<P>& nodes){
        auto it = nodes.begin();
        while(it != nodes.end()){
            board[it->first][it->second] = 'X';
            it++;
        }
    }
    void findCC(int x, int y, vector< vector<char>> &board, vector< vector<int>> &Mark){
        vector<P> stack;
        vector<P> nodes;
        P cur = make_pair(x,y);
        stack.push_back(cur);
        int n = board.size();
        int m = board[0].size();
        bool flip = true;
        while(!stack.empty()){
            cur = stack.back();
            stack.pop_back();
            int xx = cur.first;
            int yy = cur.second;
            if (Mark[xx][yy] == 1) continue;
            else {
                Mark[xx][yy] = 1;
                nodes.push_back(cur);
            }
            //right
            if(yy < m-1 ){
                if(board[xx][yy+1] == 'O'){
                    if(Mark[xx][yy +1] == 0){
                        stack.push_back(make_pair(xx, yy+1));
                    }
                }    
            }else flip = false;
            // left
            if(yy > 0 ){
                if(board[xx][yy-1] == 'O'){
                    if(Mark[xx][yy -1] == 0){
                        stack.push_back(make_pair(xx, yy-1));
                    }
                }    
            }else flip = false;
            //up
            if(xx < n-1 ){
                if(board[xx+1][yy] == 'O'){
                    if(Mark[xx+1][yy] == 0){
                        stack.push_back(make_pair(xx+1, yy));
                    }
                }
            }else flip = false;
            //down
            if(xx > 0 ){
                if(board[xx -1][yy] == 'O'){
                    if(Mark[xx -1][yy] == 0){
                        stack.push_back(make_pair(xx-1, yy));
                    }
                }
            }else flip = false;
        }
        if(flip) toFlip(board, nodes);
    }
    void solve(vector<vector<char>> &board) {
        if(board.empty())  return;
        int n = board.size();
        int m = board[0].size();
        vector<int> v(m,0);
        vector< vector<int> > Mark(n, v);
        for(int i = 0 ; i< n; i++){
            for(int j = 0 ; j < m; j++){
                if(board[i][j] != 'O') continue;
                else if(Mark[i][j] !=1 ) findCC(i,j,board,Mark);
            }
        }
    }
