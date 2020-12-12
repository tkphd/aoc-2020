exe: a.out b.out

all: $(exe)
.PHONY: all clean run

%.out: %.cpp
	g++ -O3 -Wall -fopenmp $< -o $@

run: a.out b.out
	./a.out < input.txt && ./b.out < input.txt

clean:
	rm -vf *.out
