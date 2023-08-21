#include <bits/stdc++.h>
using namespace std;

class Graph{
   public:
      int nodes;
      list<int> *adj_list;
      Graph(int);
      void insert_edge(int, int);
      vector<int> BFS(int, int, int []);
};

Graph::Graph(int nodes) {
   this->nodes = nodes;
   adj_list = new list<int>[nodes+1];
}

void Graph::insert_edge(int u, int v) {
   adj_list[u].push_back(v);
   adj_list[v].push_back(u);
}

vector<int> Graph::BFS(int comp_sum, int src,int visited[])
{
   queue<int> queue;
   queue.push(src);
   visited[src] = comp_sum;
   vector<int> reachableNodes;
   while(!queue.empty()) {
      int u = queue.front();
      queue.pop();
      reachableNodes.push_back(u);
      for (auto itr = adj_list[u].begin(); itr != adj_list[u].end(); itr++) {
         if (!visited[*itr]) {
            visited[*itr] = comp_sum;
            queue.push(*itr);
         }
      }
   }
   return reachableNodes;
}

void displayReachableNodes(int n, unordered_map <int, vector<int> > m)
{
   vector<int> temp = m[n];
   for (int i=0; i<temp.size(); i++)
      cout << temp[i] << " ";
   cout << endl;
}

void get_all_reachable(Graph g, int arr[], int n)
{
   int nodes = g.nodes;
   int visited[nodes+1];
   memset(visited, 0, sizeof(visited));
   unordered_map <int, vector<int> > m;
   int comp_sum = 0;
   for (int i = 0 ; i < n ; i++) {
      int u = arr[i];
      if (!visited[u]) {
         comp_sum++;
         m[visited[u]] = g.BFS(comp_sum, u, visited);
      }
      cout << "Reachable Nodes from " << u <<" are\n";
      displayReachableNodes(visited[u], m);
   }
}


int main() {
   int nodes = 5;
   Graph g(nodes);
   g.insert_edge(1, 2);
   g.insert_edge(2, 3);
   g.insert_edge(4, 5);
   int arr[] = {2, 4, 1};
   int n = sizeof(arr)/sizeof(int);
   get_all_reachable(g, arr, n);
}
