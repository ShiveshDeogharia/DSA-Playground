#pragma once
#include "interface.h"
#include <iostream>

namespace dsa {

class LinkedListDS : public IDataStructure {
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };

    Node* head = nullptr;

public:
    // Core operations for testability
    void push_front(int v);
    void push_back(int v);
    bool delete_value(int v);
    int search(int v) const;
    int size() const;
    int get(int index) const;

    void menu() override;
    ~LinkedListDS();
};

}
