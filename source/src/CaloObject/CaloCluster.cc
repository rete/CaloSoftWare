#include "CaloObject/CaloCluster.h"

namespace caloobject
{

  CaloCluster::CaloCluster(std::vector<caloobject::CaloHit*> vec) : _hits(vec), _energy(0.0)  
  {
    _layerID=_hits.at(0)->getCellID()[2];
    
    for(std::vector<caloobject::CaloHit*>::iterator it=_hits.begin(); it!=_hits.end(); ++it){
      _clusterPosition+=(*it)->getPosition();
    }
    _clusterPosition/=_hits.size();
  }

}
