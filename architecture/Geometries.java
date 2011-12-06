public interface Buildable { }

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
public class Quadric extends Geometry { }
