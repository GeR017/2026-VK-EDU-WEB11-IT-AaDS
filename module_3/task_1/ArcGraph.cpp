#include "ArcGraph.hpp"
#include <vector>
#include <utility>
#include <cassert>


ArcGraph::ArcGraph(int size) : vertices_count_(size) {}

ArcGraph::ArcGraph(const IGraph &graph) : vertices_count_(graph.VerticesCount()) {
    for (int from = 0; from < vertices_count_; ++from) {
        for (int to : graph.GetNextVertices(from)) {
            data_.push_back({from, to});
        }
    }
}

ArcGraph::~ArcGraph() {};

void ArcGraph::AddEdge(int from, int to)  {
    assert(0 <= from && from < vertices_count_);
    assert(0 <= to && to < vertices_count_);
    data_.push_back({from, to});
}

int ArcGraph::VerticesCount() const {
    return vertices_count_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < vertices_count_);
    std::vector<int> next;
    for (const auto &edge : data_) {
        if (edge.first == vertex)
            next.push_back(edge.second);
    }
    return next;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < vertices_count_);
    std::vector<int> prev;
    for (const auto &edge : data_) {
        if (edge.second == vertex)
            prev.push_back(edge.first);
    }
    return prev;
}

