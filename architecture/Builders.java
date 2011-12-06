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

