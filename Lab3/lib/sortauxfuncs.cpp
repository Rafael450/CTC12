#include <sortauxfuncs.h>


void troca(std::vector<int> &v, int i, int j) {
    assert(i < v.size());
    assert(j < v.size());
    int aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

std::string v2str(std::vector<int> &v) {
    std::stringstream ss;
        ss << "[ ";
        for (int val : v) 
            ss << val << " " ;
        ss << "]" << std::endl;
    return ss.str();
}


void generateOrderedVector(std::vector<int> &v, int n) {
    v.resize(n);
    for (int i=0; i <= v.size()-1; i++)
        v[i] = i;
}


void generateReverseVector(std::vector<int> &v, int n) {
    v.resize(n);
    for (int i=0; i <= v.size()-1; i++)
        v[i] = n-i;
}


/// generates ordered vector, then performs p*n random exchanges
void generateAlmostOrderedVector(std::vector<int> &v, int n, float p) {
    generateOrderedVector(v, n);
    for (int i=0; i < v.size()*p; i++) {
        troca(v,rand() % v.size(),rand() % v.size()); 
    }
}


void randomPermutation(std::vector<int> &v) {
    for (int i=0; i < v.size(); i++) {
        troca(v,i,rand() % v.size()); 
        
    }
}


std::ostream& operator<<(std::ostream& stream, 
                     const SortStats& st) {
    if (!st.name.empty()) stream << st.name << ", ";
    stream << std::scientific << st.ms_time << ", " << st.number_runs << ", " << std::fixed << st.vector_size << ", " << std::scientific << st.recursive_calls << ", " << st.depth_recursion_stack << ", " << st.custom1 << std::endl;
    return stream;
 }
 
 
