 unordered_map<char,string> d2s;
    Solution(){
        d2s['0'] = " ";
        d2s['1'] = "";
        d2s['2'] = "abc";
        d2s['3'] = "def";
        d2s['4'] = "ghi";
        d2s['5'] = "jkl";
        d2s['6'] = "mno";
        d2s['7'] = "pqrs";
        d2s['8'] = "tuv";
        d2s['9'] = "wxyz";
    }
    void mapping(char num, vector<string> &result){
        vector<string> cur;
        for(int i = 0 ;i < result.size() ;i++){
            for(int j = 0; j < d2s[num].size(); j++){
                cur.push_back(result[i] + d2s[num][j]);
            }
        }
        result.swap(cur);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        result.push_back("");
        for(int i = 0 ; i < digits.size() ;i++){
           mapping(digits[i],result);
        }
        return result;
    }
