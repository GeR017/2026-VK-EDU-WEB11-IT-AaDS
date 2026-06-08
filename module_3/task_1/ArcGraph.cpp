

#include "IGraph.hpp"
#include <vector>
#include <utility>
#include <cassert>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int size) : vertices_count_(size) {}

    ArcGraph(const IGraph &graph) : vertices_count_(graph.VerticesCount()) {
        for (int from = 0; from < vertices_count_; ++from) {
            for (int to : graph.GetNextVertices(from)) {
                data_.push_back({from, to});
            }
        }
    }

    ~ArcGraph() {};

    void AddEdge(int from, int to) override {
        assert(0 <= from && from < vertices_count_);
        assert(0 <= to && to < vertices_count_);
        data_.push_back({from, to});
    }

    int VerticesCount() const override {
        return vertices_count_;
    }

    std::vector<int> GetNextVertices(int vertex) const override {
        assert(0 <= vertex && vertex < vertices_count_);
        std::vector<int> next;
        for (const auto &edge : data_) {
            if (edge.first == vertex)
                next.push_back(edge.second);
        }
        return next;
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(0 <= vertex && vertex < vertices_count_);
        std::vector<int> prev;
        for (const auto &edge : data_) {
            if (edge.second == vertex)
                prev.push_back(edge.first);
        }
        return prev;
    }

private:
    int vertices_count_;
    std::vector<std::pair<int, int>> data_;
};