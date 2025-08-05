#include <iostream>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if(!node) return new Node(val);
        if(node->val > val) {
            node->left = insert(node->left, val);
        }
        else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while(node->left) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int val) {
        if(!node) return nullptr;
        if(node->val > val) {
            node->left = remove(node->left, val);
        }
        else if(node->val < val) {
            node->right = remove(node->right, val);
        }
        else {
            if(!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            else if(!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* minNode = findMin(node->right);
            node->val = minNode->val;
            node->right = remove(node->right, minNode->val);
        }
        return node;
    }

    bool search(Node* node, int val) {
        if(!node) return false;
        if(node->val > val) {
            return search(node->left, val);
        }
        else if(node->val < val) {
            return search(node->right, val);
        }
        else {
            return true;
        }
    }

    void destroy(Node* node) {
        if(!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    void printInorder(Node* node) {
        if(!node) return;
        printInorder(node->left);
        std::cout << node->val << " ";
        printInorder(node->right);
    }

public:
    BST() : root(nullptr) {}
    explicit BST(int val) : root(new Node(val)) {}
    ~BST() {
        destroy(root);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    void printInorder() {
        printInorder(root);
        std::cout << std::endl;
    }
    
};
