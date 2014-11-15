class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector< vector<int> > M(n+1, vector<int>(n+1, 0));
        M[1][n] = 1;
        M[1][n-1] = 1;
        M[1][n-2] = 2;
        
        for(int i = 2 ; i <= n ; i++){
            for(int j = max(n - 2*i,0); j <= n;j++){
                if(j < n -1 )M[i][j] = M[i-1][j+1] + M[i-1][j+2];
                if(j == n -1 ) M[i][j] = M[i-1][j+1];
                if(j == n ) M[i][j] = 1;
            }
        }
        
        return M[n][0];
    }
};
