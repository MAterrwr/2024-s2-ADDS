#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->link;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum);
    if (pos <= 1 || !head) {
        newNode->link = head;
        head = newNode;
    } else {
        Node* current = head;
        int index = 1;
        while (current->link && index < pos - 1) {
            current = current->link;
            index++;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
}

bool LinkedList::deletePosition(int pos) {
    if (!head) return false;
    
    Node* temp;
    if (pos == 1) {
        temp = head;
        head = head->link;
        delete temp;
        return true;
    }
    
    Node* current = head;
    int index = 1;
    while (current->link && index < pos - 1) {
        current = current->link;
        index++;
    }
    
    if (!current->link) return false;
    
    temp = current->link;
    current->link = temp->link;
    delete temp;
    return true;
}

int LinkedList::get(int pos) {
    Node* current = head;
    int index = 1;
    
    while (current && index < pos) {
        current = current->link;
        index++;
    }
    
    if (current) {
        return current->data;
    } else {
        return std::numeric_limits<int>::max();
    }
}

int LinkedList::search(int target) {
    Node* current = head;
    int index = 1;
    
    while (current) {
        if (current->data == target) {
            return index;
        }
        current = current->link;
        index++;
    }
    return -1;
}

void LinkedList::printList() {
    if (!head) return;
    
    Node* current = head;
    std::cout << "[";
    while (current) {
        std::cout << current->data;
        if (current->link) std::cout << " ";
        current = current->link;
    }
    std::cout << "]";
}
