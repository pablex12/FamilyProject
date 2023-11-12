#ifndef HEAP_H
#define HEAP_H
#include "../Person/person.h"
#include <iostream>
class HeapTree
{
private:
    Person heap[sizeof(Person) * 14];
    int size;
    bool isMaxHeap;

    void heapifyUp(int index, int feature);
    void heapifyDown(int index, int feature);

public:
    HeapTree(bool isMax);

    void insert(Person person, int feature);
    void deleteRoot();
    void display(int feature);
    int getFeatureCode(const std::string &feature);
    Person getExtremumFeaturePerson(int feature, bool isMax);
};

#endif // HEAP_TREE_H