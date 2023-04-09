#ifndef CES12_STLINDEXPOINTS_H
#define CES12_STLINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>

class IndexPointsStlMultimap : public IndexPointsAbstract {
    
public:
    
    long size() { return _map.size(); }
        
    void add (double key, long idx ) { _map.insert(std::make_pair(key,idx)) ; }
    
    //look for a range of values
    void find(std::vector<long> &res, double first, double last ) ;
    
    
private: 
    std::multimap<double, long> _map;
    
};//class


#endif
