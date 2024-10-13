#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

template<typename T>
class Heap {
    private:
        typedef std::vector<T> heap;
        typedef heap::size_type heapIndex;
        heap tree;
        
        heapIndex getLeftChildPosition(heapIndex i) {
            return (2 * i);
        }
        
        heapIndex getRightChildPosition(heapIndex i) {
            return (2 * i) + 1;
        }
        
        heapIndex getParentPosition(heapIndex i) {
            return (heapIndex) std::floor(i / 2);
        }

        heapIndex heapifyDown(heapIndex index) {
            heapIndex leftChildIndex = this->getLeftChildPosition(index);
            T leftChild = (leftChildIndex < this->tree.size()) ? this->tree.at(leftChildIndex) : std::numeric_limits<T>::min();
            
            heapIndex rightChildIndex = this->getRightChildPosition(index);
            T rightChild = (rightChildIndex < this->tree.size()) ? this->tree.at(rightChildIndex) : std::numeric_limits<T>::min();
            
            heapIndex minValueChildIndex = (leftChild < rightChild) ? leftChildIndex : rightChildIndex;
            
            if (minValueChildIndex < this->tree.size()) {
                if (this->tree.at(minValueChildIndex) < this->tree.at(index)) {
                    std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
                    this->heapifyDown(minValueChildIndex);
                    return minValueChildIndex;
                }
            }
            return this->tree.size();
        }
    
    public:
        Heap() {
            this->tree.push_back((T) NULL);
        }
        
        Heap(std::vector<T> tree) {
            this->heapify(tree);
        }

        bool isHeapEmpty() {
            return this->tree.size() <= 1;
        }
        
        void printHeap() {
            this->printVector(this->tree);
        }
        
        void heapify(std::vector<T> tree) {
            tree.insert(tree.begin(), (T) NULL);
            this->tree = tree;
            for (heapIndex index = this->tree.size() - 1; index >= 1; index--) {
                this->heapifyDown(index);
            }
        }
        
        void printVector(std::vector<T> numVector) {
            std::cout << "[ ";
            for (heapIndex index = 0; index < numVector.size(); index++) {
                if (numVector.at(index) != (T) NULL) {
                    std::cout << numVector.at(index);
                    if (index != (numVector.size() - 1)) {
                        std::cout << ", ";
                    }
                }
            }
            std:: cout << " ]" << std::endl;
        }
        
        T popTop() {
            if (this->isHeapEmpty()) {
                return std::numeric_limits<T>::min();
            }
            const heapIndex ROOT_INDEX = 1;
            T topElement = this->tree.at(ROOT_INDEX);
            this->tree.at(ROOT_INDEX) = this->tree.at(this->tree.size() - 1);
            this->tree.pop_back();
            heapIndex parent = ROOT_INDEX;
            this->heapifyDown(parent);
            return topElement;
        }
        
        std::vector<T> heapSort(std::vector<T> numList) {
            Heap<T> tree1;
            for (typename std::vector<T>::size_type index = 0; index < numList.size(); index++) {
                tree1.insert(numList[index]);
            }
            
            std::vector<T> sortedNumList;
            while (!tree1.isHeapEmpty()) {
                sortedNumList.push_back(tree1.popTop());
            }
            return sortedNumList;
        }
        
        // Insert an element into the heap
        void insert(T element) {
            this->tree.push_back(element);
            heapIndex index = this->tree.size() - 1;
            heapIndex parentIndex = getParentPosition(index);
            
            while (index > 1 && this->tree.at(parentIndex) > this->tree.at(index)) {
                std::swap(this->tree.at(parentIndex), this->tree.at(index));
                index = parentIndex;
                parentIndex = getParentPosition(index);
            }
        }
        
        // Remove an element from the heap
        void remove(T value) {
            if (this->isHeapEmpty()) return;
            
            heapIndex index = 0;
            for (heapIndex i = 1; i < this->tree.size(); i++) {
                if (this->tree.at(i) == value) {
                    index = i;
                    break;
                }
            }

            if (index == 0) return;
            
            this->tree.at(index) = this->tree.back();
            this->tree.pop_back();
            heapifyDown(index);
        }
        
        // Get the minimum element (the root of the heap)
        T getMin() {
            if (this->isHeapEmpty()) {
                return std::numeric_limits<T>::min();
            }
            return this->tree.at(1);
        }
};

#endif 
