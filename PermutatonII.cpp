class Solution {
private:
    void iterperm(vector<vector<int > > &out, vector<int> &num, int po){
        if (po == num.size()){
            out.push_back(num);
            return;
        }
        set<int > used;
        for (int i = po; i < num.size(); i++){
            if (used.find(num[i]) == used.end()) used.insert(num[i]);
            else continue;
            swap(num[po], num[i]);
            iterperm(out, num, po+1);
            swap(num[po], num[i]);
        }
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > out;
        iterperm(out, num, 0);
        return out;
    }
};
