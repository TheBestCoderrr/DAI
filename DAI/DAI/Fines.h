#pragma once
#include "String.h"
class Fine
{
public:
    explicit Fine(String f, Fine* n = nullptr) :fine(f), next(n) {};
    String getFine() const { return fine; }
    void setFine(String f) { fine = f; }
    Fine* getNext() const { return next; }
    void setNext(Fine* n) { next = n; }
    void Print() const { cout << "\n\t" << fine; }
private:
    String fine;
    Fine* next;
};

class FinesList {
public:
    FinesList() :head(nullptr), tail(nullptr), counter(0) {}
    FinesList(const FinesList& other) : FinesList() {
        *this = other;
    }
    ~FinesList();

    FinesList& operator=(const FinesList& other) {
        this->DeleteAll();
        Fine* cur = other.head;
        while (cur) {
            this->push(cur->getFine());
            cur = cur->getNext();
        }
        return *this;
    }

    size_t size() const { return counter; }
    void push(String v);
    void pop();
    void DeleteAll();
    void print() const;
    bool empty() const { return counter == 0; }
private:
    Fine* head;
    Fine* tail;
    size_t counter;
};