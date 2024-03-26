    vector<int> topKFrequent(vector<int>& nums, int k) {

      // make vector to hold the k amount of elements
      vector<int> most_frequent;
      
      // make a map to match key=element value=frequency
      map<int,int> elements_map;

      // make a map to match key=frequency value=element
      map<int,int> frequency_map;

      // add all element amounts to the map
      for(int i=0; i<nums.size(); i++){
         elements_map[nums[i]]++;
      }

      // add them to frequency map, so they are ordered by frequency
      for(int i=0; i<nums.size(); i++){
         frequency_map[nums[i]]++;
      }

      // put the top k elements from frequency_map into most_frequent;
      // by default, a Map in C++ is sorted in increasing order based on its key
      auto it=frequency_map.rbegin();
      for(int i=0; i<k && it!=frequency_map.rend(); i++){
          most_frequent.push_back(it->second);
          ++it;
      }

      return most_frequent;
    }

