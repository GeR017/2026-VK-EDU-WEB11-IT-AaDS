#include "ListGraph.hpp"
#include "SetGraph.hpp"
#include "MatrixGraph.hpp"
#include "ArcGraph.hpp"
#include <iostream>
#include <queue>

void bfs(const IGraph& graph, int start){
    std::vector<char> visited(graph.VerticesCount(), false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        std::cout << v << " ";
        for(int v : graph.GetNextVertices(v)){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


int main(){
    ListGraph listGraph(5);

    listGraph.AddEdge(0,1);
    listGraph.AddEdge(0,2);
    listGraph.AddEdge(1,3);
    listGraph.AddEdge(2,3);
    listGraph.AddEdge(3,4);

    SetGraph setGraph(listGraph);
    MatrixGraph matrixGraph(listGraph);
    ArcGraph arcGraph(listGraph);

    std::cout << "BFS ListGraph" << std::endl;
    bfs(listGraph, 0);
    std::cout << std::endl;

    std::cout << "BFS SetGraph" << std::endl    ;
    bfs(setGraph, 0);   
    std::cout << std::endl;

    std::cout << "BFS MatrixGraph" << std::endl;
    bfs(matrixGraph, 0);
    std::cout << std::endl;

    std::cout << "BFS ArcGraph" << std::endl;
    bfs(arcGraph, 0);
    return 0;
}   
