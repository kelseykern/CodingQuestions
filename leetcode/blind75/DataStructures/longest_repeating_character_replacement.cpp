int characterReplacement(string s, int k)
{
    int maxLen = 0;
    int highestSingleCharCount = 0;
    int start = 0;

    // map of char & count
    unordered_map<char, int> m;

    for (int end = 0; end < s.length(); ++end)
    {
        char character = s[end];

        // add to that character's occurrence count
        m[character]++;

        // check if this addition to the map, changed our highestSingleCharCount
        highestSingleCharCount = max(highestSingleCharCount, m[character]);

        // only move up our start index if our substring length is larger than what we can make repeating
        int substring_length = end - start + 1;
        int longest_sequence_we_can_make = highestSingleCharCount + k;

        if (substring_length > longest_sequence_we_can_make)
        {
            character = s[start];
            m[character]--;
            start++;
            substring_length--;
        }

        maxLen = max(maxLen, substring_length);
    }
    return maxLen;
}
