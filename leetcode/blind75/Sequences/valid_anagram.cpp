    bool isAnagram(string s, string t) {

       if(s.size() != t.size()) return false;

        // create the hash tables
        unordered_map<char,int> map_1;
        unordered_map<char,int> map_2;

        // get counts of each character
        for(auto c : s){
            map_1[c]++;
        }

        for(auto c : t){
            map_2[c]++;
        }

        // loop through one of the maps and compare
        for(auto c : s){
            if(map_1[c] != map_2[c]) return false;
        }

        return true;
    }

