# Makefile
# @author rvarago

CXX		= g++
CXXFLAGS	= -std=c++17 -Wall -c
LDFLAGS_TEST	= -lgtest -lpthread

RMCMD		= rm
RMFLAGS		= -rf

EXEC		= rpncalc
EXEC_TEST	= rpncalc_test
OBJS		= parser.o parser_builder.o

.PHONY: all test clean

all: $(EXEC)

test: $(EXEC_TEST)

$(EXEC): main.o $(OBJS) 
	$(CXX) -o $@ $^ 

$(EXEC_TEST): parser_test.o $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS_TEST)

%.o: %.cpp %.h
	$(CXX) -o $@ $< $(CXXFLAGS)

clean: 
	$(RMCMD) $(RMFLAGS) $(EXEC) $(EXEC_TEST) $(OBJS) main.o parser_test.o
