#ifndef PMVS3_FILTER_H
#define PMVS3_FILTER_H

#include "patch.h"
#include <list>
#include "../numeric/vec2.h"

namespace PMVS3 {
  
class FindMatch;
  
class Filter {
 public:
  Filter(FindMatch& findMatch);

  void init(void);
  void run(void);

  float computeGain(const Patch::Cpatch& patch, const int lock);

  int filterQuad(const Patch::Cpatch& patch,
                 const std::vector<Patch::Ppatch>& neighbors) const;
  
  
 protected:
  void filterOutside(void);
  void filterOutsideThread(void);
  static int filterOutsideThreadTmp(void* arg);

  void filterExact(void);
  void filterExactThread(void);
  static int filterExactThreadTmp(void* arg);
  
  void filterNeighbor(const int time);
  void filterSmallGroups(void);
  void filterSmallGroupsSub(const int pid, const int id,
                            std::vector<int>& label,
                            std::list<int>& ltmp) const;
  void setDepthMaps(void);
  void setDepthMapsVGridsVPGridsAddPatchV(const int additive);
  
  void setConf(const int image);

  std::vector<float> m_gains;

  std::vector<std::vector<int> > m_newimages, m_removeimages;
  std::vector<std::vector<TVec2<int> > > m_newgrids, m_removegrids;

  int m_time;
  std::vector<int> m_rejects;
  
  //----------------------------------------------------------------------
  // Thread related
  //----------------------------------------------------------------------
  void setDepthMapsThread(void);
  static int setDepthMapsThreadTmp(void* arg);
  
  void addPatchVThread(void);
  static int addPatchVThreadTmp(void* arg);
  
  void setVGridsVPGridsThread(void);
  static int setVGridsVPGridsThreadTmp(void* arg);

  void filterNeighborThread(void);
  static int filterNeighborThreadTmp(void* arg);
  
  FindMatch& m_fm;
  
};
};

#endif // PMVS3_FILTER_H
