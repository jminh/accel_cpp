
SOURCES=$(wildcard *.cc)
OBJECTS=$(patsubst %.cc,%.o,$(SOURCES))

CXXFLAGS := -I../include

PHONY := all

all: $(OBJECTS)
#	$(V)$(CXX) -o $@ $^

ifeq (@, $(V))
%.o: %.cc
	@$(CXX) -c $< $(CXXFLAGS)
	@echo Compile -  $<
else
%.o: %.cc
	$(CXX) -c $< $(CXXFLAGS)
endif

clean:
	rm -rf *.o
