vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> answer;
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    answer.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        int &end = answer.back()[1];
        // can we merge?
        if (end >= intervals[i][0])
        {
            end = max(intervals[i][1], end);
        }
        else
        {
            answer.push_back(intervals[i]);
        }
    }

    return answer;
}
