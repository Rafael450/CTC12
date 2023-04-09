#ifndef CES12_POINTREADER_H
#define CES12_POINTREADER_H

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>

#include <Point3.h>

class PointReader {

    
public:
    PointReader(std::string fname) { open(fname); }
    void open(std::string fname);
    void close() { _fs.close(); };
    Point3 parseLineAsc(std::string &line) ;
    void read(std::vector<Point3> &vp) ;
    
    ~PointReader() { close(); }
private:
    std::ifstream _fs;

};//class


#endif
