#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:

    void dfsRec(vector<int> adj[], vector<int>& res, vector<bool>& visited, int src) {

      visited[src] = true;
      res.push_back(src);

      for(int x : adj[src]) {
        if(!visited[x]) {
          dfsRec(adj, res, visited, x);
        }
      }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {

      vector<int> res;
      vector<bool> visited(V, false);
      dfsRec(adj, res, visited, 0);
      return res;

    }

    void bfsRec(vector<int> adj[], vector<int>& res, vector<bool>& visited, int src) {

      queue<int> q;     
      q.push(src);
      visited[src] = true;

      while(!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for(int x : adj[curr]) {
          if(!visited[x]) {
            visited[x] = true;
            q.push(x);
          }
        }

      }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> visited(V, false);
        bfsRec(adj, res, visited, 0);
        return res;
    }
};