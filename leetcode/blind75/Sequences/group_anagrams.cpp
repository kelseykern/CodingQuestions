    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;

        for(auto unsorted_word : strs){
            string sorted_word = unsorted_word;
            sort(sorted_word.begin(),sorted_word.end());
            m[sorted_word].push_back(unsorted_word);
          }
        
        for(auto it = m.begin(); it!=m.end();it++){
            ans.push_back(it->second);
        }
      return ans;
    }

