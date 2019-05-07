#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::vector<int> solution;
        if(nums.size() == 0){
            return solution;
        }
        std::map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++){
            int firstNumber = nums[i];
            cout << firstNumber << endl;
            if (hashMap.count(target-firstNumber) > 0){
                solution.push_back (i);
                solution.push_back (hashMap[target-firstNumber]);
                return solution;
            } else {
                hashMap[firstNumber] = i;
            }
            
        }
        return solution;
    }
};