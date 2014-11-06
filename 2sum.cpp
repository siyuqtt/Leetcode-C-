class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        if(numbers.size() < 2) return result;
        unordered_map<int, int> dic;// number idx
        for(int i = 0; i<numbers.size(); i++) dic[numbers[i]] = i + 1;
        for(int i = 0 ; i < numbers.size(); i++){
            int comple = target - numbers[i];
            auto vit = dic.find(comple);
            if(vit != dic.end()){
                int idx = vit->second;
                if(idx > i+1){
                    result.push_back(i+1);
                    result.push_back(idx);
                    return result;
                }
                if(idx < i+1){
                    result.push_back(idx);
                    result.push_back(i+1);
                    return result;
                }
            }
           
        }
        return result;
    }
};
