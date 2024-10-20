// Document.h
#ifndef DOCUMENT_H
#define DOCUMENT_H

struct Document {
    int id;
    int license_limit;
    int borrowed_count;

    // Default constructor
    Document() : id(0), license_limit(0), borrowed_count(0) {}

    // Parameterized constructor
    Document(int docId, int limit) : id(docId), license_limit(limit), borrowed_count(0) {}
};

#endif // DOCUMENT_H
