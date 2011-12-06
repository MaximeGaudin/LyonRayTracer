DEPS=$(shell find src/)
OUTPUT=proof.pdf

all: tmp/main.pdf
	
tmp/main.pdf: ${DEPS} 
	@mkdir tmp 2>/dev/null; true
	@echo "Compiling ..." && cd src/ && pdflatex -output-directory ../tmp/ -halt-on-error -shell-escape main.tex || (cat ../tmp/main.log | grep -A 20 "!" ; exit 1)
	open tmp/main.pdf

proof:
	@mkdir tmp 2>/dev/null; true
	@echo "Compiling (1/3)..." && cd src/ && pdflatex -output-directory ../tmp/ -halt-on-error -shell-escape main.tex >/dev/null || (cat ../tmp/main.log | grep -A 20 "!" ; exit 1)
	-@echo "Bibtex (1/1)..." && cp src/references.bib tmp/ && cd tmp/ && bibtex main >/dev/null
	@echo "Glossary (1/1)..." && cd tmp/ && makeindex -s main.ist -t main.alg -o main.acr main.acn >/dev/null
	@echo "Compiling (2/3)..." && cd src/ && pdflatex -output-directory ../tmp/ -shell-escape main.tex >/dev/null
	@echo "Compiling (3/4)..." && cd src/ && pdflatex -output-directory ../tmp/ -shell-escape main.tex >/dev/null
	@cp tmp/main.pdf ${OUTPUT} && open ${OUTPUT}


clean:
	@rm tmp/main.pdf 2>/dev/null; true
	@rm ${OUTPUT} 2>/dev/null; true

mrproper: clean
	@rm -rf tmp 2>/dev/null; true
	@rm src/main.pyg 2>/dev/null; true
