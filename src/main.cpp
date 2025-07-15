
#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <optional>


// 1.  Common interface every data‑structure menu implements

class IDataStructure {
public:
    virtual void menu() = 0;  
    virtual ~IDataStructure() = default;
};


// 2.  Array

class ArrayDS : public IDataStructure {
    std::vector<int> a;
    void print() const {
        std::cout << "[ ";
        for (int x : a) std::cout << x << ' ';
        std::cout << "]\n";
    }
public:
    void menu() override {
        while (true) {
            std::cout << "\n— Array Operations —\n"
                         "1. Push Back\n2. Insert at Index\n3. Erase at Index\n4. Display\n0. Return\n> ";
            int c; std::cin >> c;
            if (c==0) break;
            switch (c) {
                case 1: {
                    int val; std::cout << "Value: "; std::cin >> val;
                    a.push_back(val);
                    break;
                }
                case 2: {
                    int idx,val; std::cout << "Index Value: "; std::cin >> idx >> val;
                    if(idx>=0 && idx<=a.size()) a.insert(a.begin()+idx,val);
                    else std::cout << "Invalid index\n";
                    break;
                }
                case 3: {
                    int idx; std::cout << "Index: "; std::cin >> idx;
                    if(idx>=0 && idx<a.size()) a.erase(a.begin()+idx);
                    else std::cout << "Invalid index\n";
                    break;
                }
                case 4:  print(); break;
                default: std::cout << "Invalid option\n";
            }
        }
    }
};

// 3.  Singly Linked List

class LinkedListDS : public IDataStructure {
    struct Node { int data; Node* next; Node(int d):data(d),next(nullptr){} };
    Node* head = nullptr;

    void push_front(int v) {
        Node* newNode = new Node(v);
        newNode->next = head;
        head = newNode;
    }

    void push_back(int v) {
        if (!head) {
            head = new Node(v);
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new Node(v);
    }

    bool deleteValue(int value) {
    if (!head) return false;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* cur = head;
    while (cur->next && cur->next->data != value) {
        cur = cur->next;
    }

    if (cur->next) {
        Node* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        return true;
    }

    return false; // Not found
}

    int search(int value) const {
    Node* cur = head;
    int index = 0;
    while (cur) {
        if (cur->data == value)
            return index;
        cur = cur->next;
        index++;
    }
    return -1; // Not found
}


    void print() const {
        Node* cur = head; std::cout << "head -> ";
        while (cur) { std::cout << cur->data << " -> "; cur = cur->next; }
        std::cout << "NULL\n";
    }

    

public:
    void menu() override {
        while (true) {
            std::cout << "\n— Linked List Operations —\n";
            std::cout<<"1. Push Front\n2. Push Back\n3. Display\n4. Delete Value\n5. Search Value\n0. Return\n> ";
            int c; std::cin >> c; if (c == 0) break;
            switch (c) {
                case 1: {
                    int v; std::cout << "Value: "; std::cin >> v; push_front(v); break;
                }
                case 2: {
                    int v; std::cout << "Value: "; std::cin >> v; push_back(v); break;
                }
                case 3: print(); break;
                default: std::cout << "Invalid option\n";
                case 4: {
                    int val; std::cout << "Value to delete: "; std::cin >> val;
                    if (deleteValue(val)) std::cout << "Deleted successfully\n";
                    else std::cout << "Value not found\n";
                break;
                }
                case 5: {
                    int val; std::cout << "Value to search: "; std::cin >> val;
                    int pos = search(val);
                    if (pos != -1) std::cout << "Found at position " << pos << "\n";
                    else std::cout << "Not found\n";
                    break;
                }


            }
        }
    }

    ~LinkedListDS() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};



// 4.  Stack 

class StackDS : public IDataStructure {
    std::stack<int> st;
public:
    void menu() override {
        while(true){
            std::cout<<"\n— Stack Operations —\n1. Push\n2. Pop\n3. Top\n4. Size\n0. Return\n> ";
            int c; std::cin>>c; if(c==0) break;
            switch(c){
                case 1:{int v; std::cout<<"Value: "; std::cin>>v; st.push(v); break;}
                case 2:{ if(st.empty())std::cout<<"Empty\n"; else{std::cout<<st.top()<<" popped\n"; st.pop();} break;}
                case 3:{ if(st.empty())std::cout<<"Empty\n"; else std::cout<<"Top = "<<st.top()<<"\n"; break; }
                case 4:{ std::cout<<"Size = "<<st.size()<<"\n"; break; }
                default: std::cout<<"Invalid\n";
            }
        }
    }
};


// 5.  Queue 

class QueueDS : public IDataStructure {
    std::queue<int> q;
public:
    void menu() override {
        while(true){
            std::cout<<"\n— Queue Operations —\n1. Enqueue\n2. Dequeue\n3. Front\n4. Size\n0. Return\n> ";
            int c; std::cin>>c; if(c==0) break;
            switch(c){
                case 1:{int v; std::cout<<"Value: "; std::cin>>v; q.push(v); break;}
                case 2:{ if(q.empty())std::cout<<"Empty\n"; else{std::cout<<q.front()<<" dequeued\n"; q.pop();} break;}
                case 3:{ if(q.empty())std::cout<<"Empty\n"; else std::cout<<"Front = "<<q.front()<<"\n"; break; }
                case 4:{ std::cout<<"Size = "<<q.size()<<"\n"; break; }
                default: std::cout<<"Invalid\n";
            }
        }
    }
};


// 6.  Binary Search Tree

class BSTDS : public IDataStructure {
    struct Node{int key; Node* l; Node* r; Node(int k):key(k),l(nullptr),r(nullptr){} };
    Node* root=nullptr;
    Node* insert(Node* n,int k){ if(!n) return new Node(k); if(k<n->key) n->l=insert(n->l,k); else n->r=insert(n->r,k); return n; }
    
    Node* deleteNode(Node* node, int key) {
    if (!node) return nullptr;
    if (key < node->key) {
        node->l = deleteNode(node->l, key);
    } else if (key > node->key) {
        node->r = deleteNode(node->r, key);
    } else {
        // Found node to delete
        if (!node->l) {
            Node* temp = node->r;
            delete node;
            return temp;
        } else if (!node->r) {
            Node* temp = node->l;
            delete node;
            return temp;
        } else {
            // Node with 2 children: find inorder successor
            Node* succ = node->r;
            while (succ->l) succ = succ->l;
            node->key = succ->key;
            node->r = deleteNode(node->r, succ->key);
        }
    }
    return node;
}


    
    void inorder(Node* n){ if(!n) return; inorder(n->l); std::cout<<n->key<<' '; inorder(n->r);} 
    
    bool search(Node* n, int key) {
        if (!n) return false;
        if (key == n->key) return true;
        if (key < n->key) return search(n->l, key);
        return search(n->r, key);
    }


public:
    void menu() override {
        while(true){
            std::cout<<"\n— BST Operations —\n1. Insert\n2. In-order Traversal\n3. Search\n4. Delete\n0. Return\n> ";

            int c; std::cin>>c; if(c==0) break;
            switch(c){
                case 1:{int k; std::cout<<"Key: "; std::cin>>k; root=insert(root,k); break;}
                case 2:{ inorder(root); std::cout<<"\n"; break; }
                case 3: {
                    int key; std::cout << "Key to search: "; std::cin >> key;
                    if (search(root, key)) std::cout << "Found\n";
                    else std::cout << "Not found\n";
                    break;
                }
                case 4: {
                    int key; std::cout << "Key to delete: "; std::cin >> key;
                    root = deleteNode(root, key);
                    break;
                }

                default: std::cout<<"Invalid\n";
            }
        }
    }
    
};


// 7.  Graph (undirected, adjacency list)

class GraphDS : public IDataStructure {
    std::vector<std::vector<int>> adj;

    void dfsUtil(int u, std::vector<bool>& visited) const {
        visited[u] = true;
        std::cout << u << ' ';
        for (int v : adj[u]) {
            if (!visited[v]) dfsUtil(v, visited);
        }
    }


    void dfs(int start) const {
        std::vector<bool> visited(adj.size(), false);
        std::cout << "DFS traversal: ";
        dfsUtil(start, visited);
        std::cout << "\n";
    }

    void bfs(int start) const {
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



public:
    explicit GraphDS(int n=5):adj(n){}
    void addEdge(int u,int v){ adj[u].push_back(v); adj[v].push_back(u);} 
    void print() const {
        for(size_t i=0;i<adj.size();++i){
            std::cout<<i<<":";
            for(int v:adj[i]) std::cout<<' '<<v;
            std::cout<<"\n";
        }
    }
    void menu() override {
        while(true){
            std::cout<<"\n— Graph Operations —\n1. Add Edge\n2. Display\n3. DFS\n4. BFS\n0. Return\n> ";

            int c; std::cin>>c; if(c==0) break;
            switch(c){
                case 1:{int u,v; std::cout<<"u v: "; std::cin>>u>>v; if(u>=0&&u<adj.size()&&v>=0&&v<adj.size()) addEdge(u,v); else std::cout<<"Out of range\n"; break;}
                case 2: print(); break;
                case 3: {
                    int start; std::cout << "Start node for DFS: "; std::cin >> start;
                    if (start >= 0 && start < adj.size()) dfs(start);
                    else std::cout << "Invalid node\n";
                    break;
                }
                case 4: {
                    int start; std::cout << "Start node for BFS: "; std::cin >> start;
                    if (start >= 0 && start < adj.size()) bfs(start);
                    else std::cout << "Invalid node\n";
                    break;
                }

                default: std::cout<<"Invalid\n";
            }
        }
    }
};


// 8. Factory to obtain desired data‑structure object

std::unique_ptr<IDataStructure> makeDS(int choice){
    switch(choice){
        case 1: return std::make_unique<ArrayDS>();
        case 2: return std::make_unique<LinkedListDS>();
        case 3: return std::make_unique<StackDS>();
        case 4: return std::make_unique<QueueDS>();
        case 5: return std::make_unique<BSTDS>();
        case 6: return std::make_unique<GraphDS>();
        default: return nullptr;
    }
}


// 9. Main menu loop

int main(){
    std::cout<<"==============================\n"
               "   DSA-Playground\n"
               "==============================\n";
    while(true){
        std::cout<<"\nSelect a Data Structure:\n"
                 "1. Array\n2. Linked List\n3. Stack\n4. Queue\n5. Binary Search Tree\n6. Graph\n0. Exit\n> ";
        int ch; std::cin>>ch; if(ch==0) break;
        auto ds=makeDS(ch);
        if(ds) ds->menu();
        else std::cout<<"Invalid choice!\n";
    }
    std::cout<<"Goodbye!\n";
    return 0;
}
