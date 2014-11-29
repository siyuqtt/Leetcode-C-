class Solution {
public:
    struct R{
        int l;
        int r;
        R(int a,int b): l(a), r(b){}
    };
    int largestRectangleArea(vector<int> &height) {
        vector<R> range(int(height.size()), R(0, int(height.size())));
        int maxsize = 0;
        for(int i = 0 ;i < height.size(); i++){
            int left = i;
            if(i != 0 ){
                if(height[i] <= height[i-1]){
                    left = range[i-1].l;
                }
            }
            int j;
            for(j = left ;j >=0 ;j--){
                if(height[j] < height[i]){ j++; break;}
            }
            range[i].l = max(j,0);
            //maxsize = max(maxsize,height[i] *(i - range[i].l +1));
        }
        for(int i = height.size() -1; i>= 0 ;i--){
            int right =  i;
            if(i != height.size() -1){
                if(height[i] <= height[i+1]) right = range[i+1].r;
            }
            int j;
            for(j = right; j <height.size();j++){
                if(height[j] < height[i]){j--; break;}
            }
            range[i].r = min(j, int(height.size()-1));
            maxsize = max(maxsize,height[i] *(range[i].r - range[i].l +1));
        }
        return maxsize;
    }
};
