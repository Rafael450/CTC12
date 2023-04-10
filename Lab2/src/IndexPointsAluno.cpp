#include <IndexPointsAluno.h>
#include <memory>
#include <iostream>


IndexPointsAluno::IndexPointsAluno()
{
    this->nil = new_node(0,0);
    this->nil->parent = this->nil;
    this->nil->right = this->nil;
    this->nil->left = this->nil;

    this->root = this->nil;
}

/// returns the number of elements in the index
long IndexPointsAluno::size() { 
    return recursive_size(this->root);
}

/// adds new element to the index. 
void IndexPointsAluno::add(double key, long idx) 
{    
    Node* y = this->nil;
    Node* x = this->root;
    Node* inserting = new_node(key, idx);

    while(x != this->nil) 
    {
        y = x;
        if(inserting->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    inserting->parent = y;

    if(y == this->nil)
        this->root = inserting;
    else if(inserting->key < y->key)
        y->left = inserting;
    else
        y->right = inserting;
    
    inserting->left = this->nil;
    inserting->right = this->nil;
    inserting->colour = 1;

    add_fix(inserting);
}


void IndexPointsAluno::find(std::vector<long> &res, double first, double last) 
{
    recursive_find(this->root, res, first, last);
}

IndexPointsAluno::Node* IndexPointsAluno::new_node(double key, long idx) {
    Node* created_node = new Node;
    created_node->colour = 0;
    created_node->key = key;
    created_node->idx = idx;
    created_node->right = this->nil;
    created_node->left = this->nil;
    return created_node;
}

int IndexPointsAluno::recursive_size(Node* crr_node) {
    if(crr_node == this->nil)
        return 0;

    return 1 + recursive_size(crr_node->right) + recursive_size(crr_node->left);
}

void IndexPointsAluno::recursive_find(Node* crr_node, std::vector<long> &res, double first, double last)
{
    if(crr_node == this->nil)
        return;
    if((last > crr_node->key && crr_node->key > first)) 
        res.push_back(crr_node->idx);
    if(crr_node->key < last)
        recursive_find(crr_node->right, res, first, last);
    if(crr_node->key > first)
        recursive_find(crr_node->left, res, first, last);

}

void IndexPointsAluno::add_fix(Node* inserting) 
{
    while(inserting->parent->colour == 1)
    {
        if(inserting->parent == inserting->parent->parent->left)
        {
            Node* y = inserting->parent->parent->right;
            if(y->colour == 1)
            {
                inserting->parent->colour = 0;
                y->colour = 0;
                inserting->parent->parent->colour = 1;
                inserting = inserting->parent->parent;
            }
            else
            {
                if(inserting == inserting->parent->right)
                {
                    inserting = inserting->parent;
                    inserting->leftRotate(this);
                }
                inserting->parent->colour = 0;
                inserting->parent->parent->colour = 1;
                inserting->parent->parent->rightRotate(this);
            }
        }
        else
        {
            Node* y = inserting->parent->parent->left;
            if(y->colour == 1)
            {
                inserting->parent->colour = 0;
                y->colour = 0;
                inserting->parent->parent->colour = 1;
                inserting = inserting->parent->parent;
            }
            else 
            {
                if(inserting == inserting->parent->left)
                {
                    inserting = inserting->parent;
                    inserting->rightRotate(this);
                }
                inserting->parent->colour = 0;
                inserting->parent->parent->colour = 1;
                inserting->parent->parent->leftRotate(this);
            }
        }
    }
    this->root->colour = 0;
}

void IndexPointsAluno::Node::leftRotate(IndexPointsAluno* tree ) 
{
    Node* y = this->right;
    this->right = y->left;

    if(y->left != tree->nil)
        y->left->parent = this;
    y->parent = this->parent;

    if(this->parent == tree->nil)
        tree->root = y;
    else if(this == this->parent->left) 
        this->parent->left = y;
    else 
        this->parent->right = y;

    y->left = this;
    this->parent = y;
}

void IndexPointsAluno::Node::rightRotate(IndexPointsAluno* tree) 
{

    Node* y = this->left;
    this->left = y->right;

    if(y->right != tree->nil)
        y->right->parent = this;
    y->parent = this->parent;

    if(this->parent == tree->nil)
        tree->root = y;
    else if(this == this->parent->right)
        this->parent->right = y;
    else
        this->parent->left = y;

    y->right = this;
    this->parent = y;
}
