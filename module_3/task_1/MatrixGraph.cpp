#include "IGraph.hpp"
#include <vector>
#include <cassert>

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int size) : matrix_(size, std::vector<char>(size, 0)) {}

    MatrixGraph(const IGraph &graph) {
        int size = graph.VerticesCount();
        matrix_.assign(size, std::vector<char>(size, 0));
        for (int from = 0; from < size; from++) {
            for (int to : graph.GetNextVertices(from)) {
                matrix_[from][to] = 1;
            }
        }
    }

    ~MatrixGraph() {};

    void AddEdge(int from, int to) override {
        assert(0 <= from && from < matrix_.size());
        assert(0 <= to && to < matrix_.size());
        matrix_[from][to] = 1;
    }

    int VerticesCount() const override {
        return matrix_.size();
    }

    std::vector<int> GetNextVertices(int vertex) const override {
        assert(0 <= vertex && vertex < matrix_.size());
        std::vector<int> next;
        for (int to = 0; to < matrix_.size(); to++) {
            if (matrix_[vertex][to])
                next.push_back(to);
        }
        return next;
    }

    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(0 <= vertex && vertex < matrix_.size());
        std::vector<int> prev;
        for (int from = 0; from < matrix_.size(); from++) {
            if (matrix_[from][vertex])
                prev.push_back(from);
        }
        return prev;
    }

private:
    std::vector<std::vector<char>> matrix_;
};