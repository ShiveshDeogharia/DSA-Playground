#include "linked_list_ds.h"
namespace dsa{
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

bool LinkedListDS::deleteValue(int value) {
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

int LinkedListDS::search(int value) const {
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

void LinkedListDS::print() const {
    Node* cur = head;
    std::cout << "head -> ";
    while (cur) {
        std::cout << cur->data << " -> ";
        cur = cur->next;
    }
    std::cout << "NULL\n";
}

void LinkedListDS::menu() {
    while (true) {
        std::cout << "\n— Linked List Operations —\n";
        std::cout << "1. Push Front\n2. Push Back\n3. Display\n4. Delete Value\n5. Search Value\n0. Return\n> ";
        int c; std::cin >> c;
        if (c == 0) break;
        switch (c) {
            case 1: {
                int v; std::cout << "Value: "; std::cin >> v; push_front(v); break;
            }
            case 2: {
                int v; std::cout << "Value: "; std::cin >> v; push_back(v); break;
            }
            case 3: print(); break;
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
            default: std::cout << "Invalid option\n";
        }
    }
}

LinkedListDS::~LinkedListDS() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
}
}