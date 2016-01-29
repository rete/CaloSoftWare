#ifndef CALOTRACK_HH
#define CALOTRACK_HH

#include <iostream>
#include <vector>
#include "CLHEP/Vector/ThreeVector.h"
#include "CaloObject/CaloCluster.h"

namespace caloobject
{ 

  class CaloTrack
  {
  public:
    CaloTrack(std::vector<caloobject::CaloCluster*> &vec);
    ~CaloTrack(){;}

    inline void setChi2(float chi2){_chi2=chi2;}
    inline void setTrackParameters(float *params){
      for(unsigned int i=0; i<4; i++) _params[i]=params[i];
    }

    inline const caloobject::CaloCluster* getTrackStartingCluster(){return (*_clusters.begin());}
    inline const caloobject::CaloCluster* getTrackLastCluster(){return (*(_clusters.end()-1));}
    inline const float getChi2(){return _chi2;}
    inline const float *getTrackParameters(){return _params;} 
    inline const void addCluster(caloobject::CaloCluster* cluster){_clusters.push_back(cluster); Update();}
    
  private:
    void Update();

    std::vector<caloobject::CaloCluster*> _clusters;
    float _chi2;
    float _params[4];
  };

}
#endif