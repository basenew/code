cc = g++
prom = server
deps = $(shell find . -name "*.h"  ! -path "./test*/*")
src = $(shell find . -name "*.cpp" ! -path "./test*/*")
obj = $(src:%.cpp=%.o) 

$(prom): $(obj)
	$(cc) -o $(prom) $(obj)

%.o: %.cpp $(deps)
	$(cc) -c $< -o $@ -std=c++11

clean:
	rm -rf $(obj) $(prom) *.gch

