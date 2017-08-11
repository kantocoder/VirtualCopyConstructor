CXX = g++ 
# CXX = clang++
RM = rm

# ========== Directories ==========
SRCDIR := ./src
OBJDIR := .
BINDIR := .

# ============  Flags  ============
CXXFLAGS = -std=c++11  -O2


# ============ Targets ============

all:  main


%:	$(SRCDIR)/%.cpp
	$(CXX) -std=c++11 -o $(BINDIR)/$@  $^


clean:  main
	$(RM) $^

.PHONY: all


