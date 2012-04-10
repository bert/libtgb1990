tex_SOURCES := $(wildcard *.tex)

gif_TARGETS := $(patsubst %.tex,%.gif,$(tex_SOURCES))

%.gif: %.tex
	./textogif -res 0.2 -dpi 150 $<

.DEFAULT_GOAL := all

all: \
	$(gif_TARGETS)

clean:
	rm *.gif *.aux *.log *.dvi *.ps

