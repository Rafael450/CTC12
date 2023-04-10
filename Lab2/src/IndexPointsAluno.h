#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <memory>
#include <IndexPointsAbstract.h>

class IndexPointsAluno : public IndexPointsAbstract {
    
public:

    IndexPointsAluno();
    
    long size();
        
    void add(double key, long idx);
    
    //look for a range of values
    void find(std::vector<long> &res, double first, double last );
    
    
private: 

    struct Node{
        double key;
        long idx;

        short colour; // 0 para preto, 1 para vermelho

        Node *parent, *right, *left;

        void leftRotate(IndexPointsAluno* tree);  
        void rightRotate(IndexPointsAluno* tree);

    };

    Node* root;
    Node* nil;


    Node* new_node(double key, long idx);

    void add_fix(Node* inserting);

    int recursive_size(Node* crr_node);

    void recursive_find(Node* crr_node, std::vector<long> &res, double first, double last);

    
};//class


#endif
