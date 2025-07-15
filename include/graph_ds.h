#pragma once
#include "interface.h"
#include <vector>
#include <queue>
#include <iostream>
namespace dsa{
class GraphDS : public IDataStructure {
    std::vector<std::vector<int>> adj;

    void dfsUtil(int u, std::vector<bool>& visited) const;
    void dfs(int start) const;
    void bfs(int start) const;

public:
    explicit GraphDS(int n = 5);
    void addEdge(int u, int v);
    void print() const;
    void menu() override;
};
}