public interface Buildable { }

/**
  * @opt all
  * @navassoc - Construit - Buildable
  */
public class Builder {
  public String getID () { }
  public Buildable getObject () { }
}

public class MaterialBuilder extends Builder { }

public class MeshBuilder extends Builder { }
public class SphereBuilder extends Builder { }
public class PlaneBuilder extends Builder { }

public class PerspectiveBuilder extends Builder { }
public class PerspectiveDOFBuilder extends Builder { }

public class PointBuilder extends Builder { }
public class DirectionnalBuilder extends Builder { }
public class AreaBuilder extends Builder { }

/**
  * @opt all
 * @navassoc 1 "Fournit les rayons" 0..n Sampler 
  */
public class Camera implements Buildable {
  public abstract Ray getRay ( );  
}

public class Perspective extends Camera { }
public class PerspectiveDOF extends Camera { }
public class Orthographic extends Camera { }
public class FishEye extends Camera { }

/**
  * @opt all
  * @navassoc 0..n "Fait reference" 0..n Material
  */
public class Geometry implements Buildable {
  public abstract HitRecord getRecord ( Ray ray );
  public abstract Vector2 getUVFromHit ( HitRecord record );
}

public class Sphere extends Geometry { }
public class Plane extends Geometry { }
public class Mesh extends Geometry { }
public class Triangle extends Geometry { }
public class Box extends Geometry { }
public class Quadric extends Geometry { }

/**
  * @opt all
  */
public class Light implements Buildable {
  public abstract Color getContribution ( );
}

public class Directional extends Light { }
public class Point extends Light { }
public class Cone extends Light { }

public class AreaLight extends Light { }
public class SphereLight extends Light { }
public class SphereLight extends Light { }

/**
  * @opt all
  */
public class Sampler {
  public abstract void getRays ( );
}

public class DefaultSampler extends Sampler { }
public class SuperSampler extends Sampler { }
public class AdaptativeSampler extends Sampler { }

public class Material implements Buildable { }
