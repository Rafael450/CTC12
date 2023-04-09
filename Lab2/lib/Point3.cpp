#include <Point3.h>

std::ostream& operator<<(std::ostream& os, const Point3& p)
{
    os << "[ " << p.x() << ' ' << p.y() << ' ' << p.z() << " ]";
    return os;
}
