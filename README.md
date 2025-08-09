# File Explorer – C++

**File Explorer** is a C++ application designed to help users navigate, manage, and interact with files and directories efficiently through a console-based interface.
It was built as a practice project to strengthen **Data Structures & Algorithms (DSA)** concepts while implementing real-world file system operations.

---

## 📖 Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Technology Stack](#technology-stack)
4. [Usage Guide](#usage-guide)
5. [Future Enhancements](#future-enhancements)

---

## 1. Overview

The **File Explorer in C++** simulates a simplified version of a desktop file explorer, enabling users to:

* View directory contents
* Search for files or folders
* Create and delete directories
* Open and manage files

The project applies **core DSA principles** such as stacks, queues, linked lists, and tree traversal to replicate file system navigation logic.

---

## 2. Features

### **Directory Navigation**

* View the current working directory path.
* List all files and subdirectories.
* Navigate into subfolders or go back to the parent directory.

### **File & Folder Operations**

* Create a new folder.
* Delete a folder or file.
* Rename files or directories.

### **Search Functionality**

* Search for files by name within the current directory or recursively in all subdirectories.

### **File Interaction**

* Open and display file content (for text-based files).
* Create new files.

---

## 3. Technology Stack

| Component       | Technology Used                                   |
| --------------- | ------------------------------------------------- |
| **Language**    | C++                                               |
| **Standard**    | C++11 / C++14 / C++17                             |
| **Libraries**   | `<iostream>` (C++17) |
| **Environment** | Visual Studio Code                                |

---

## 4. Usage Guide

* **List Directory Contents**: The application displays all files/folders in the current directory.
* **Navigate Folders**: Enter a folder name to open it, or `..` to move to the parent directory.
* **Create Folder**: Choose the "Create Folder" option and provide a name.
* **Delete File/Folder**: Select "Delete" and specify the file/folder name.
* **Search**: Enter a filename to search in the current directory or recursively.

---

## 5. Future Enhancements

* Graphical User Interface (GUI) version.
* File copy/move operations.
* Support for more file types and binary file reading.
* Multi-threaded search for faster performance.

