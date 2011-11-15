AUTOMAKE_OPTIONS= subdir-objects
ACLOCAL_AMFLAGS= ${ACLOCAL_FLAGS}

bin_PROGRAMS= lrt 
lrt_SOURCES= ./src/Cameras/Perspective.cc ./src/exceptions.cc ./src/Geometry/Box.cc ./src/Geometry/Geometry.cc ./src/Geometry/Mesh.cc ./src/Geometry/Plane.cc ./src/Geometry/Sphere.cc ./src/Geometry/Triangle.cc ./src/Graphics/Image.cc ./src/Graphics/JPGWriter.cc ./src/Graphics/PNGWriter.cc ./src/Lights/AreaLight.cc ./src/Lights/Directional.cc ./src/Lights/Point.cc ./src/main.cc ./src/Material.cc ./src/MeshImporters/MeshImporter3ds.cc ./src/Optimization/OctreeNode.cc ./src/Ray.cc ./src/Samplers/DefaultSampler.cc

if HAVE_DOXYGEN
doxyfile.stamp:
	@echo "Building documentation..."
	@$(DOXYGEN) Doxyfile >/dev/null
if HAVE_LATEX
	@cd doc/latex && make >/dev/null
endif
	@echo Timestamp > doxyfile.stamp

CLEANFILES = doxyfile.stamp

all-local: doxyfile.stamp

endif

mrproper: clean

