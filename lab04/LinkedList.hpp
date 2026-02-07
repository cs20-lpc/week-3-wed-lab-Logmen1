#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList : public List<T> {
    protected:
        // represents an element in the linked list
        struct Node {
            T value;
            Node* next;

            Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) { }
        };

        // a pointer to the front of the list
        Node* head;

    public:
        // default constructor
        LinkedList();

        // destructor
        virtual ~LinkedList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list, resetting to the initial state
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override { }

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // remove the element at the given position (argument)
        virtual void remove(int) override { }

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const LinkedList<U>&);
};

template <typename T>
LinkedList<T>::LinkedList()
    : head(nullptr) {
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
    Node* NewNode = new Node;
    NewNode->value = elem;
    NewNode->next = nullptr;

    if (!head) {
        head = NewNode;
    }

    else {
        Node* traveler = head;
        while (traveler->next != nullptr) {
            traveler = traveler->next;
        }
        traveler->next = NewNode;
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    Node* traveler = head;
    while (traveler != nullptr) {
        Node* temp = traveler;
        traveler = traveler->next;
        delete temp;
    }

    head = nullptr;
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    if (this->isEmpty()) {
        throw string("List is empty, no elements to return\n");
    }

    if (position < 0 || position >= this->length) {
        throw string("Index out of bounds");
    }
    Node* traveler = head;
    for (int i = 0; i < position; i++) {
        traveler = traveler->next;
    }

    return traveler->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    if (this->isEmpty()) {
        throw string("List is empty, no elements to replace.\n");
    }

    if (position < 0 || position >= this->length) {
        throw string("Index out of bounds");
    }
    Node* traveler = head;
    for (int i = 0; i < position; i++) {
        traveler = traveler->next;
    }

    traveler->value = elem;
}


template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}

#endif

#endif
