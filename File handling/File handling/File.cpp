#include "File.h"

File::File(string name, string extension, string data)
    : name(name), extension(extension), data(data) {
    size = data.length() / 1024.0, lastModificationDate = Date();
}


void File::displayFileInfo() {
    cout << "File: " << name << "." << extension << " | Size: "
        << size << " KB | Last Modified: ";
    lastModificationDate.printDate();
    cout << endl;
}
