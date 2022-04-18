#include "Graph.h"
#include "mst.h"

#include <set>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using std::vector;
using std::set;
using std::min;
using std::cout;
using std::endl;

Graph kruskal(const Graph& graph) {
	set<int> vertex;
	set<int> old_vertex = graph.vertex;
	vector<vector<int>> adj(graph.num_v, vector<int>(graph.num_v, 0));
	while (vertex != old_vertex) {
		int m = INT_MAX;
		for (int i = 0; i < graph.num_v; ++i) {
			for (int j = i; j < graph.num_v; ++j) {
				if (graph.adj[i][j] > 0 && (vertex.count(i) == 0 || vertex.count(j) == 0)) {
					m = min(m, graph.adj[i][j]);
				}
			}
		}
		for (int i = 0; i < graph.num_v; ++i) {
			for (int j = i; j < graph.num_v; ++j) {
				if (m == graph.adj[i][j] && (vertex.count(i) == 0 || vertex.count(j) == 0)) {
					if (vertex.count(i) == 0) {
						vertex.insert(i);
						cout << i << " ";
					}
					if (vertex.count(j) == 0) {
						vertex.insert(j);
						cout << j << " ";
					}
					adj[i][j] = adj[j][i] = graph.adj[i][j];
					cout << endl;
				}
			}
		}
	}

	return Graph(vertex, adj);
}
