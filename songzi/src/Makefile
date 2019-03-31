LIBS=-lcppcms -lbooster

all: clean sz_svr

sz_svr: sz_svr.cpp user.cpp
	$(CXX) $(CXXFLAGS) -Wall sz_svr.cpp user.cpp -o sz_svr $(LIBS)

clean:
	rm -fr sz_svr *.exe *.so cppcms_rundir
