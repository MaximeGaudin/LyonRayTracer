public interface Buildable { }

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


