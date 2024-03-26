    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> triplets;

       // sort array, we only need to return values not indexes
       sort(nums.begin(),nums.end());

       // search for the the solution to -a = b + c
       for(int i=0;i<nums.size()-2;i++){
           // skip duplicates
           if ( i > 0 && nums[i] == nums[i - 1]) continue;

           int target = nums[i] * -1;
           int start = i+1;
           int end = nums.size()-1;

           while(start < end){
               int sum = nums[start] + nums[end];

               if (target < sum){
                   while (start < end && nums[start] == nums[start + 1]) start++;
                   start++;
                   }
               else if(target > sum){
                   while (start < end && nums[end] == nums[end - 1]) end--;
                   end--;
                   }
               else{
                   triplets.push_back({target*-1,nums[start],nums[end]});

                   // skip duplicates
                   while (start < end && nums[start] == nums[start + 1]) start++;
                   while (start < end && nums[end] == nums[end - 1]) end--;
                   start++;
                   end--;
               }
           }
       }
        return triplets;
    }

