class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int maxnum = 0;
        for(int i = 0 ; i < n ;i++){
            maxnum = max(maxnum,A[i]);
        }
        vector<int > B(maxnum+1,-1);
        for(int i = 0 ;i < n; i++){
            if(A[i] > 0){
                
                B[A[i]] = 1;
            }
        }
        for(int i = 1 ; i < B.size() ;i++){
            if(B[i] != 1){
                
                return i;
            }
        }
        return maxnum+1;
    }
};
