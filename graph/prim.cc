#include "Graph.h"
#include "mst.h"

#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <algorithm>
using std::vector;
using std::set;
using std::min;
using std::cout;
using std::endl;
	
Graph prim(const Graph& graph) {
	set<int> vertex;
	vertex.insert(*(graph.vertex.begin()));
	vector<vector<int>> adj(graph.num_v, vector<int>(graph.num_v, 0));
	set<int> old_vertex(graph.vertex);

	while (vertex != old_vertex) {
		int m = INT_MAX;
		for (auto v: vertex) {
			for (int i = v; i < graph.num_v; ++i) {
				if (graph.adj[v][i] > 0 && vertex.count(i) == 0){
					m = min(m, graph.adj[v][i]);
				}
			} 
		}
		cout << m << endl;
		for (auto v: vertex) {
			for (int i = v; i < graph.num_v; ++i) {
				if (graph.adj[v][i] == m && vertex.count(i) == 0) {
					vertex.insert(i);
					adj[v][i] = adj[i][v] = m;
					cout << i << endl;
				}
			}
		}	
	}
	return Graph(vertex, adj);
}
