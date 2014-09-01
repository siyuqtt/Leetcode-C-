class Solution {
public:
   string getPermutation(int n, int k) {
        int total = 1;
        int no = 0;
        vector<int > sequence;
        for(int j = 1; j <= n; j++){
            total *= j;
            sequence.push_back(j);
        }
        int bucket = n;
        vector<int > position;
        int count = 0;
        while( 1 ){
            total /= bucket;
            count = 0;
            while(no < k){
                no += total;
                count++;
            }
            position.push_back(count - 1);
            no -= total;
            if( --bucket == 0) break;
            
        }
        string re = "";
        for(int i = 0;i < n; i++){
            re += sequence[position[i]]+'0';
            sequence.erase(sequence.begin() + position[i]);
            
        }
        return re;
        
    }
};
