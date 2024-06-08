#ifndef MYCYCLICLIST_H
#define MYCYCLICLIST_H

#include <QString>



class MyCyclicList
{
public:
    MyCyclicList();
    void push_back(int data);
    QString print();

private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
};

#endif // MYCYCLICLIST_H
