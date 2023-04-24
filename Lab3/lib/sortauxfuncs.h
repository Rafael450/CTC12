#ifndef SORTAUXFUNC_H
#define SORTAUXFUNC_H


#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ostream> // output stream for << operator
#include <cassert>
#include <iomanip> // fixed, scientific, format manupulation for << stream


struct SortStats {

    std::string name; // algorithm name
    float ms_time; // how long did it take to sort
    int number_runs; // is these numbers the average of how many sorts?
    float vector_size; // the size of input vector
    float recursive_calls; // how many recursive calls were made
    float depth_recursion_stack; // depth of the recursion stack
    float custom1; // you may record anything else
    
    SortStats() { // structs may have default constructors
        name = "undefined";
        ms_time = number_runs = vector_size = recursive_calls = custom1 = depth_recursion_stack = 0.0f; 
    }
    
    void clear() {
        ms_time = number_runs = vector_size = recursive_calls = custom1 = depth_recursion_stack = 0.0f; 
    }
    
    
    // structs may have methods too
    // adds anoter SortStats with a weighted average
    void add2Average(SortStats &new_data) {
            if (0 == number_runs) { 
                name = new_data.name;
                ms_time = new_data.ms_time;
                vector_size = new_data.vector_size;
                recursive_calls = new_data.recursive_calls;
                depth_recursion_stack = new_data.depth_recursion_stack;
                custom1 = new_data.custom1;
                number_runs = new_data.number_runs;
            } else {
                // do not change names
                int total_runs = number_runs + new_data.number_runs;
                ms_time = ((ms_time * number_runs) + (new_data.ms_time*new_data.number_runs))/total_runs;
                vector_size = ((vector_size * number_runs) +
                              (new_data.vector_size*new_data.number_runs))/total_runs;
                recursive_calls = ((recursive_calls * number_runs) +
                              (new_data.recursive_calls*new_data.number_runs))/total_runs;
                depth_recursion_stack = ((depth_recursion_stack * number_runs) +
                              (new_data.depth_recursion_stack*new_data.number_runs))/total_runs;
                custom1 = ((custom1 * number_runs) +
                              (new_data.custom1*new_data.number_runs))/total_runs;
                number_runs = total_runs;
            }
    }//add2Average
        
     std::string asString() { 
        std::stringstream ss; 
        ss << this;
        return ss.str();
    }
    
};//struct




std::ostream& operator<<(std::ostream& stream, const SortStats& st) ;

void troca(std::vector<int> &v, int i, int j) ;

std::string v2str(std::vector<int> &v) ;

void generateOrderedVector(std::vector<int> &v, int n) ;
void generateReverseVector(std::vector<int> &v, int n) ;
void generateAlmostOrderedVector(std::vector<int> &v, int n, float p) ;


void randomPermutation(std::vector<int> &v) ;


#endif
