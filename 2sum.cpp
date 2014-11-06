class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        if(numbers.size() < 2) return result;
        for(int i = 0 ; i < numbers.size(); i++){
            int comple = target - numbers[i];
            auto vit = find(numbers.begin(), numbers.end(), comple);
            if(vit != numbers.end()){
                int idx = distance(numbers.begin(), vit) + 1;
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
