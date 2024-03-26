    int maxSubArray(vector<int>& nums) {
      int currsum = 0;
      int best = 0;

      for(int i=0;i<nums.size();i++){
        currsum = currsum+nums[i];

        // if adding the next number creates                
        // a deficit, we start new count
        if(currsum < 0) currsum = 0;

        best = max(currsum,best);
      }

     return best;
     
    }

