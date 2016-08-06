#ifndef __UNDIRECTED_GRAPH_H__
#define __UNDIRECTED_GRAPH_H__

#include <vector>
#include <map>

#include "graph_base.h"

using namespace std;

class undirected_graph : public graph_base
{
public:
	undirected_graph();
	undirected_graph(const graph_base &gr);
	undirected_graph(const undirected_graph &gr);
	virtual ~undirected_graph();

public:
	// modify the graph
	virtual edge_descriptor add_edge(int s, int t);
	virtual int remove_edge(edge_descriptor e);
	virtual int remove_edge(int s, int t);

	// access
	virtual PEEI out_edges(int v);

	// algorithms
	virtual bool intersect(edge_descriptor ex, edge_descriptor ey);
	vector< set<int> > compute_connected_components();

	// print and draw
	int draw(const string &file, const MIS &mis, const MES &mes, double len);
};

#endif
