public class Image { }

/**
 * @opt all
 * @navassoc 1 "Manipule" 0..n Image
 */
public interface ImageHandler {
  void Save ( Image img, String filename );

  Image Load ( String filename );
  bool Validate ( String filename );
}

/**
 * @opt all
 * @composed 1 - 0..n ImageHandler
 */
class ImageFactory {
  static void addHandler ( ImageHandler handler );
  static void Save ( Image img, string filename );

  static Image Load ( String filename );
}


