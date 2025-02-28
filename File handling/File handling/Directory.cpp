#include "Directory.h"

Directory::Directory(string name, Directory* parent) : name(name), parent(parent) {}


void Directory::displayDirectoryInfo() {
    cout << "\nDirectory: " << name << endl;
    cout << "Last Modified: " << lastModificationDate.day << "/"
        << lastModificationDate.month << "/" << lastModificationDate.year << endl;
}


