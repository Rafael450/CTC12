
#include <stl_sort.h>

// just to show how to use the quicksort in the STL
void stl_sort(std::vector<int> &v , SortStats &stats) {
    std::sort (v.begin(), v.end()); 
    stats.recursive_calls = 1;
    stats.custom1 = 2;
}



