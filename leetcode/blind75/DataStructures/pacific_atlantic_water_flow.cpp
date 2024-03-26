void dfs(int i, int j, vector<vector<int>> &height, vector<vector<bool>> &ocean)
{
    int n = height.size();
    int m = height[0].size();

    // mark this point as able to reach
    ocean[i][j] = true;

    // check if points can reach us

    // can the point above reach us?
    // if the point above us is greater or equal to us, it can reach us
    if (i > 0 && ocean[i - 1][j] == false && height[i - 1][j] >= height[i][j])
        // check the point above us
        dfs(i - 1, j, height, ocean);

    // can the point to our left reach us?
    if (j > 0 && height[i][j - 1] >= height[i][j] && ocean[i][j - 1] == false)
        dfs(i, j - 1, height, ocean);

    // can the point to our right reach us?
    if (j < m - 1 && height[i][j + 1] >= height[i][j] && ocean[i][j + 1] == false)
        dfs(i, j + 1, height, ocean);

    // can the point below reach us?
    if (i < n - 1 && height[i + 1][j] >= height[i][j] && ocean[i + 1][j] == false)
        dfs(i + 1, j, height, ocean);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> ans;
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<bool>> pacific(n + 1, vector<bool>(m + 1, false));
    vector<vector<bool>> atlantic(n + 1, vector<bool>(m + 1, false));

    // check pacific -> atlantic
    for (int i = 0; i < n; i++)
    {
        // for each point
        for (int j = 0; j < m; j++)
        {
            // if we are on pacific side
            if (i == 0 || j == 0)
                dfs(i, j, heights, pacific);
        }
    }
    // check atlantic -> pacific
    for (int i = 0; i < n; i++)
    {
        // for each point
        for (int j = 0; j < m; j++)
        {
            // if we are on atlantic side
            if (i == n - 1 || j == m - 1)
                dfs(i, j, heights, atlantic);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (atlantic[i][j] == true && pacific[i][j] == true)
                ans.push_back({i, j});
        }
    }
    return ans;
}
