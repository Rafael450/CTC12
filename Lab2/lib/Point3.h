#ifndef CES12_POINT_H
#define CES12_POINT_H

#include <vector>
#include <iostream>
#include <math.h> //sqrt

class Point3 {
public:
    Point3(float x, float y, float z, int cat) : _x(x), _y(y), _z(z), _cat(cat) { } 
    
    float x() const { return _x; }
    float y() const { return _y; }
    float z() const { return _z; }
    float cat() const { return _cat; }
    void get(std::vector<float> &v) const { v.resize(3); v[0]=_x; v[1]=_y; v[2]=_z; }
    float dist(const Point3 &p) const {
        return sqrt( (_x - p.x())*(_x - p.x())+
                     (_y - p.y())*(_y - p.y())+
                     (_z - p.z())*(_z - p.z()) );
    }//dist
    
    float norm() { 
        Point3 zero(0,0,0,1);
        return dist(zero);
    }
    
private:
    float _x,_y,_z;
    int _cat;
    
};//class


std::ostream& operator<<(std::ostream& os, const Point3& p);

#endif
