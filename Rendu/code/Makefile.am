AUTOMAKE_OPTIONS= subdir-objects
ACLOCAL_AMFLAGS= ${ACLOCAL_FLAGS}

bin_PROGRAMS= lrt 
lrt_SOURCES= ./src/Builders/Builder.cc ./src/Builders/AreaBuilder.cc ./src/Builders/MaterialBuilder.cc ./src/Builders/MeshBuilder.cc ./src/Builders/PerspectiveDOFBuilder.cc ./src/Builders/PerspectiveBuilder.cc ./src/Builders/PlaneBuilder.cc ./src/Builders/PointBuilder.cc ./src/Builders/SphereBuilder.cc ./src/Cameras/PerspectiveDOF.cc ./src/Cameras/Perspective.cc ./src/exceptions.cc ./src/Geometry/Box.cc ./src/Geometry/Geometry.cc ./src/Geometry/Mesh.cc ./src/Geometry/Plane.cc ./src/Geometry/Sphere.cc ./src/Geometry/Triangle.cc ./src/Graphics/Image.cc ./src/Graphics/ImageFactory.cc ./src/Graphics/PNGHandler.cc ./src/Lights/Area.cc ./src/Lights/Directional.cc ./src/Lights/Point.cc ./src/main.cc ./src/Material.cc ./src/MeshImporters/MeshImporter3ds.cc ./src/Optimization/OctreeNode.cc ./src/Ray.cc ./src/Samplers/DefaultSampler.cc ./src/Scene/SceneReader.cc

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

