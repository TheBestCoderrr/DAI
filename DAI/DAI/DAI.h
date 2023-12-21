#pragma once
#include "NodeTree.h"
#include "Fines.h"
class DAI {
public:
    DAI();
    ~DAI();
    void insert(String number, String f);
    void print() const;
    void clear();
private:
    NodeTree<String, FinesList>* root;
    void insert(NodeTree<String, FinesList>* cur, String number, String f);
    void print(NodeTree<String, FinesList>* cur) const;
    void clear(NodeTree<String, FinesList>* cur);
};

