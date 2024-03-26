int recurse(vector<int> &nums, int target, vector<int> &remaining)
{
    if (target < 0)
        return 0; // 0 ways to make invalid target
    if (target == 0)
        return 1; // 1 way to make 0
    if (remaining[target] != -1)
        return remaining[target]; // already found remaining for that target

    int count = 0;
    // starting with num[i], how many ways can we reach target
    for (int i = 0; i < nums.size(); i++)
    {
        count = count + recurse(nums, target - nums[i], remaining);
    }

    remaining[target] = count;
    return count;
}

int combinationSum4(vector<int> &nums, int target)
{
    // remaining sum to reach target could range from 0 to target
    vector<int> remaining(target + 1, -1); // [-1, -1, -1, -1]
    return recurse(nums, target, remaining);
}
