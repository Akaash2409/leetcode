class Solution {
public:
    bool isCyclicUtil(int cur, unordered_map<int, vector<int>>& edges, vector<bool>& visited, vector<bool>& recStack){
        visited[cur] = true;
        recStack[cur] = true;
        for(int nei : edges[cur]){
            if(!visited[nei]){
                if(isCyclicUtil(nei, edges, visited, recStack)){
                    return true;
                }
            }else if(recStack[nei]){
                return true;
            }
        }
        recStack[cur] = false;        
        return false;
    };
     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        
        bool hasCycle = false;
        
        unordered_map<int, vector<int>> edges;
        for(vector<int>& pre : prerequisites){
            edges[pre[1]].push_back(pre[0]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(isCyclicUtil(i, edges, visited, recStack)){
                    hasCycle = true;
                    break;
                }
            }
        }
        
        return !hasCycle;
    }
};