#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    bool isCycle(int V, vector<int> adj[]) {

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                queue<pair<int, int>> q;
                q.push({i, -1});
                visited[i] = true;

                while(!q.empty()) {
                    int u = q.front().first;
                    int p = q.front().second;
                    q.pop();

                    for(int v : adj[u]) {
                        if(!visited[v]) {
                            visited[v] = true;
                            q.push({v, u});
                        } else if (v != p) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;

    }
};