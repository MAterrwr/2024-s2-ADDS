#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node* link;

    Node(int val) : data(val), link(nullptr) {}
};

#endif
