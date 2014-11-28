class Solution {
public:
    void genpath(string s, int pos, vector< vector<int>> &out, vector<string> &path, string p){
        if(pos == -1){
            path.push_back(p.substr(0, p.length()-1));
            return;
        }
        for(auto it :out[pos]){
            genpath(s, it, out, path, s.substr(it+1, pos - it) + ' ' + p);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<int> v;
        vector< vector<int> > out(s.length(), v);
        for(int i = 0; i <s.length() ; i++){
            for(int j = 0 ;j <= i;j++){
                string sub = s.substr(j, i-j +1);
                if(dict.find(sub) != dict.end()){
                    out[i].push_back(j -1);
                }
            }
        }
        vector<string> path;
        string p = "";
        genpath(s, s.length() -1, out, path, p);
        return path;
    }
};
