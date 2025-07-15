#pragma once
#include "interface.h"
#include <iostream>
namespace dsa{
class BSTDS : public IDataStructure {
    struct Node {
        int key;
        Node* l;
        Node* r;
        Node(int k) : key(k), l(nullptr), r(nullptr) {}
    };

    Node* root = nullptr;

    Node* insert(Node* node, int key);
    Node* deleteNode(Node* node, int key);
    void inorder(Node* node);
    bool search(Node* node, int key);

public:
    void menu() override;
};
}