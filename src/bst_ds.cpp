#include "bst_ds.h"
namespace dsa{
BSTDS::Node* BSTDS::insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key) node->l = insert(node->l, key);
    else node->r = insert(node->r, key);
    return node;
}

BSTDS::Node* BSTDS::deleteNode(Node* node, int key) {
    if (!node) return nullptr;
    if (key < node->key) {
        node->l = deleteNode(node->l, key);
    } else if (key > node->key) {
        node->r = deleteNode(node->r, key);
    } else {
        if (!node->l) {
            Node* temp = node->r;
            delete node;
            return temp;
        } else if (!node->r) {
            Node* temp = node->l;
            delete node;
            return temp;
        } else {
            Node* succ = node->r;
            while (succ->l) succ = succ->l;
            node->key = succ->key;
            node->r = deleteNode(node->r, succ->key);
        }
    }
    return node;
}

void BSTDS::inorder(Node* node) {
    if (!node) return;
    inorder(node->l);
    std::cout << node->key << ' ';
    inorder(node->r);
}

bool BSTDS::search(Node* node, int key) {
    if (!node) return false;
    if (key == node->key) return true;
    if (key < node->key) return search(node->l, key);
    return search(node->r, key);
}

void BSTDS::menu() {
    while (true) {
        std::cout << "\n— BST Operations —\n1. Insert\n2. In-order Traversal\n3. Search\n4. Delete\n0. Return\n> ";
        int c; std::cin >> c;
        if (c == 0) break;
        switch (c) {
            case 1: {
                int k; std::cout << "Key: "; std::cin >> k;
                root = insert(root, k);
                break;
            }
            case 2: {
                inorder(root); std::cout << "\n";
                break;
            }
            case 3: {
                int k; std::cout << "Key to search: "; std::cin >> k;
                if (search(root, k)) std::cout << "Found\n";
                else std::cout << "Not found\n";
                break;
            }
            case 4: {
                int k; std::cout << "Key to delete: "; std::cin >> k;
                root = deleteNode(root, k);
                break;
            }
            default:
                std::cout << "Invalid\n";
        }
    }
}
}