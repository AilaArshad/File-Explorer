#pragma once
#include "DLL.h"
#include "file.h"
#include "Date.h"

class Directory {
public:
    string name;
    Date lastModificationDate;
    DoublyLinkedList<File> files;
    DoublyLinkedList<Directory> subdirectories;
    Directory* parent;

    Directory(string name, Directory* parent = nullptr);

    void displayDirectoryInfo();


};