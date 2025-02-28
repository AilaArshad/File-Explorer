#pragma once
#include "File.h"
#include "Directory.h"

class Node {
public:
    Directory data;
    Node* left;
    Node* right;

    Node(Directory data);
};

class BST {
public:
    Node* root;

    BST();
    ~BST();
    void executeCommand(string& input);
    Node* insert(Node* root, Directory data);
    Node* search(Node* root, string& name);
    Node* deleteNode(Node* root, string& name);
    Node* findMin(Node* root);
    void inorderTraversal(Node* root);
    void destroyTree(Node* root);
    void manageDirectory(Directory& dir);
};
