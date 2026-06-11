#include "ListGraph.hpp"

#include <iostream>
#include <functional>
#include <vector>
#include <cassert>


ListGraph::ListGraph(int size): data_(size) {}

ListGraph::ListGraph(const IGraph &graph) {
    data_.resize(graph.VerticesCount());

    for (int i = 0; i < graph.VerticesCount(); i++)
        data_[i] = graph.GetNextVertices(i);
}

ListGraph::~ListGraph() {}

void
ListGraph::AddEdge(int from, int to)  {
    assert(0 <= from && from < data_.size());
    assert(0 <= to && to < data_.size());
    data_[from].push_back(to);
}

int
ListGraph::VerticesCount() const  {
    return data_.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const  {
    return data_[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const  {
    std::vector<int> prev;
    for (int from = 0; from < data_.size(); from++) {
        for (int to: data_[from]) {
            if (to == vertex)
                prev.push_back(from);
        }
    }
    return prev;
}



