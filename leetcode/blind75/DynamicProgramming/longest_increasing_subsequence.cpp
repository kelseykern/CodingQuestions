int lengthOfLIS(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;

    vector<int> memo(nums.size(), 1);

    for (int start = nums.size() - 1; start >= 0; start--)
    {
        // for each starting index (starting on the end)
        for (int next = start + 1; next < nums.size(); next++)
        {
            // try all paths that have potential to work
            if (nums[start] < nums[next])
            {
                // try it
                memo[start] = max(memo[start], memo[next] + 1);
            }
        }
    }

    return *max_element(memo.begin(), memo.end());
}
