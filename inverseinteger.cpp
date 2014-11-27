class Solution {
public:
    int reverse(int x) {
        bool flag = false;
         if( x < 0) {
             flag = true;
             x = -x;
         }
         int res = 0;
         while(x != 0){
             if(res > (INT_MAX - x%10)/10 ) return 0;
             res = res *10 + x%10;
             x /= 10;
         }
         if(flag) return -1*res;
         return res;
    }
};
