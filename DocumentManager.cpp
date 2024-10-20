// DocumentManager.cpp
#include "Document.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

class DocumentManager {
private:
    // Maps document name to Document object
    std::unordered_map<std::string, Document> documents;
    
    // Stores registered patron IDs
    std::unordered_set<int> patrons;
    
    // Maps document ID to the set of patron IDs who have borrowed the document
    std::unordered_map<int, std::unordered_set<int>> borrowedDocs;

public:
    void addDocument(std::string name, int id, int license_limit) {
        documents[name] = Document(id, license_limit);
    }

    void addPatron(int patronID) {
        patrons.insert(patronID);
    }

    int search(std::string name) {
        if (documents.find(name) != documents.end()) {
            return documents[name].id;
        }
        return 0;
    }

    bool borrowDocument(int docid, int patronID) {
        if (patrons.find(patronID) == patrons.end()) {
            return false;
        }

        for (const auto& pair : documents) {
            if (pair.second.id == docid) {
                Document& doc = documents[pair.first];
                if (doc.borrowed_count < doc.license_limit) {
                    if (borrowedDocs[docid].find(patronID) == borrowedDocs[docid].end()) {
                        doc.borrowed_count++;
                        borrowedDocs[docid].insert(patronID);
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }

    void returnDocument(int docid, int patronID) {
        if (borrowedDocs.find(docid) != borrowedDocs.end()) {
            if (borrowedDocs[docid].find(patronID) != borrowedDocs[docid].end()) {
                borrowedDocs[docid].erase(patronID);
                documents.begin()->second.borrowed_count--;
            }
        }
    }
};
