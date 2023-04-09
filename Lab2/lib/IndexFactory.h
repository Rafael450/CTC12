#ifndef CES12_INDEXFACTORY_H
#define CES12_INDEXFACTORY_H

#include <IndexPointsStlMultimap.h>
#include <IndexPointsAluno.h>

class IndexFactory {
    
public:
    static  IndexPointsAbstract* makeIndex(std::string name);
    
    
};//factory



#endif
