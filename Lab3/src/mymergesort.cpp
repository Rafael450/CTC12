
#include <mysortfunctions.h>

std::vector<int> aux;

void mymergesort_recursive(std::vector<int> &v, SortStats &stats)
{
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;
    aux.resize(v.size());
    mergeSortRecursive(v, stats, 0, aux.size()-1, 1);
}

void mymergesort_iterative(std::vector<int> &v, SortStats &stats)
{
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;
    aux.resize(v.size());
    mergeSortIterative(v, stats, 0, aux.size()-1);

}

void merge(std::vector<int> &v, int i, int m, int f)
{
    int i1 = i, i2 = i, i3 = m+1;

    while(i2 <= m && i3 <= f)
    {
        if(v[i2] < v[i3])
            aux[i1++] = v[i2++];
        else
            aux[i1++] = v[i3++];
    }

    while(i2 <= m)
        aux[i1++] = v[i2++];

    while(i3 <= f)
        aux[i1++] = v[i3++];

    for(int j = i;j <= f; j++)
        v[j] = aux[j];

    
}

void mergeSortRecursive(std::vector<int> &v, SortStats &stats, int i, int f, int depth)
{
    stats.depth_recursion_stack = depth;
    stats.recursive_calls++;
    if(i < f)
    {
        int m = (i+f)/2;
        mergeSortRecursive(v, stats, i, m, depth + 1);
        mergeSortRecursive(v, stats, m+1, f, depth + 1);
        merge(v, i, m, f);
    }

    
}

void mergeSortIterative(std::vector<int> &v, SortStats &stats, int i, int f)
{
    int b = 1;
    
    while(b < f)
    {
        int p = i;
        while(p+b <= f)
        {
            int r;
            if(f < p-1+2*b)
                r = f;
            else
                r = p-1+2*b;
            
            int m = p+b-1;
            merge(v, p, m, r);
            p += 2*b;
        }
        b *= 2;
    }
}


