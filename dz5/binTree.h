#ifndef BINTREE_H_INCLUDED
#define BINTREE_H_INCLUDED

#include <iostream>
#include <vector>


struct BinNode{

    int key;
    BinNode * left;
    BinNode * right;
    BinNode * p;

public:
    BinNode():
      key(0),
      left(nullptr),
      right(nullptr),
      p(nullptr){}

};


class BinTree{
private:
    BinNode * top = nullptr;

public:
    int key(BinNode * node);

    void BinInsert(int key);
    void BinInsert(BinNode * node, int key);

    BinNode * BinFind(int key);
    BinNode * BinFind(BinNode * node, int key);

    void BinDelete(int key);

    void BinWalk(std::vector<int> * vec);
    void BinWalk(BinNode * node, std::vector<int> * vec);

    int key(BinNode * node);
};

int BinTree::key(BinNode * node){
    return node->key;
};

void BinTree::BinInsert(int key){
    if (top == nullptr){
        BinNode * newnode = new BinNode;
        newnode->key = key;
        top = newnode;
        return;
    }
    BinInsert(top, key);
};


void BinTree::BinInsert(BinNode * node, int key){
    if (key < node->key){
        if (node->left == nullptr){
            BinNode * newleft = new BinNode;
            newleft->key = key;
            newleft->p = node;
            node->left = newleft;
            return;
        }
        BinInsert(node->left, key);
    }
    if (key > node->key){
        if (node->right == nullptr){
            BinNode * newright = new BinNode;
            newright->key = key;
            newright->p = node;
            node->right = newright;
            return;
        }
        BinInsert(node->right, key);
    }

};

BinNode * BinTree::BinFind(int key){
    return BinFind(top, key);
};


BinNode * BinTree::BinFind(BinNode * node, int key){
    if (node == nullptr) return nullptr;
    if (node->key == key) return node;
    if (key < node->key) return BinFind(node->left, key);
    if (key > node->key) return BinFind(node->right, key);
};


void BinTree::BinDelete(int key){
    BinNode * node = BinFind(key);
    if (node == nullptr) return;
    if ((node->left != nullptr) && (node->right != nullptr)){
        BinNode * successor = node->right;
        while (successor->left != nullptr) successor = successor->left;
        std::swap(node->key, successor->key);
        node = successor;
    }
    if ((node->left == nullptr) && (node->right == nullptr)){
        delete node;
        return;
    }
    if ((node->left == nullptr) && (node->right != nullptr)){
        BinNode * tempnd = node;
        if (node->p->left == node) node->p->left = node->right;
        else node->p->right = node->right;
        delete tempnd;
        node = node->right;
        node->right = nullptr;
        return;
    }
    if ((node->left != nullptr) && (node->right == nullptr)){
        BinNode * tempnd = node;
        if (node->p->left == node) node->p->left = node->left;
        else node->p->right = node->left;
        delete tempnd;
        node = node->left;
        node->left = nullptr;
        return;
    }
};


void BinTree::BinWalk(std::vector<int> * vec){
    if (top == nullptr) return;
    BinWalk(top->left, vec);
    vec->push_back(top->key);
    BinWalk(top->right, vec);
};


void BinTree::BinWalk(BinNode * node, std::vector<int> * vec){
    if (node == nullptr) return;
    BinWalk(node->left, vec);
    vec->push_back(node->key);
    BinWalk(node->right, vec);
};


void BinSort(std::vector<int> * vec){
    BinTree btr;
    for (size_t i = 0; i < vec->size(); ++i)
        btr.BinInsert((*vec)[i]);
    vec->clear();
    btr.BinWalk(vec);
};

#endif // BINTREE_H_INCLUDED
