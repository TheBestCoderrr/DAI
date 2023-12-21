#include "DAI.h"

DAI::DAI() : root(nullptr) {}

DAI::~DAI() { clear(); }

void DAI::insert(String number, String f)
{
    if (root)
        insert(root, number, f);
    else {
        FinesList fines;
        fines.push(f);
        root = new NodeTree<String, FinesList>(number, fines);
    }
}

void DAI::insert(NodeTree<String, FinesList>* cur,String number, String f)
{
    if (cur->getKey() == number) {
        FinesList fines = cur->getValue();
        fines.push(f);
        cur->setValue(fines);
        return;
    }
    if (cur->getKey() < number)
        if (cur->getRight())
            insert(cur->getRight(), number, f);
        else {
            FinesList fines;
            fines.push(f);
            cur->setRight(new  NodeTree<String, FinesList>(number, fines));
        }
    else
        if (cur->getLeft())
            insert(cur->getLeft(), number, f);
        else {
            FinesList fines;
            fines.push(f);
            cur->setLeft(new  NodeTree<String, FinesList>(number, fines));
        }
}

void DAI::print() const
{
    print(root);
}

void DAI::print(NodeTree<String, FinesList>* cur) const
{
    if (!cur) return;
    print(cur->getLeft());
    print(cur->getRight());
    cout << "Number: " << cur->getKey() << "\nFines: ";
    cur->getValue().print();
    cout << endl;
}


void DAI::clear()
{
    clear(root);
    root = nullptr;
}

void DAI::clear(NodeTree<String, FinesList>* cur)
{
    if (!cur) return;
    clear(cur->getLeft());
    clear(cur->getRight());
    delete cur;
}

