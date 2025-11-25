#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    bool isCyclic(int N, vector<int> adj[]) {
        
        queue<int> q;
        vector<int> inDegree(N, 0);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                inDegree[adj[i][j]]++;
            }
        }

        for(int i = 0; i < N; i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        int countProcessedNodes = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            countProcessedNodes++;

            for(int v : adj[u]) {
                inDegree[v] -= 1;
                if(inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return N != countProcessedNodes;
    }
};