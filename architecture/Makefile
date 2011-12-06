SRC_DIR=.

SRC_FILES=$(wildcard *.java)
PDF_FILES=$(patsubst %.java,%.pdf,$(SRC_FILES))

all: ${PDF_FILES} 

sequence.pdf: sequence.pic
	@echo "Building $@..."
	@pic2plot -Tps sequence.pic > sequence.ps && ps2pdf sequence.ps && rm sequence.ps

%.pdf: %.java
	@echo "Building $@..."
	@bin/umlgraph $(basename $^) pdf >/dev/null 


.PHONY: clean mrproper

clean:
	rm *.pdf

mrproper: clean
