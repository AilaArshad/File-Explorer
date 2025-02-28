#pragma once
#include "Date.h" 

class File {
public:
    string name;
    string data;
    string extension;
    double size;
    Date lastModificationDate;


    File(string name, string extension, string data);

    void displayFileInfo();

};