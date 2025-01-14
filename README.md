# 4D Notepad Data Structures

## Overview
This project is a C++ implementation of a notepad application with all the basic text editing functionalities. It utilizes 4 Dimension linked lists and queues to manage text data and operations efficiently.

## Features
- **Open Notepad:** Allows users to input text into the notepad.
- **Delete Text:** Enables users to delete specific text from the notepad.
- **Copy Text:** Copies selected text from the notepad for pasting elsewhere.
- **Paste Text:** Pastes copied text into the notepad at a specified location.
- **Find Text:** Searches for specific text within the notepad.
- **Replace Text:** Replaces occurrences of specific text with another text within the notepad.
- **Undo Text:** Reverts recent changes made to the text in the notepad.
- **View Notepad:** Displays the content of the notepad.
- **Count Total Words:** Calculates and displays the total number of words in the notepad.

## Approach
The linked list approach is utilized to manage the text data in the notepad efficiently. Here's how it works:
- **Node Class (`node`):** Represents each word or segment of text in the notepad. Each node contains text data and pointers to the next, previous, up, and down nodes, forming a 4D linked list structure.
- **Inserting Text:** Text data is inserted into the linked list by creating new nodes and connecting them appropriately using the `open_insert_txt_1` function.
- **Deleting Text:** Text can be deleted from the notepad by removing nodes from the linked list using the `delete_txt_2` function.
- **Traversing the Linked List:** The linked list is traversed to perform various operations such as displaying the content of the notepad and counting the total number of words.
- **Linked List Structure:** The linked list structure maintains the order of text data and facilitates efficient insertion and deletion operations.

## Usage
1. Upon launching the application, a main menu will be displayed with various options.
2. Choose an option by entering the corresponding number and follow the on-screen instructions.
3. Perform text editing operations as prompted.
4. Use option "0" to exit the application.

## Dependencies
- This project relies on standard C++ libraries and does not have any external dependencies.

## Contributors
- [Saad Abdur Razzaq](https://github.com/saadarazzaq)
