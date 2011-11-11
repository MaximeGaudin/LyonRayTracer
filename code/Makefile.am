AUTOMAKE_OPTIONS= subdir-objects
ACLOCAL_AMFLAGS= ${ACLOCAL_FLAGS}

AM_CXXFLAGS=-I/opt/local/include/ -I./ -I./src/ -I./src/Maths/ -I./src/Graphics/ -I./src/Cameras/ -I./src/Geometry/ -I./src/Lights/ -I./src/MeshImporters/ -L/opt/local/lib/ -ljpeg -lpng -l3ds

bin_PROGRAMS= lrt 
lrt_SOURCES= ./src/Cameras/Perspective.cc ./src/DefaultSampler.cc ./src/exceptions.cc ./src/Geometry/Box.cc ./src/Geometry/Mesh.cc ./src/Geometry/Plane.cc ./src/Geometry/Sphere.cc ./src/Geometry/Triangle.cc ./src/Graphics/Image.cc ./src/Graphics/JPGWriter.cc ./src/Graphics/PNGWriter.cc ./src/Lights/Directional.cc ./src/main.cc ./src/Material.cc ./src/MeshImporters/MeshImporter3ds.cc ./src/Ray.cc

if HAVE_DOXYGEN
doxyfile.stamp:
	$(DOXYGEN) Doxyfile
	echo Timestamp > doxyfile.stamp

CLEANFILES = doxyfile.stamp

all-local: doxyfile.stamp

endif