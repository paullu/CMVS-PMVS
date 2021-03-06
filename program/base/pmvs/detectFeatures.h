#ifndef PMVS3_DETECTFEATURES_H
#define PMVS3_DETECTFEATURES_H

/*
 * A main class to detect features
 */

#include <string>
#include <list>
#include "tinycthread.h"
#include "../image/photoSetS.h"
#include "point.h"

namespace Image {
  class PhotoSetS;
};

namespace PMVS3 {

class DetectFeatures {
 public:
  DetectFeatures(void);
  virtual ~DetectFeatures();

  void run(const Image::PhotoSetS& pss,
           const int num, const int csize, const int level,
           const int CPU = 1);

  std::vector<std::vector<Point> > m_points;
  
 protected:
  const Image::PhotoSetS* m_ppss;
  int m_csize;
  int m_level;
  
  //----------------------------------------------------------------------
  // thread related
  //----------------------------------------------------------------------  
  mtx_t m_rwlock;
  int m_CPU;

  std::list<int> m_jobs;
  
  void runThread(void);
  static int runThreadTmp(void*arg);
};
};

#endif // PMVS3_DETECTFEATURES_H
