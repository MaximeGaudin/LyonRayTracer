all: bin doc

doc: doc/html/index.html doc/latex/refman.pdf

bin: code/lrt

code/lrt:
	cd code && ninja

doc/html/index.html:
	doxygen 

doc/latex/refman.pdf:
	doxygen

clean:
	rm -rf doc/html
	rm -rf doc/latex
	rm code/lrt
