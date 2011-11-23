#ifndef BOX_H_
#define BOX_H_
#include <Geometry.hpp>
#include <Material.hpp>
#include <Vector.hpp>
#include <Triangle.hpp>

class Box : public Geometry {
  public:
    /**
      * Créer une boite dummy 
      */
    Box ();

    /**
      * @param min Coin inférieur gauche de la boite.
      * @param min Coin supérieur droit de la boite.
      */
    Box ( Vector3d const& min, Vector3d const& max );

    /**
      * @param min Coin inférieur gauche de la boite.
      * @param min Coin supérieur droit de la boite.
      * @param material Matériaux à associer à la géométrie.
      */
    Box ( Vector3d const& min, Vector3d const& max , Material* material );

  public:
    HitRecord getRecord ( Ray const& ray ) const;

    /**
      * @param t Triangle dont il faut vérifier l'appartenance à la boite.
      * @return true, si le triangle est géométriquement inclu dans la boite,
      * false, sinon.
    */
    bool contains ( const Triangle *const t ) const;

  public:
    /**
      * @return Le coin inférieur gauche de la boite.
      */
    Vector3d getMin () const { return min_; }

    /**
      * @return Le coin supérieur droitde la boite.
      */
    Vector3d getMax () const { return max_; }

  protected:
    Vector3d min_;
    Vector3d max_;
};
#endif // BOX_H_
