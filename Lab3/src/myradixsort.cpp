
#include <mysortfunctions.h>


void myradixsort(std::vector<int> &v, SortStats &stats) {
    // you need to set the counting of recursive recursive_calls
    stats.recursive_calls = 0;
    // you need to set the depth = the maximum height of the tree of recursion calls. 
    stats.depth_recursion_stack = 0;
    // the tester already knows the size of v and the algorithm name, it already measures time
    // you may set custom1 field if you want to measure anything else.
    stats.custom1 = 2;
    radixSort(v, stats);
}

void radixSort(std::vector<int> &v, SortStats &stats)
{
    if(v.empty()) return;

    int d = 0;
    int max = *std::max_element(v.begin(), v.end());
    while (max != 0)
    {
        max /= 2;
        d++;
    }

    std::queue<int> q[2];
    for(int i = 0, factor = 0; i < d; factor++, i++)
    {
        for(int j = 0; j < v.size(); j++)
            q[(v[j] >> factor) & 1].push(v[j]);

        int k = 0;

        for(int j = 0; j < 2; j++)
        {
            while(!q[j].empty())
            {
                v[k++] = q[j].front();
                q[j].pop();
            }

        }
    }
}
