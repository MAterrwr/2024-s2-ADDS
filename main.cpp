// main.cpp
#include "DocumentManager.cpp"

int main() {
    DocumentManager manager;

    manager.addDocument("Document1", 1, 3);
    manager.addDocument("Document2", 2, 2);

    manager.addPatron(101);
    manager.addPatron(102);

    if (manager.borrowDocument(1, 101)) {
        std::cout << "Patron 101 borrowed Document1 successfully.\n";
    } else {
        std::cout << "Patron 101 failed to borrow Document1.\n";
    }

    manager.returnDocument(1, 101);
    std::cout << "Patron 101 returned Document1.\n";

    return 0;
}
