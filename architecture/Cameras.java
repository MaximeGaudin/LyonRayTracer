public interface Buildable { }

/**
  * @opt all
  */
public class Camera implements Buildable {
  public abstract Ray getRay ( );  
}

public class Perspective extends Camera { }
public class PerspectiveDOF extends Camera { }
public class Orthographic extends Camera { }
public class FishEye extends Camera { }


