#include "Stack.h"

StackNode::StackNode(string filePath) : filePath(filePath), next(nullptr) {}

FileStack::FileStack() : top(nullptr) {}

string FileStack::getFullPath(Directory* dir, const string& fileName) {
    string path = fileName;
    while (dir) {
        path = dir->name + "/" + path; 
        dir = dir->parent;  
    }
    return path;
}

void FileStack::push(string fileName, Directory* dir) {
    string fullPath = getFullPath(dir, fileName);
    StackNode* newNode = new StackNode(fullPath);
    newNode->next = top;
    top = newNode;
}

void FileStack::remove(string fileName, Directory* dir) {
    string fullPath = getFullPath(dir, fileName);
    StackNode* current = top;
    StackNode* prev = nullptr;

    while (current) {
        if (current->filePath == fullPath) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                top = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void FileStack::displayHistory() {
    if (!top) {
        cout << "No files have been added yet.\n";
        return;
    }
    cout << "\n===== File Addition History =====" << endl;
    StackNode* current = top;
    while (current) {
        cout << "File Path: " << current->filePath << endl;
        current = current->next;
    }
}

FileStack::~FileStack() {
    while (top) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }
}
