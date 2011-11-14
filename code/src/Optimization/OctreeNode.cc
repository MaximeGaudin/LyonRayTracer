#include "OctreeNode.hpp"
#include <Vector.hpp>

#include <boost/foreach.hpp>
#define feach BOOST_FOREACH

OctreeNode::OctreeNode ()
: Geometry()
{}

OctreeNode::OctreeNode (
    Box box,
    vector< Triangle* > triangles,
    unsigned int minTriangles)
: Geometry()
  , box_(box)
    , triangles_(triangles)
{
  cout << box.getMin() << " || " << box.getMax() << endl;
  if ( triangles.size() <= minTriangles ) {
    isLeaf_ = true;
    cout << "Leaf !" << endl;
  } else {
    isLeaf_ = false;
    Vector3d O ( box.getMin() );

    Vector3d Right;
    Right[0] = ((box.getMax() - box.getMin()) / 2.0)[0];

    Vector3d Up;
    Up[1] = ((box.getMax() - box.getMin()) / 2.0)[1];

    Vector3d Forward;
    Forward[2] = ((box.getMax() - box.getMin()) / 2.0)[2];

    cout << "Création des subboxes... (" << triangles.size() << ")" << endl;
    Box subBoxes[8];
    subBoxes[0] = createBox ( V3d_Zero ); 
    subBoxes[1] = createBox ( Up ); 

    subBoxes[2] = createBox ( Right ); 
    subBoxes[3] = createBox ( Right + Up); 

    subBoxes[4] = createBox ( Forward ); 
    subBoxes[5] = createBox ( Forward + Up); 

    subBoxes[6] = createBox ( Right + Forward ); 
    subBoxes[7] = createBox ( Right + Forward + Up); 

    cout << "Ajout des triangles aux subboxes..." << endl;
    vector< Triangle* > subBoxesTriangles[8];
    feach ( Triangle* t, triangles ) {
      for ( unsigned int i = 0; i < 8; ++i ) {
        if ( subBoxes[i].contains ( t ) ) {
          cout << "Ajout d'un triangle..." << endl;
          subBoxesTriangles[i].push_back( t );
        }
      }
    }

    for ( unsigned int i = 0; i < 8; ++i ) {
      cout << "Ajout de la subboxes " << i << " : " << subBoxesTriangles[i].size() << endl;
      if ( subBoxesTriangles[i].size() != 0 )
        subNodes_.push_back ( new OctreeNode ( subBoxes[i], subBoxesTriangles[i], minTriangles ) );
    }
  }
}

HitRecord OctreeNode::getRecord ( Ray ray ) const {
  if ( isLeaf_ ) {
    HitRecord closestHit;
    closestHit.hit = false;
    double closestT = numeric_limits<double>::infinity();

    feach ( Triangle* tr, triangles_) {
      HitRecord newRecord = tr->getRecord ( ray );

      if ( newRecord.hit && newRecord.t < closestT ) {
        closestT = newRecord.t;
        closestHit = newRecord;
      }
    }

    return closestHit;
  } else {
    HitRecord closestHit;
    closestHit.hit = false;
    double closestT = numeric_limits<double>::infinity();

    // Il est possible d'optimiser le calcul en commencant par
    // les boites les plus proches.

    feach ( OctreeNode* children, subNodes_ ) {
      if ( children->getBox().getRecord ( ray ).hit ) {
        HitRecord newRecord = children->getRecord ( ray );

        if ( newRecord.hit && newRecord.t < closestT ) {
          closestT = newRecord.t;
          closestHit = newRecord;
        }
      }
    }

    return closestHit;
  }
}

Box OctreeNode::createBox ( Vector3d origin ) const {
  Vector3d O ( box_.getMin() );
  Vector3d half (((box_.getMax() - box_.getMin()) / 2.0));

  return Box ( O + origin, O + origin + half);
}
