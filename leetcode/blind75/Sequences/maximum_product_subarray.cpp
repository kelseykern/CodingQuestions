int maxProduct(vector<int>& nums) {
     if(nums.size() < 1) return 0;
     if(nums.size() == 1) return nums[0];

        int current_max=INT_MIN;
        int left_product=1;
        int right_product=1;

        for(int i=0;i<nums.size();i++)
        {
            // if either product results in 0, 
            // we will move up our subarray past them and restart
            if(left_product==0)left_product=1;
            if(right_product==0)right_product=1;

            // get left product
            left_product=left_product*nums[i];
            // get right product
            right_product=right_product*nums[nums.size()-i-1];

            current_max = max(current_max,max(left_product,right_product));
        }

        return current_max;
    }

