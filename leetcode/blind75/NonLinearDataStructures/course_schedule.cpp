vector<vector<int>> adj;
vector<int> checked;

// Create new vector of vectors where index = prerequisite and vector is dependents
void build_adj(vector<vector<int>>& prerequisites){
    int parent = 1;
    int child = 0;
    for(vector<int>& pair:prerequisites){
        adj[pair[parent]].push_back(pair[child]);
    }
}

// Depth-first search to detect cycles and mark visited status
bool dfs(int course) {
    if (checked[course] == 1) 
        return 0;  // Cycle detected
    if (checked[course] == 2) 
        return 1;  // Already checked that we can take this course
    checked[course] = 1;  // Mark as checked
    for (int child : adj[course]) {
        if (dfs(child) == 0) //if cycle detected return 0
            return false;
    }
    checked[course] = 2;  // Reached the end, we can take this course
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // there are N courses numbered 0-N
    adj.resize(numCourses);

    // change vector to parent -> child
    build_adj(prerequisites);
    checked.assign(numCourses, 0);

    // for each course, 
    for(int course=0; course<numCourses; course++)
        // if it is not checked,
        if (!checked[course]){
            //check if possible to take it / dfs check for a cycle / follow dependency until no dependency
            if (dfs(course) == false) return false;            
        }
    return true;
}

