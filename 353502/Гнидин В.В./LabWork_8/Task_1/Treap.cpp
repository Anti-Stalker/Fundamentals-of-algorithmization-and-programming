//
// Created by volodya-petarda on 5/28/24.
//

#include "Treap.h"

Treap::Node *Treap::merge(Treap::Node *l, Treap::Node *r) {
    if(r == nullptr)
        return l;
    if(l == nullptr)
        return r;
    if(l->priority > r->priority){
        l->r = merge(l->r, r);
        return l;
    }
    else{
        r->l = merge(l, r->l);
        return r;
    }
}

std::pair<Treap::Node*, Treap::Node*> Treap::split(Treap::Node *n, int key) {
    if(n == nullptr)
        return {nullptr, nullptr};
    if(key > n->key){
        std::pair<Node*, Node*> p = split(n->r, key);
        n->r = p.first;
        return {n, p.second};
    }
    else{
        std::pair<Node*, Node*> p = split(n->l, key);
        n->l = p.second;
        return {p.first, n};
    }
}

void Treap::insert(int key, std::string value) {
    Node *n = new Node(key, value, rand());
    std::pair<Treap::Node*, Treap::Node*> p1 = split(root, key + 1);
    std::pair<Treap::Node*, Treap::Node*> p2 = split(p1.first, key);
    root = merge(merge(p2.first, n), p1.second);
}

void Treap::erase(int key) {
    std::pair<Treap::Node*, Treap::Node*> p = split(root, key + 1);
    root = merge(split(p.first, key).first, p.second);
}

std::string Treap::find(int key) {
    std::pair<Treap::Node*, Treap::Node*> p1 = split(root, key + 1);
    std::pair<Treap::Node*, Treap::Node*> p2 = split(p1.first, key);
    std::string ans = "not found";
    if(p2.second != nullptr)
        ans = p2.second->val;
    root = merge(merge(p2.first, p2.second), p1.second);
    return ans;
}

void Treap::printTree() {
    std::cout<<"Tree:\n";
    recPrint(root);
}

void Treap::recPrint(Treap::Node *n) {
    if(n == nullptr)
        return;
    recPrint(n->l);
    std::cout<<"key: "<<n->key<<" value: "<<n->val<<" priority: "<<n->priority<<'\n';
    recPrint(n->r);
}

void Treap::getTree(std::vector<std::vector<std::string>> &result) {
    BaseTree::getTree(result);
    addToVect(root, result, {"-1", "-1"});
}

void Treap::addToVect(Treap::Node *root, std::vector<std::vector<std::string>> &result,
                      std::pair<std::string, std::string> last) {
    if(root == nullptr)
        return;
    result.push_back({last.first, last.second, std::to_string(root->key), root->val});
    addToVect(root->l, result, {std::to_string(root->key), root->val});
    addToVect(root->r, result, {std::to_string(root->key), root->val});

}
