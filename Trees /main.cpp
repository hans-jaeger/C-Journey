/*
Author: Hans Jaeger
Date: March 8, 2024
Assignment: Binary Tree Program in C++ with the operations of inorder(), preorder(), and postorder().
*/

#include <iostream>

using namespace std;

class BinaryTree
{
private:
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;

        BinaryTree *tree;
        // Constructor:
        Node(int val, Node *leftChild = nullptr, Node *rightChild = nullptr)
        {
            value = val;
            left = leftChild;
            right = rightChild;
        }
    };

public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    // Insert a value into the binary tree
    Node *insertRecursive(Node *current, int val)
    {
        // If the current node is null, create a new node with the given value.
        if (current == nullptr)
        {
            return new Node(val);
        }

        // Decide whether to insert the value in the left or right subtree.
        if (val < current->value)
        {
            current->left = insertRecursive(current->left, val);
        }
        else
        {
            current->right = insertRecursive(current->right, val);
        }

        return current;
    }

    // Public insert method
    void insert(int val)
    {
        // Create an anchor point at the root for inserting a new value.
        root = insertRecursive(root, val);
    }

    // Inorder Traversal:
    // 1. Traverse the left subtree.
    // 2. Visit the root node and print its value.
    // 3. Traverse the right subtree.
    void printInorder(Node *node)
    {
        if (node == NULL)
            return;
        // Recursively traverse the left subtree.
        printInorder(node->left);

        cout << node->value << " ";
        // Recursively traverse the right subtree.
        printInorder(node->right);
    }

    // Preorder Traversal:
    // 1. Visit the root node and print its value.
    // 2. Traverse the left subtree.
    // 3. Traverse the right subtree.
    void printPreOrder(Node *node)
    {
        if (node == NULL)
            return;

        cout << node->value << " ";
        // Recursively traverse the left subtree.
        printPreOrder(node->left);
        // Recursively traverse the right subtree.
        printPreOrder(node->right);
    }

    // Postorder Traversal:
    // 1. Traverse the left subtree.
    // 2. Traverse the right subtree.
    // 3. Visit the root node and print its value.
    void printPostOrder(Node *node)
    {
        if (node == NULL)
            return;
        // Recursively traverse the left subtree.
        printPostOrder(node->left);
        // Recursively traverse the right subtree.
        printPostOrder(node->right);

        cout << node->value << " ";
    }
};

int main()
{
    BinaryTree tree;
    // Example usage:
    tree.insert(100);
    tree.insert(20);
    tree.insert(200);
    tree.insert(10);
    tree.insert(30);
    tree.insert(150);
    tree.insert(300);

    cout << "Inorder Traversal: ";
    tree.printInorder(tree.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.printPreOrder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.printPostOrder(tree.root);
    cout << endl;

    return 0;
}
