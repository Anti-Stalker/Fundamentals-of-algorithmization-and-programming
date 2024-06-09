#include "hashtablechild.h"

template <typename T>
HashTableChild<T>::HashTableChild(int size) : HashTable<T>(size){}

template<typename T>
void HashTableChild<T>::print(QListWidget *listWidget)
{
    listWidget->clear();


    Stack<Item<T>> tempStack;
    QString oneStack;

    for(int i = 0; i < this->size; i++)
    {
        oneStack = QString::number(i) + ". ";

        while (!this->table[i].isEmpty()) {
            Item stackItem = this->table[i].MyPop();
            tempStack.MyPush(stackItem);
            oneStack += QString::number(stackItem.key) + "(" + stackItem.value + ") ";
        }

        while (!tempStack.isEmpty()) {
            this->table[i].MyPush(tempStack.MyPop());
        }

        listWidget->addItem(oneStack);
    }
}

template<typename T>
void HashTableChild<T>::deleteAllEvenKeys()
{
    Stack<Item<T>> tempStack;

    for(int i = 0; i < this->size; i++)
    {

        while (!this->table[i].isEmpty()) {
            Item stackItem = this->table[i].MyPop();
            if(stackItem.key % 2 == 1) tempStack.MyPush(stackItem);
        }

        while (!tempStack.isEmpty()) {
            this->table[i].MyPush(tempStack.MyPop());
        }
    }
}

template<typename T>
void HashTableChild<T>::clear()
{
    for(int i = 0; i < this->size; i++)
    {

        while (!this->table[i].isEmpty()) {
            this->table[i].MyPop();
        }
    }
}
