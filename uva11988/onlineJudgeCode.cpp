// onlineJudgeCode.cpp
// This is the code submitted to online judge.
//      This code does not need 'list.h' bc 
//      everything from list.h is in this file.

//  Jered Stevens
//  09/2/2024
//  UVA Problem 11988
//
//  To compile, navigate to working directory and make sure you
//  have the following files:
//  main.cpp    list.h    input2
//  then enter the following command into terminal
//  g++ main.cpp -o main
//
//  To run, enter the following into terminal
//  ./main < input2 > out2

#include <iostream>
#include <string>


using namespace std;
/*
    -use linked list
    -node pointer named cursor to keep track of where to insert data
    -when a bracket is found, call function cursorFront or cursorBack
        to move position of inserted data
*/


class Node {
private:
    char data;
    Node* next;
    Node* prev;

public:
    Node();                  // Default constructor
    Node(char);              // Overloaded constructor
    char getData();          // Getter for data
    Node* getNext();         // Getter for next pointer
    Node* getPrev();         // Getter for prev pointer
    void setData(char);      // Setter for data
    void setNext(Node*);     // Setter for next pointer
    void setPrev(Node*);     // Setter for prev pointer
};

// Default constructor
Node::Node() {
    data = '\0';             // \0 for null character
    next = nullptr;          // Use nullptr instead of NULL for pointers in modern C++
    prev = nullptr;
}

// overloaded constructor
Node::Node(char c) {
    data = c;
    next = nullptr;
    prev = nullptr;
}

// Getter for data
char Node::getData() {
    return data;
}

// Getter for next pointer
Node* Node::getNext() {
    return next;
}

// Getter for prev pointer
Node* Node::getPrev() {
    return prev;
}

// Setter for data
void Node::setData(char c) {
    data = c;
}

// Setter for next pointer
void Node::setNext(Node* node) {
    next = node;
}

// Setter for prev pointer
void Node::setPrev(Node* node) {
    prev = node;
}

class List {
private:
    Node* front;
    Node* back;
    Node* cursor;

public:
    List();                   // Default constructor
    List(Node*);              // Parameterized constructor
    Node* getFront();         // Getter for front
    Node* getBack();          // Getter for back
    void cursorFront();       // Move cursor to front
    void cursorBack();        // Move cursor to back
    void insertFront(char);   // Insert character at front
    void insertBack(char);    // Insert character at back
    void insertCursor(char);  // Insert character at cursor position
    void print();             // Print content in list
    void clearList();         // Delete nodes to free memory
};

// Default constructor
List::List() {
    front = nullptr;          // Use nullptr instead of NULL
    back = nullptr;
    cursor = nullptr;
}

// Parameterized constructor
List::List(Node* node) {
    front = back = cursor = node;
}

// Getter for front node
Node* List::getFront() {
    return front;
}

// Getter for back node
Node* List::getBack() {
    return back;
}

// Move cursor to the front
void List::cursorFront() {
    cursor = front;
}

// Move cursor to the back
void List::cursorBack() {
    cursor = back;
}

// Insert a new node with given char at the front
void List::insertFront(char c) {
    Node* newNode = new Node(c);
    if (front == nullptr) {
        front = back = cursor = newNode;
    } else {
        newNode->setNext(front);
        front->setPrev(newNode);
        front = newNode;
    }
}

// Insert a new node with given char at the back
void List::insertBack(char c) {
    Node* newNode = new Node(c);
    if (back == nullptr) {
        front = back = cursor = newNode;
    } else {
        newNode->setPrev(back);
        back->setNext(newNode);
        back = newNode;
    }
}

// Insert a new node with given char at the cursor position
void List::insertCursor(char c) {
    // if there is nothing in list
    Node* newNode = new Node(c);
    if (cursor == nullptr){
        front = back = cursor = newNode;
    }
    // if cursor is at the front and there are multiple items in list
    else if (cursor == front && front->getNext() != nullptr){
        newNode->setNext(front);
        front->setPrev(newNode);
        front = front->getPrev();
    }
    // if cursor is at back
    else if (cursor == back){
        back->setNext(newNode);
        newNode->setPrev(back);
        back = newNode;
        cursor = newNode;
    }
    // Everything else
    else {
        newNode->setPrev(cursor->getPrev());
        newNode->setNext(cursor);
        cursor->getPrev()->setNext(newNode);
        cursor->setPrev(newNode);
    }
}

// Print all elements in the list
void List::print() {
    Node* current = front;
    while (current != nullptr) {
        std::cout << current->getData(); // Print the data of each node
        current = current->getNext();
    }
}

// Clear the list and free all allocated memory
void List::clearList() {
    Node* current = front;
    while (current != nullptr) {
        Node* temp = current;
        current = current->getNext();
        delete temp; // Delete each node to free memory
    }
    front = back = cursor = nullptr; // Reset pointers to null
}


int main()
{
    string line;
    List list;

    while (cin >> line)
    {
        if (line.size() > 100000)
        {
            continue;
        }

        for (char i : line)
        {
            // test to know when to switch stacks
            if (i == '[')
            {
                list.cursorFront();
            }
            else if (i == ']')
            {
                list.cursorBack();
            }
            else
            {
                list.insertCursor(i);
            }
        }
        list.print();
        cout << endl;
        list.clearList();
    }
}
