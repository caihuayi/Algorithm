#include "Graph.h"
#include "mst.h"
#include <vector>
#include <set>
#include <iostream>

using std::set;
using std::vector;
using std::cout;
using std::cin;
using std::endl;



int main()
{
	vector<int> vertex = {0, 1, 2, 3, 4};
	vector<vector<int>> adj = 
	{
		{0, 4, 0, 3, 0},
		{4, 0, 2, 0, 1},
		{0, 2, 0, 5, 6},
		{3, 0, 5, 0, 0},
		{0, 1, 6, 0, 0}
	};
	set<int> vertex_set(vertex.begin(), vertex.end());
	Graph g = Graph(vertex_set, adj);
	Graph r = prim(g);	
	Graph r2 = kruskal(g);	
	for (auto& i: r.adj) {
		for (auto j: i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "==============" << endl;
	for (auto& i: r2.adj) {
		for (auto j: i) {
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
