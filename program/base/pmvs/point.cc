#include "point.h"
#include <iostream>

using namespace PMVS3;
using namespace std;

Point::Point(void) {
  m_response = -1.0;
  m_type = -1;
}

Point::~Point() {
}

std::istream& PMVS3::operator >>(std::istream& istr, Point& rhs) {
  string header;
  char str[1024];
  istr >> str;
  header = string(str);
  istr >> rhs.m_icoord[0] >> rhs.m_icoord[1] >> rhs.m_response >> rhs.m_type;
  rhs.m_icoord[2] = 1.0f;
  return istr;
}

std::ostream& PMVS3::operator <<(std::ostream& ostr, const Point& rhs) {
  ostr << "POINT0" << endl
       << rhs.m_icoord[0] << ' ' << rhs.m_icoord[1] << ' ' << rhs.m_response << ' '
       << rhs.m_type;
  return ostr;
}

bool SortPoint(const Point& a, const Point& b)
{
    return a.m_response < b.m_response;
}
