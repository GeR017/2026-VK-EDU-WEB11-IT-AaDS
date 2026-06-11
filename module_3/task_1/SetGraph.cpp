#include "SetGraph.hpp"
#include <vector>
#include <cassert>


SetGraph::SetGraph(int size) : data_(size) {}

SetGraph::SetGraph(const IGraph &graph) {
    data_.resize(graph.VerticesCount());
    for (int from = 0; from < graph.VerticesCount(); from++) {
        for (int to : graph.GetNextVertices(from)) {
            data_[from].insert(to);
        }
    }
}

SetGraph::~SetGraph() {}

void SetGraph::AddEdge(int from, int to)  {
    assert(0 <= from && from < data_.size());
    assert(0 <= to && to < data_.size());
    data_[from].insert(to);
}

int SetGraph::VerticesCount() const  {
    return data_.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const  {
    assert(0 <= vertex && vertex < data_.size());
    return std::vector<int>(data_[vertex].begin(), data_[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const  {
    assert(0 <= vertex && vertex < data_.size());
    std::vector<int> prev;
    for (int from = 0; from < data_.size(); from++) {
        if (data_[from].count(vertex))
            prev.push_back(from);
    }
    return prev;
}

