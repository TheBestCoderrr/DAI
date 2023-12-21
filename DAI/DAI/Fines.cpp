#include "Fines.h"

FinesList::~FinesList() { DeleteAll(); }


void FinesList::push(String f)
{
    Fine* temp = new Fine(f);
    if (tail)
        tail->setNext(temp);
    else
        head = temp;
    tail = temp;
    ++counter;
}

void FinesList::pop()
{
    if (head) {
        Fine* temp = head;
        head = head->getNext();
        delete temp;
        --counter;
        if (!head) tail = nullptr;
    }
}

void  FinesList::DeleteAll() { while (counter > 0) { pop(); } }

void FinesList::print() const {
    Fine* cur = head;
    while (cur) {
        cur->Print();
        cur = cur->getNext();
    }
    cout << endl;
}
