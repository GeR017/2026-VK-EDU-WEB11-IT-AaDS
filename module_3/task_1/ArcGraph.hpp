#pragma once

#include "IGraph.hpp"
#include <vector>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int size);
    ArcGraph(const IGraph &graph);
    ~ArcGraph() override;
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertices_count_;
    std::vector<std::pair<int, int>> data_;
};