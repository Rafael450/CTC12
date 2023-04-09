#include <string>
#include <IndexFactory.h>

IndexPointsAbstract* IndexFactory::makeIndex(std::string name) {
    if (!name.compare("MMP"))
        return new IndexPointsStlMultimap();
    else if (!name.compare("ALU"))
        return new IndexPointsAluno();
    else return nullptr;
    }
