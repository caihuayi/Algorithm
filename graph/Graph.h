#ifndef _GRAPH_H_
#define _GRAPH_H_ 

#include <vector>
#include <set>
using std::set;
using std::vector;

class Graph {
public:
	set<int> vertex;
	vector<vector<int>> adj;
	Graph(set<int>& _vertex, vector<vector<int>>& adj);
	Graph() = default;
	Graph(Graph&& g);
	int num_v;
	int num_edge;
};

#endif
