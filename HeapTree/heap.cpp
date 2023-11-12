#include "heap.h"
#include <iostream>

using namespace std;

HeapTree::HeapTree(bool isMax) : size(0), isMaxHeap(isMax) {}

void HeapTree::heapifyUp(int index, int feature)
{
    int parent = (index - 1) / 2;

    if (index > 0)
    {
        switch (feature)
        {
        case 1: // Edad
            if ((isMaxHeap && heap[index].getAge() > heap[parent].getAge()) || (!isMaxHeap && heap[index].getAge() < heap[parent].getAge()))
            {
                swap(heap[index], heap[parent]);
                heapifyUp(parent, feature);
            }
            break;
        case 2: // Ahorros
            if ((isMaxHeap && heap[index].getSavings() > heap[parent].getSavings()) || (!isMaxHeap && heap[index].getSavings() < heap[parent].getSavings()))
            {
                swap(heap[index], heap[parent]);
                heapifyUp(parent, feature);
            }
            break;
        case 3: // Ataque
            if ((isMaxHeap && heap[index].getAttack() > heap[parent].getAttack()) || (!isMaxHeap && heap[index].getAttack() < heap[parent].getAttack()))
            {
                swap(heap[index], heap[parent]);
                heapifyUp(parent, feature);
            }
            break;
        case 4: // Defensa
            if ((isMaxHeap && heap[index].getDefense() > heap[parent].getDefense()) || (!isMaxHeap && heap[index].getDefense() < heap[parent].getDefense()))
            {
                swap(heap[index], heap[parent]);
                heapifyUp(parent, feature);
            }
            break;
        case 5: // Sabiduría
            if ((isMaxHeap && heap[index].getWisdom() > heap[parent].getWisdom()) || (!isMaxHeap && heap[index].getWisdom() < heap[parent].getWisdom()))
            {
                swap(heap[index], heap[parent]);
                heapifyUp(parent, feature);
            }
            break;
        default:
            break;
        }
    }
}

void HeapTree::heapifyDown(int index, int feature)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int extreme = index;

    if (left < size)
    {
        switch (feature)
        {
        case 1: // Edad
            if ((isMaxHeap && heap[left].getAge() > heap[extreme].getAge()) || (!isMaxHeap && heap[left].getAge() < heap[extreme].getAge()))
            {
                extreme = left;
            }
            break;
        case 2: // Ahorros
            if ((isMaxHeap && heap[left].getSavings() > heap[extreme].getSavings()) || (!isMaxHeap && heap[left].getSavings() < heap[extreme].getSavings()))
            {
                extreme = left;
            }
            break;
        case 3: // Ataque
            if ((isMaxHeap && heap[left].getAttack() > heap[extreme].getAttack()) || (!isMaxHeap && heap[left].getAttack() < heap[extreme].getAttack()))
            {
                extreme = left;
            }
            break;
        case 4: // Defensa
            if ((isMaxHeap && heap[left].getDefense() > heap[extreme].getDefense()) || (!isMaxHeap && heap[left].getDefense() < heap[extreme].getDefense()))
            {
                extreme = left;
            }
            break;
        case 5: // Sabiduría
            if ((isMaxHeap && heap[left].getWisdom() > heap[extreme].getWisdom()) || (!isMaxHeap && heap[left].getWisdom() < heap[extreme].getWisdom()))
            {
                extreme = left;
            }
            break;
        default:
            break;
        }
    }

    if (right < size)
    {
        switch (feature)
        {
        case 1: // Edad
            if ((isMaxHeap && heap[right].getAge() > heap[extreme].getAge()) || (!isMaxHeap && heap[right].getAge() < heap[extreme].getAge()))
            {
                extreme = right;
            }
            break;
        case 2: // Ahorros
            if ((isMaxHeap && heap[right].getSavings() > heap[extreme].getSavings()) || (!isMaxHeap && heap[right].getSavings() < heap[extreme].getSavings()))
            {
                extreme = right;
            }
            break;
        case 3: // Ataque
            if ((isMaxHeap && heap[right].getAttack() > heap[extreme].getAttack()) || (!isMaxHeap && heap[right].getAttack() < heap[extreme].getAttack()))
            {
                extreme = right;
            }
            break;
        case 4: // Defensa
            if ((isMaxHeap && heap[right].getDefense() > heap[extreme].getDefense()) || (!isMaxHeap && heap[right].getDefense() < heap[extreme].getDefense()))
            {
                extreme = right;
            }
            break;
        case 5: // Sabiduría
            if ((isMaxHeap && heap[right].getWisdom() > heap[extreme].getWisdom()) || (!isMaxHeap && heap[right].getWisdom() < heap[extreme].getWisdom()))
            {
                extreme = right;
            }
            break;
        default:
            break;
        }
    }

    if (extreme != index)
    {
        swap(heap[index], heap[extreme]);
        heapifyDown(extreme, feature);
    }
}
void HeapTree::insert(Person person, int feature)
{
    if (size >= 14)
    {
        cout << "El montículo está lleno" << endl;
        return;
    }

    heap[size] = person;
    int index = size;
    heapifyUp(index, feature);
    size++;
}

void HeapTree::deleteRoot()
{
    if (size <= 0)
    {
        cout << "El montículo está vacío" << endl;
        return;
    }

    heap[0] = heap[size - 1];
    size--;
    if (size > 0)
    {
        heapifyDown(0, 0);
    }
}

void HeapTree::display(int feature)
{
    cout << "Heap Tree Display:" << endl;
    if (size == 0)
    {
        cout << "The heap is empty." << endl;
        return;
    }

    // Depending on the feature, select the attribute for comparison
    string attribute;
    switch (feature)
    {
    case 1:
        attribute = "Edad";
        break;
    case 2:
        attribute = "Ahorros";
        break;
    case 3:
        attribute = "Ataque";
        break;
    case 4:
        attribute = "Defensa";
        break;
    case 5:
        attribute = "Sabiduría";
        break;
    default:
        cout << "Invalid feature." << endl;
        return;
    }

    // Display the heap based on the selected feature
    for (int i = 0; i < size; i++)
    {
        cout << "Name: " << heap[i].getName() << " || " << attribute << "=";
        switch (feature)
        {
        case 1:
            cout << heap[i].getAge();
            break;
        case 2:
            cout << heap[i].getSavings();
            break;
        case 3:
            cout << heap[i].getAttack();
            break;
        case 4:
            cout << heap[i].getDefense();
            break;
        case 5:
            cout << heap[i].getWisdom();
            break;
        }
        cout << endl;
    }
}

int HeapTree::getFeatureCode(const string &feature)
{
    if (feature == "Edad")
    {
        return 1;
    }
    else if (feature == "Ahorros")
    {
        return 2;
    }
    else if (feature == "Ataque")
    {
        return 3;
    }
    else if (feature == "Defensa")
    {
        return 4;
    }
    else if (feature == "Sabiduría")
    {
        return 5;
    }
    else
    {
        return -1; // Código por defecto si la característica no es reconocida
    }
}

Person HeapTree::getExtremumFeaturePerson(int feature, bool isMax)
{
    if (size == 0)
    {
        cout << "El montículo está vacío." << endl;
        return Person(); // Devuelve un objeto Person por defecto indicando un montículo vacío
    }

    int extremumVal = isMax ? INT_MIN : INT_MAX;
    Person extremumPerson;

    for (int i = 0; i < size; ++i)
    {
        int value = 0;
        switch (feature)
        {
        case 1:
            value = heap[i].getAge();
            break;
        case 2:
            value = heap[i].getSavings();
            break;
        case 3:
            value = heap[i].getAttack();
            break;
        case 4:
            value = heap[i].getDefense();
            break;
        case 5:
            value = heap[i].getWisdom();
            break;
        default:
            cout << "Característica no válida." << endl;
            return Person(); // Devuelve un objeto Person por defecto indicando una característica inválida
        }

        if ((isMax && value > extremumVal) || (!isMax && value < extremumVal))
        {
            extremumVal = value;
            extremumPerson = heap[i];
        }
    }

    return extremumPerson;
}