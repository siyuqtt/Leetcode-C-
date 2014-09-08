class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        unordered_map<string, int> letters;
        string sub;
        string out = "";
        if(strs.size() == 1 ) return strs[0];
        if(strs.size() == 0 ) return out;
        //create sub set
        for(int i = 0; i < strs[0].length(); i++){
            sub = strs[0].substr(0,i+1);
            letters[sub] = sub.length();
        }
        // filter sub set
        for( int i = 1; i < strs.size(); i++){
            for(auto it = letters.begin() ; it != letters.end(); ){
                int pos = strs[i].find(it->first,0);
                if(pos != 0 ){
                    it = letters.erase(it);
                }else it++;
            }
        }
        for( auto it = letters.begin(); it != letters.end(); it++){
            out = out.length() > it->second ? out : it->first;
        }
        return out;
    }
};
