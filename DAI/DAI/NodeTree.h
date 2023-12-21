#pragma once
template<class Key, class V>
class NodeTree {
public:
    explicit NodeTree(Key key, V value, NodeTree* left = nullptr, NodeTree* right = nullptr) {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
    Key getKey() const { return key; }
    V getValue() const { return value; }
    void setValue(const V& value) { this->value = value; }
    NodeTree* getLeft() const { return left; }
    NodeTree* getRight() const { return right; }
    void setLeft(NodeTree* left) { this->left = left; }
    void setRight(NodeTree* right) { this->right = right; }
private:
    V value;
    Key key;
    NodeTree* left;
    NodeTree* right;
};