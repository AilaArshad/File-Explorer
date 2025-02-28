#include "BST.h"
#include "Stack.h"

FileStack filestack;

Node::Node(Directory data)
    : data(data), left(nullptr), right(nullptr) {
}

BST::BST() : root(nullptr) {}

BST::~BST() {
    destroyTree(root);
}

void BST::destroyTree(Node* root) {
    if (root) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

Node* BST::insert(Node* root, Directory data) {
    if (!root)
        return new Node(data);

    if (data.name < root->data.name)
        root->left = insert(root->left, data);
    else if (data.name > root->data.name)
        root->right = insert(root->right, data);

    return root;
}

Node* BST::search(Node* root, string& name) {
    if (!root || root->data.name == name)
        return root;

    if (name < root->data.name)
        return search(root->left, name);

    return search(root->right, name);
}

Node* BST::findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* BST::deleteNode(Node* root, string& name) {
    if (!root) {
        cout << "Directory Not Found! Cannot delete." << endl;
        return root;
    }

    if (name < root->data.name)
        root->left = deleteNode(root->left, name);
    else if (name > root->data.name)
        root->right = deleteNode(root->right, name);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.name);
    }
    return root;
}

void BST::inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        root->data.displayDirectoryInfo();
        inorderTraversal(root->right);
    }
}

void BST::executeCommand(string& input) {
  
    string command = input.substr(0, input.find(' '));
    string name = input.substr(input.find(' ') + 1);
    name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());
    
    if (command == "cr") {
        Node* found = search(root, name);
        if (found) {
            int count = 1;
            string newName;
            do {
                newName = name + "(" + to_string(count) + ")";
                found = search(root, newName);
                count++;
            } while (found);

            cout << "Directory already exists! Renaming to: " << newName << endl;
            root = insert(root, Directory(newName));
        }
        else {
            cout << "Creating Directory: " << name << endl;
            root = insert(root, Directory(name));
        }
    }
    else if (command == "cd") {
        cout << "Searching for Directory: " << name << endl;
        Node* found = search(root, name);
        if (found) {
            cout << "Directory Found: " << name << endl;
        }
        else {
            cout << "Directory Not Found!" << endl;
        }
    }
    else if (command == "open") {
        cout << "Opening Directory: " << name << endl;
        Node* found = search(root, name);
        if (found) {
            found->data.displayDirectoryInfo();
            manageDirectory(found->data);
            cin.ignore();
        }
        else {
            cout << "Directory Not Found!" << endl;
        }
    }
    else if (command == "free") {
        cout << "Deleting Directory: " << name << endl;
        Node* found = search(root, name);
        if (found) {
            root = deleteNode(root, name);
        }
        else {
            cout << "Directory Not Found! Cannot delete." << endl;
        }
    }
    else if (command == "dir") {
        cout << "Displaying All Directories:\n";
        inorderTraversal(root);
    }
    else if (command == "exit") {
        cout << "Exiting Program..." << endl;
        exit(0);
    }
    else if (command == "history") {
        filestack.displayHistory();
    }
    else {
        cout << "Invalid Command!" << endl;
    }

}
void BST::manageDirectory(Directory& dir) {
    int choice;
    string name, extension, data;

    do {
        
        cout << "\n===== Managing Directory: " << dir.name << " =====" << endl;
        cout << "1. Create File" << endl;
        cout << "2. Create Subdirectory" << endl;
        cout << "3. Search File" << endl;
        cout << "4. Search Subdirectory" << endl;
        cout << "5. Delete File" << endl;
        cout << "6. Delete Subdirectory" << endl;
        cout << "7. Display All Files" << endl;
        cout << "8. Display All Subdirectories" << endl;
        cout << "9. Update File" << endl;
        cout << "10. Open Subdirectory" << endl;
        cout << "11. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter File Name: ";
            cin >> name;
            DLLNode<File>* file = dir.files.searchByName(name);
            if (file) {
                cout << "File already exist!\n";
            }
            else {
                cout << "Enter File Extension: ";
                cin >> extension;
                cout << "Enter File Data: ";
                cin.ignore();
                getline(cin, data);
                dir.files.insertAtBeginning(File(name, extension, data));
                filestack.push(name, &dir);
                cout << "File Created Successfully!\n";
            }
        }
            break;

        case 2: {
            cout << "Enter Subdirectory Name: ";
            cin >> name;
            DLLNode<Directory>* subDirNode = dir.subdirectories.searchByName(name);
            if (subDirNode) {
                int count = 1;
                string newName;
                do {
                    newName = name + "(" + to_string(count) + ")";
                    subDirNode = dir.subdirectories.searchByName(newName);
                    count++;
                } while (subDirNode);

                cout << "Directory already exists! Renaming to: " << newName << endl;
                dir.subdirectories.insertAtBeginning(Directory(newName, &dir));
                cout << "Subdirectory Created Successfully!\n";
            }
            else {
                cout << "Creating Directory: " << name << endl;
                dir.subdirectories.insertAtBeginning(Directory(name, &dir));
                cout << "Subdirectory Created Successfully!\n";
            }
        }
            break;

        case 3:
            cout << "Enter File Name to Search: ";
            cin >> name;
            cout << (dir.files.searchByName(name) ? "File Found!\n" : "File Not Found!\n");
            break;

        case 4:
            cout << "Enter Subdirectory Name to Search: ";
            cin >> name;
            cout << (dir.subdirectories.searchByName(name) ? "Subdirectory Found!\n" : "Subdirectory Not Found!\n");
            break;

        case 5:
            cout << "Enter File Name to Delete: ";
            cin >> name;
            dir.files.deleteByName(name);
            filestack.remove(name, &dir);
            break;

        case 6:
            cout << "Enter Subdirectory Name to Delete: ";
            cin >> name;
            dir.subdirectories.deleteByName(name);
            break;

        case 7:
            if (dir.files.getHead() == nullptr) {
                cout << "No files available." << endl;
            }
            else {
                dir.files.displayList();
            }
            break;

        case 8:
            if (dir.subdirectories.getHead() == nullptr) {
                cout << "No subdirectories available." << endl;
            }
            else {
                dir.files.displayList();
            }
            dir.subdirectories.displayList();
            break;

        case 9:
            cout << "Enter File Name to Update: ";
            cin >> name;
            if (DLLNode<File>* subDirNode = dir.files.searchByName(name)) {
                cout << "Enter New File Data: ";
                cin.ignore();
                getline(cin, data);
                dir.files.updateFile(name, data);
            }
            else {
                cout << "File Not Found!\n";
            }
            break;

        case 10:
            cout << "Enter Subdirectory Name to Open: ";
            cin >> name;
            if (DLLNode<Directory>* subDirNode = dir.subdirectories.searchByName(name)) {
                manageDirectory(subDirNode->data);
            }
            else {
                cout << "Subdirectory Not Found!\n";
            }
            break;
        case 11:
            cout << "Returning to Main Menu...\n";
            return;
        }

    } while (choice != 11);
}
