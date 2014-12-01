class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        const char* star = nullptr;
        const char * ss;
        while(*s){
            if(*p == '?' || *p ==*s) {p++;s++;continue;}
            if(*p == '*'){
                star = p++;
                ss = s;
                continue;
            }
            if(star){
                p = star +1;
                s = ++ss;
                continue;
            }
            return false;
        }
        while(*p){
            if(*p == '*' ) p++;
            else return false;
        }
        return true;
        
    }
};
