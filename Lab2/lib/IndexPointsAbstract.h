#ifndef CES12_INDEXPOINTSABS_H
#define CES12_INDEXPOINTSABS_H

#include <vector>
//#include <iostream> //#include <iomanip> 


class IndexPointsAbstract {
    
public:
    
    IndexPointsAbstract() : _tolerance(1e-3) { }
    
    virtual long size() = 0;
    
    virtual void add (double key, long idx ) =0 ;
    
    //look for a range of values
    virtual void find(std::vector<long> &res, double first, double last ) = 0;
    
    // convenience function to find a single value
    void find(std::vector<long> &res, double value ) {
        find(res, value - _tolerance, value + _tolerance );
    }
    
    
    void setTolerance( double newtol ) { _tolerance = newtol; }
    double getTolerance() { return _tolerance; } 
    
private: 
    double _tolerance;
    
};//class


#endif
