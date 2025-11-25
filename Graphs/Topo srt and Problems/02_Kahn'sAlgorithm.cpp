#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
       
        vector<int> res;
        queue<int> q;
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                inDegree[adj[i][j]]++;
            }
        }

        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);

            for(int v : adj[u]) {
                inDegree[v] -= 1;
                if(inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return res;
    }
};
