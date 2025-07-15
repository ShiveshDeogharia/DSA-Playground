#pragma once
#include "interface.h"
#include <iostream>
namespace dsa{
class LinkedListDS : public IDataStructure {
    struct Node {
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };

    Node* head = nullptr;

    void push_front(int v);
    void push_back(int v);
    bool deleteValue(int value);
    int search(int value) const;
    void print() const;

public:
    void menu() override;
    ~LinkedListDS();
};
}