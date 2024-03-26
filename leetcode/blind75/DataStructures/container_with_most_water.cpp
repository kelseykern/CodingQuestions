int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxarea = 0;

    while (left < right)
    {
        // get width and height
        int w = right - left;
        int h = min(height[left], height[right]);

        // save our highest area we have found
        int currarea = h * w;
        maxarea = max(maxarea, currarea);

        // move the index with the smaller value
        if (height[left] < height[right])
            left++;
        else if (height[left] > height[right])
            right--;
        else
        {
            left++;
            right--;
        }
    }
    return maxarea;
}
