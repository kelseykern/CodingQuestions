    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> instances;

        for(auto num : nums){
            if (instances.count(num) > 0){
                return true;
            }
            instances.insert(num);
        }
        return false;
    }

