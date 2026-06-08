#include "IGraph.hpp"
#include <vector>
#include <unordered_set>
#include <cassert>

class SetGraph : public IGraph {
public:
    explicit SetGraph(int size) : data_(size) {}

    SetGraph(const IGraph &graph) {
        data_.resize(graph.VerticesCount());
        for (int from = 0; from < graph.VerticesCount(); from++) {
            for (int to : graph.GetNextVertices(from)) {
                data_[from].insert(to);
            }
        }
    }

    ~SetGraph() {};

    void AddEdge(int from, int to) override {
        assert(0 <= from && from < data_.size());
        assert(0 <= to && to < data_.size());
        data_[from].insert(to);
    }

    int VerticesCount() const override {
        return data_.size();
    }

    std::vector<int> GetNextVertices(int vertex) const override {
        assert(0 <= vertex && vertex < data_.size());
        return std::vector<int>(data_[vertex].begin(), data_[vertex].end());
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(0 <= vertex && vertex < data_.size());
        std::vector<int> prev;
        for (int from = 0; from < data_.size(); from++) {
            if (data_[from].count(vertex))
                prev.push_back(from);
        }
        return prev;
    }

private:
    std::vector<std::unordered_set<int>> data_;
};