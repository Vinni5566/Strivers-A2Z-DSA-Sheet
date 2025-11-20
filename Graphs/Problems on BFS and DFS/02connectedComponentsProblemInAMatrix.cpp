#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {

      vector<vector<int>> matrix = buildGraph(V, edges);

      vector<bool> visited(V, false);
        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bfsdis(matrix, visited, i);
                count++;
            }
        }

        return count;
    
    }

    vector<vector<int>> buildGraph(int V, vector<vector<int>> &edges) {

      vector<vector<int>> matrix(V, vector<int>(V, 0));

      for(int i = 0; i < edges.size(); i++) {
        
        int u = edges[i][0];
        int v = edges[i][1];

        matrix[u][v] = 1;
        matrix[v][u] = 1;
        
      }

      return matrix;
    }

    void bfsdis(vector<vector<int>>& matrix, vector<bool>& visited, int src) {
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            for(int v = 0; v < matrix.size(); v++) {
                if(matrix[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};