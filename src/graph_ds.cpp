#include "graph_ds.h"
namespace dsa{
GraphDS::GraphDS(int n) : adj(n) {}

void GraphDS::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void GraphDS::print() const {
    for (size_t i = 0; i < adj.size(); ++i) {
        std::cout << i << ":";
        for (int v : adj[i]) std::cout << ' ' << v;
        std::cout << "\n";
    }
}

void GraphDS::dfsUtil(int u, std::vector<bool>& visited) const {
    visited[u] = true;
    std::cout << u << ' ';
    for (int v : adj[u]) {
        if (!visited[v]) dfsUtil(v, visited);
    }
}

void GraphDS::dfs(int start) const {
    std::vector<bool> visited(adj.size(), false);
    std::cout << "DFS traversal: ";
    dfsUtil(start, visited);
    std::cout << "\n";
}

void GraphDS::bfs(int start) const {
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    std::cout << "BFS traversal: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        std::cout << u << ' ';
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    std::cout << "\n";
}

void GraphDS::menu() {
    while (true) {
        std::cout << "\n— Graph Operations —\n1. Add Edge\n2. Display\n3. DFS\n4. BFS\n0. Return\n> ";
        int c; std::cin >> c;
        if (c == 0) break;
        switch (c) {
            case 1: {
                int u, v; std::cout << "u v: "; std::cin >> u >> v;
                if (u >= 0 && u < adj.size() && v >= 0 && v < adj.size()) addEdge(u, v);
                else std::cout << "Out of range\n";
                break;
            }
            case 2:
                print(); break;
            case 3: {
                int s; std::cout << "Start node for DFS: "; std::cin >> s;
                if (s >= 0 && s < adj.size()) dfs(s);
                else std::cout << "Invalid node\n";
                break;
            }
            case 4: {
                int s; std::cout << "Start node for BFS: "; std::cin >> s;
                if (s >= 0 && s < adj.size()) bfs(s);
                else std::cout << "Invalid node\n";
                break;
            }
            default:
                std::cout << "Invalid\n";
        }
    }
}
}