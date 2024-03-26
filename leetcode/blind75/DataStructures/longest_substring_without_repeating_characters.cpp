int lengthOfLongestSubstring(string s)
{
    if (s.size() < 2)
        return s.size();

    unordered_map<char, int> mp;
    int start = 0;
    int longest = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char Char = s[i];

        // if it exists in our map
        if (mp.count(Char) > 0)
        {
            // move up start and remove characters before it
            int existing_index = mp[Char];
            while (start <= existing_index)
            {
                // remove char from map
                mp.erase(s[start]);
                start++;
            }
        }

        // insert new char to map
        mp.insert({Char, i});

        int currentLength = (i - start) + 1;
        longest = max(longest, currentLength);
    }

    return longest;
}
