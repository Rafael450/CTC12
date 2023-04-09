#include <PointReader.h>


void PointReader::open(std::string fname) {
    close();
    _fs.open(fname);
}

Point3 PointReader::parseLineAsc(std::string &line) {
    float x,y,z; int cat; int aux;
    std::istringstream iss(line);
    assert( (iss >> x >> y >> z >> cat >> aux) && "WRONG LINE FOMMAT. EXPECTED: X Y Z CAT \\n" ); 
    Point3 p(x,y,z,cat);
    return p;
}//parselineAsc


void PointReader::read(std::vector<Point3> &vp) {
    std::string line;
    while (std::getline(_fs, line))
    {
        vp.push_back(parseLineAsc(line));
    }//while    
    
}//read
