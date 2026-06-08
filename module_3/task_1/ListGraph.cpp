#include "IGraph.hpp"

#include <iostream>
#include <functional>
#include <vector>
#include <cassert>

struct ListGraph: public IGraph
{
public:
    ListGraph(int size): data_(size) {}

    ListGraph(const IGraph &graph) {
        data_.resize(graph.VerticesCount());

        for (int i = 0; i < graph.VerticesCount(); i++)
            data_[i] = graph.GetNextVertices(i);
    }

    ~ListGraph() {}

    void
    AddEdge(int from, int to) override {
        assert(0 <= from && from < data_.size());
        assert(0 <= to && to < data_.size());
        data_[from].push_back(to);
    }

    int
    VerticesCount() const override {
        return data_.size();
    }

    std::vector<int> GetNextVertices(int vertex) const override {
        return data_[vertex];
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
        std::vector<int> prev;
        for (int from = 0; from < data_.size(); from++) {
           for (int to: data_[from]) {
               if (to == vertex)
                   prev.push_back(from);
           }
        }
        return prev;
    }

private:
    std::vector<std::vector<int>> data_;
};

