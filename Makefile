all: bin doc video

doc: doc/html/index.html doc/latex/refman.pdf

bin: code/lrt

video: gource.webm
	
gource.webm:
	@echo "Encoding repository video..."
	@gource -800x600  --stop-at-end -o - | ffmpeg -y -r 60 -f image2pipe -vcodec ppm -i - -vcodec libvpx -b 10000K gource.webm > /dev/null

code/lrt:
	@echo "Compiling..."
	@cd code && ninja

doc/html/index.html:
	@echo "Building HTML documentation..."
	@doxygen >/dev/null

doc/latex/refman.pdf:
	@echo "Building latex documentation..."
	@doxygen >/dev/null

clean:
	@echo "Cleaning..."
	@rm -rf doc/html
	@rm -rf doc/latex
	@rm code/lrt
	@rm gource.webm

mrproper: clean
	@cd code && ninja -t clean
