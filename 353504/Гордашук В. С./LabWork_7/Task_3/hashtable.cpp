#include "hashtable.h"

int HashTable::hash(int key)
{
    return key % capacity;
}

HashTable::HashTable(int _capacity)
{
    capacity = _capacity;
    table.resize(capacity);
}

void HashTable::insert(MyStack *value)
{
    int index = hash(value->sum());
    Node *node = new Node{index, value};
    if (table[index] != nullptr)
    {
        Node *current = table[index];
        while (current->child != nullptr)
        {
            current = current->child;
        }
        current->child = node;
    }
    else
    {
        table[index] = node;
    }
}

void HashTable::remove(int index)
{
    Node *node = table[index];
    Node *prev = nullptr;

    if (node == nullptr)
    {
        return;
    }
    while (node->child != nullptr)
    {
        prev = node;
        node = node->child;
    }
    if (prev != nullptr)
    {
        prev->child = nullptr;
    }
    else
    {
        table[index] = nullptr;
    }
    delete node;
}
