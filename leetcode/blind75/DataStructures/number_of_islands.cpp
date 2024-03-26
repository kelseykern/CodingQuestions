void bfs_mark_adjacent(vector<vector<char>> &grid,
                       int i, int j)
{

    if (
        i >= grid.size() ||
        j >= grid[0].size() ||
        grid[i][j] != '1')
        return;

    grid[i][j] = '2';

    // mark neighboring below
    bfs_mark_adjacent(grid, i + 1, j);

    // mark neighboring to the right
    bfs_mark_adjacent(grid, i, j + 1);
}

int numIslands(vector<vector<char>> &grid)
{

    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    // loop through grid until we find a 1
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == '1')
            {
                // add to counter of starting 1's
                //  (start of new island)
                count++;

                // bfs starting here and mark every 1
                //  to a 2 (visited)
                // each bfs returns when it hits a 0
                bfs_mark_adjacent(grid, row, col);
            }
        }
    }
    return count;
}
