#include <IndexPointsAluno.h>
#include <memory>


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
    Node* aux_node1 = this->nil;
    Node* aux_node2 = this->root;
    Node* inserting = new_node(key, idx);

    while(aux_node2 != this->nil) 
    {
        aux_node1 = aux_node2;
        if(inserting->key < aux_node2->key)
            aux_node2 = aux_node2->left;
        else
            aux_node2 = aux_node2->right;
    }

    inserting->parent = aux_node1;

    if(aux_node1 == this->nil)
        this->root = inserting;
    else if(inserting->key < aux_node1->key)
        aux_node1->left = inserting;
    else
        aux_node1->right = inserting;
    
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
            Node* aux_node = inserting->parent->parent->right;
            if(aux_node->colour == 1)
            {
                inserting->parent->colour = 0;
                aux_node->colour = 0;
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
            Node* aux_node = inserting->parent->parent->left;
            if(aux_node->colour == 1)
            {
                inserting->parent->colour = 0;
                aux_node->colour = 0;
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
    Node* start_rchild = this->right;
    this->right = start_rchild->left;

    if(start_rchild->left != tree->nil)
        start_rchild->left->parent = this;
    start_rchild->parent = this->parent;

    if(this->parent == tree->nil)
        tree->root = start_rchild;
    else if(this == this->parent->left) 
        this->parent->left = start_rchild;
    else 
        this->parent->right = start_rchild;

    start_rchild->left = this;
    this->parent = start_rchild;
}

void IndexPointsAluno::Node::rightRotate(IndexPointsAluno* tree) 
{

    Node* start_lchild = this->left;
    this->left = start_lchild->right;

    if(start_lchild->right != tree->nil)
        start_lchild->right->parent = this;
    start_lchild->parent = this->parent;

    if(this->parent == tree->nil)
        tree->root = start_lchild;
    else if(this == this->parent->right)
        this->parent->right = start_lchild;
    else
        this->parent->left = start_lchild;

    start_lchild->right = this;
    this->parent = start_lchild;
}
