
#include <mysortfunctions.h>

// you only need to mantain the headers. You can create aux funcs, objects, or create a generic quicksort that can work with different functions to select the pivot.

/// the most comon quicksort, with 2 recursive calls
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;



    quickSortTwoRec(v, stats, 0, v.size()-1, 1);


}// function myquicksort_2recursion_medianOf3

/// quicksort with one recursive call
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    quickSortOneRec(v, stats, 0, v.size()-1, 1);

} // function myquicksort_1recursion_medianOf3

/// quicksort with fixed pivot 
/// be sure to compare with equivalent implementation 
/// e.g., if you do 1 recursive call, compare with the 1recursion version
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 1;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 1;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;

    quickSortFixedPivot(v, stats, 0, v.size()-1, 1);
} // myquicksort_fixedPivot


int partition(std::vector<int> &v, int left, int right, bool fixedPivot)
{
    if(!fixedPivot)
    {
        int median = (left + right)/2;
        if((median > left && right > median) || (median < left && right < median))
        {
            int aux = v[left];
            v[left] = v[median];
            v[median] = aux;
        }
        else if((right > left && median > right) || (right < left && median < right))
        {
            int aux = v[left];
            v[left] = v[right];
            v[right] = aux;
        }
    }

    int pivot = v[left], l = left+1, r = right;

    while(true)
    {
        while(l < right && v[l] < pivot) l++;
        while(r > left && v[r] >= pivot) r--;

        if(l >= r) break;

        int aux = v[l];
        v[l] = v[r];
        v[r] = aux;
    }
    v[left] = v[r];
    v[r] = pivot;
    return r;
}

void quickSortTwoRec(std::vector<int> &v, SortStats &stats, int min, int max, int depth)
{
    stats.recursive_calls++;
    if(depth > stats.depth_recursion_stack) stats.depth_recursion_stack = depth;
    if(min < max)
    {
        int p = partition(v, min, max, false);
        quickSortTwoRec(v, stats, min, p-1, depth + 1);
        quickSortTwoRec(v, stats, p+1, max, depth + 1);
    }
}

void quickSortOneRec(std::vector<int> &v, SortStats &stats, int min, int max, int depth)
{
    stats.recursive_calls++;
    if(depth > stats.depth_recursion_stack) stats.depth_recursion_stack = depth;
    while(min < max)
    {
        int p = partition(v, min, max, false);
        if(p-min < max-p)
        {
            quickSortOneRec(v, stats, min, p-1, depth + 1);
            min = p+1;
        }
        else
        {
            quickSortOneRec(v, stats, p+1, max, depth + 1);
            max = p-1;
        }
    }
}

void quickSortFixedPivot(std::vector<int> &v, SortStats &stats, int min, int max, int depth)
{
    stats.recursive_calls++;
    if(depth > stats.depth_recursion_stack) stats.depth_recursion_stack = depth;
    if(min < max)
    {
        int p = partition(v, min, max, true);
        quickSortFixedPivot(v, stats, min, p-1, depth + 1);
        quickSortFixedPivot(v, stats, p+1, max, depth + 1);
    }
    stats.recursive_calls++;
}


