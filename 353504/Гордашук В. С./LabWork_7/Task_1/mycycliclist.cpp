#include "mycycliclist.h"

MyCyclicList::MyCyclicList() : head(nullptr), tail(nullptr) {}

void MyCyclicList::push_back(int data)
{
    Node* node = new Node{data, head};
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    tail = node;
}

QString MyCyclicList::print()
{
    Node *node = head;
    QString res;
    if (node != nullptr) {
        do {
            res += QString::number(node->data);
            node = node->next;
            if (node != head) res += ' ';
        } while (node != head);
    }
    return res;
}
