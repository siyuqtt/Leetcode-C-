class Solution {
    private:
        void rec( int pos, vector<int> &num, vector<vector<int> > &result){
            if(pos == num.size()){
                result.push_back(num);
                return;
            }
            for( int i = pos; i< num.size(); i++){
                swap(num[i], num[pos]);
                rec(pos+1, num, result);
                swap( num[i], num[pos]);
            }
        }
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        rec(0,num,result);
        return result;
    }
};
