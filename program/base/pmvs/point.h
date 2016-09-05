#ifndef PMVS3_POINT_H
#define PMVS3_POINT_H

#include "../numeric/vec4.h"
#include "../numeric/mat3.h"

namespace PMVS3 {
class Point {
 public:
  Point(void);
  virtual ~Point();
  
  Vec3f m_icoord;
  float m_response;

  // 0: Harris
  // 1: DoG
  int m_type;

  // tempporary variable, used to store original imageid in initial match
  int m_itmp;

  // 3D coordinate
  Vec4f m_coord;
  
  bool operator < (const Point& rhs) const {
    return m_response < rhs.m_response;
  }

  friend std::istream& operator >>(std::istream& istr, Point& rhs);
  friend std::ostream& operator <<(std::ostream& ostr, const Point& rhs);
};

bool SortPoint(const Point& a, const Point& b);

std::istream& operator >>(std::istream& istr, Point& rhs);
std::ostream& operator <<(std::ostream& ostr, const Point& rhs);
};

#endif //PMVS3_POINT_H
