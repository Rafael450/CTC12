#include "hash.h"
// LOOK FOR THE COMMENTS IN THE .H 
// TO UNDERSTAND WHAT EACH FUNCTION MUST DO

Hash::Hash(int tablesize, int (*hf) (std::string) ) {
    _table = std::vector<std::forward_list<std::string>>(tablesize);
    _hash_func = hf;
}

int Hash::add(std::string str, int &collisions) { 

    if(!contains(str, collisions)){
        _table[hash(str)].push_front(str);
        return 1;
    }

    return 0;
    
}//add

int Hash::remove(std::string str, int &collisions) { 

    if(contains(str, collisions)){
        _table[hash(str)].remove(str);
        return 1;
    }
    
    return 0;
    
}//remove


int Hash::hash(std::string str) { 
    return _hash_func(str);
}//hash
    
int Hash::contains(std::string str, int &collisions) { 

    int hash_num = hash(str); 
    collisions = 0;

    for(std::forward_list<std::string>::iterator it = _table[hash_num].begin(); it != _table[hash_num].end(); it++){
        collisions++;
        if(*it == str) return 1;
    }

    return 0;
    
}//contains


int Hash::worst_case() {
    int size = 0;

    for(int i = 0; i < size_t(_table.size()); i++) {
        int list_size = 0;
        for(std::forward_list<std::string>::iterator it = _table[i].begin(); it != _table[i].end(); it++){
            list_size++;
        }

        if(list_size > size) size = list_size;
    }

    return size;
    
}//worst_case

int Hash::size() {
    int size = 0;

    for(int i = 0; i < size_t(_table.size()); i++) {
        for(std::forward_list<std::string>::iterator it = _table[i].begin(); it != _table[i].end(); it++){
            size++;
        }
    }
    return size;
    
}//size

