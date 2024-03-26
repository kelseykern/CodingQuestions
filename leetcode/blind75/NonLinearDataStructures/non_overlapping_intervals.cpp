static bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int count = 0;
    sort(intervals.begin(), intervals.end(), compare);
    for (int i = 0; i < intervals.size(); i++)
    {
        int right = intervals[i][1];
        while (i < intervals.size() - 1 && right > intervals[i + 1][0])
        {
            count++;
            i++;
        }
    }
    return count;
}
