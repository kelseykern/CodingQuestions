int getCombos(vector<int> nums, int index, unordered_map<int, int> &m)
{
    if (index == nums.size())
        return 0;

    if (m.count(index) > 0)
        return m[index];

    if (index == nums.size() - 1 ||
        index == nums.size() - 2)
    {
        m[index] = nums[index];
        return nums[index];
    }

    // try 1 between and 2 between
    m[index] = nums[index] +
               max(getCombos(nums, index + 2, m),
                   getCombos(nums, index + 3, m));

    return m[index];
}
int rob(vector<int> &nums)
{
    if (nums.size() < 3)
        return *max_element(nums.begin(), nums.end());
    unordered_map<int, int> m;
    return max(getCombos(nums, 0, m), getCombos(nums, 1, m));
}
