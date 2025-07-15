#include "linked_list_ds.h"

namespace dsa {

void LinkedListDS::push_front(int v) {
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void LinkedListDS::push_back(int v) {
    if (!head) {
        head = new Node(v);
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Node(v);
}

bool LinkedListDS::delete_value(int value) {
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
    return false;
}

int LinkedListDS::search(int value) const {
    Node* cur = head;
    int index = 0;
    while (cur) {
        if (cur->data == value) return index;
        cur = cur->next;
        ++index;
    }
    return -1;
}

int LinkedListDS::get(int index) const {
    Node* cur = head;
    int count = 0;
    while (cur) {
        if (count == index) return cur->data;
        cur = cur->next;
        ++count;
    }
    throw std::out_of_range("Index out of range");
}

int LinkedListDS::size() const {
    int count = 0;
    Node* cur = head;
    while (cur) {
        ++count;
        cur = cur->next;
    }
    return count;
}

LinkedListDS::~LinkedListDS() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}
void dsa::LinkedListDS::menu() {
    std::cout << "LinkedListDS::menu() not tested in unit tests.\n";
}


}
