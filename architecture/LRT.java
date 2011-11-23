
public interface Buildable { }

/**
  * @opt all
  */
public class Sampler {
  public abstract void getRays ( );
}

public class DefaultSampler extends Sampler { }
public class SuperSampler extends Sampler { }

/**
  * @opt all
  */
public class Light implements Buildable {
  public abstract Color getContribution ( );
}

public class Directional extends Light { }
public class Point extends Light { }

/**
  * @opt all
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

/**
  * @opt all
  */
public class Camera implements Buildable {
  public abstract Ray getRay ( );  
}

public class Perspective extends Camera { }
public class Orthographic extends Camera { }

public class Material implements Buildable { }

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
public class PointBuilder extends Builder { }
