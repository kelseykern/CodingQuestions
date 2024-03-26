    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<std::vector<int>> result {};
        sort(intervals.begin(), intervals.end(), 
	  [](const std::vector<int>& a, const std::vector<int>& b) 
        {
            return a[0] < b[0];
        }
            );


        int start = 0;
        while(start<intervals.size()){
            int end = start;
            int highest = intervals[end][1];
            while(end+1 < intervals.size() &&
                  highest >= intervals[end+1][0] 
                  ) 
                  {
                     highest = max(highest,intervals[end+1][1] );
                     end++;
                  }

            result.push_back({intervals[start][0],highest});
            start=end+1;
        }
        return result;
    }

