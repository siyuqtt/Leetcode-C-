class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        if(n < 1) return result;
        vector<int > v(n, 0);
        result.resize(n,v);
        int cur = 1;
        int x = 0, y = 0;
        int direc = 0; 
        while(cur != n*n + 1){
            if(direc%4 == 0 ){
                while(y < n) {
                    if(result[x][y] == 0) result[x][y++] = cur++;
                    else break;
                }
                direc++;
                y--;x++;
                continue;
            }
            if(direc%4 == 1){
                while(x < n){
                    if(result[x][y] == 0) result[x++][y] = cur++;
                    else break;
                }
                direc++;
                x--;y--;
                continue;
            }
            if(direc%4 == 2){
                while(y >= 0){
                    if(result[x][y] == 0) result[x][y--] = cur++;
                    else break;
                }
                direc++;
                y++;x--;
                continue;
            }
            if(direc%4 == 3){
                while(x >= 0){
                    if(result[x][y] == 0) result[x--][y] = cur++;
                    else break;
                }
                direc++;
                x++;y++;
            }
            
        }
        return result;
    }
};
