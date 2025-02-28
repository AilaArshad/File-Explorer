#pragma once
#include "Directory.h"
class StackNode {
public:
    string filePath;  
    StackNode* next;

    StackNode(string filePath);
};

class FileStack {
private:
    StackNode* top;
    string getFullPath(Directory* dir, const string& fileName); 
public:
    FileStack();
    void push(string fileName, Directory* dir);
    void remove(string fileName, Directory* dir);
    void displayHistory();
    ~FileStack();
};
