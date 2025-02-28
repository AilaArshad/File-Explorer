#pragma once
#include "File.h"

class Directory;

template <typename T>
class DLLNode {
public:
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;

    DLLNode(T data);
};

template <typename T>
class DoublyLinkedList {
private:
    DLLNode<T>* head;
    DLLNode<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertAtBeginning(T data);
    DLLNode<T>* searchByName(string name);
    void deleteByName(string name);
    void displayList();
    void updateFile(string name, string newData);
    DLLNode<T>* getHead();
};

template <typename T>
DLLNode<T>::DLLNode(T data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DLLNode<T>* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAtBeginning(T data) {
    DLLNode<T>* newNode = new DLLNode<T>(data);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
DLLNode<T>* DoublyLinkedList<T>::searchByName(string name) {
    DLLNode<T>* temp = head;
    while (temp) {
        if constexpr (is_same_v<T, File>) {
            if (temp->data.name == name) return temp;
        }
        else if constexpr (is_same_v<T, Directory>) {
            if (temp->data.name == name) return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
void DoublyLinkedList<T>::deleteByName(string name) {
    DLLNode<T>* nodeToDelete = searchByName(name);
    if (!nodeToDelete) {
        cout << "Item not found!" << endl;
        return;
    }
    if constexpr (is_same_v<T, File>) {
        if (nodeToDelete == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        }
        else if (nodeToDelete == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        }
        else {
            nodeToDelete->prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        delete nodeToDelete;
        cout << "File deleted successfully!" << endl;
    }
    else if constexpr (is_same_v<T, Directory>) {
        if (nodeToDelete == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        }
        else if (nodeToDelete == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        }
        else {
            nodeToDelete->prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
        delete nodeToDelete;
        cout << "Directory deleted successfully!" << endl;
    }
}


template <typename T>
void DoublyLinkedList<T>::displayList() {
    DLLNode<T>* temp = head;
    while (temp) {
        if constexpr (is_same_v<T, File>) {
            temp->data.displayFileInfo();
        }
        else if constexpr (is_same_v<T, Directory>) {
            temp->data.displayDirectoryInfo();
        }
        temp = temp->next;
    }
}

template <typename T>
DLLNode<T>* DoublyLinkedList<T>::getHead() {
    return head;
}

template <typename T>
void DoublyLinkedList<T>::updateFile(string name, string newData) {
    if constexpr (is_same_v<T, File>) {
        DLLNode<T>* fileNode = searchByName(name);
        if (!fileNode) {
            cout << "File not found!\n";
            return;
        }

        fileNode->data.data += newData;
        fileNode->data.size = fileNode->data.data.length() / 1024.0;
        fileNode->data.lastModificationDate = Date();

        cout << "File updated successfully!\n";
    }
    else {
        cout << "Update operation is only allowed for Files!" << endl;
    }
}
