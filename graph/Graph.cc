#include "Graph.h"
Graph::Graph(set<int>& _vertex, vector<vector<int>>& _adj): vertex(_vertex), adj(_adj){
	num_v = _vertex.size();
	num_edge = 0;
	for (auto &a: _adj) {
		for (auto b: a) {
			if (b != 0) {
				num_edge += 1;
			}
		}
	}
	num_edge /= 2;
}

Graph::Graph(Graph&& _graph):vertex(_graph.vertex), adj(_graph.adj), num_v(_graph.num_v), num_edge(_graph.num_edge){}
