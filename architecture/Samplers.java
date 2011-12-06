public interface Buildable { }

/**
  * @opt all
  */
public class Sampler {
  public abstract void getRays ( );
}

public class DefaultSampler extends Sampler { }
public class SuperSampler extends Sampler { }
public class AdaptativeSampler extends Sampler { }
