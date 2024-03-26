int findMin(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        // we found beginning value of the sorted array
        if (nums[left] <= nums[right])
            return nums[left];

        int mid = left + (right - left) / 2;
        if (nums[left] > nums[mid])
        {
            // the array starts somewhere between left and mid
            right = mid;
        }
        else if (nums[mid] > nums[right])
        {
            // the array starts somewhere between mid and right
            left = mid + 1;
        }
    }
    if (nums[left] <= nums[right])
        return nums[left];
    return -1;
}
