#include <iostream>
#include <memory>

#include "../include/dsa.h"

std::unique_ptr<dsa::IDataStructure> makeDS(int choice) {
    switch (choice) {
        case 1: return std::make_unique<dsa::ArrayDS>();
        case 2: return std::make_unique<dsa::LinkedListDS>();
        case 3: return std::make_unique<dsa::StackDS>();
        case 4: return std::make_unique<dsa::QueueDS>();
        case 5: return std::make_unique<dsa::BSTDS>();
        case 6: return std::make_unique<dsa::GraphDS>();
        default: return nullptr;
    }
}

int main() {
    std::cout << "==============================\n"
                 "   DSA-Playground\n"
                 "==============================\n";

    while (true) {
        std::cout << "\nSelect a Data Structure:\n"
                     "1. Array\n2. Linked List\n3. Stack\n4. Queue\n5. Binary Search Tree\n6. Graph\n0. Exit\n> ";
        int ch; std::cin >> ch;
        if (ch == 0) break;

        auto ds = makeDS(ch);
        if (ds) ds->menu();
        else std::cout << "Invalid choice!\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}
