

# Change EXECUTABLE to match the command name given in the project spec.
EXECUTABLE 	= roll.exe

# designate which compiler to use
CXX			= g++

# list of sources used in project
SOURCES 	= $(wildcard Rolls/*.cpp)
SOURCES     := $(filter-out $(TESTSOURCES), $(SOURCES))
# list of objects used in project
OBJECTS		= $(SOURCES:%.cpp=%.o)

PROJECTFILE = Rolls/_rolls.cpp


#Default Flags
CXXFLAGS = -std=c++14 -Wall -Werror -Wextra -pedantic 

# make release - will compile "all" with $(CXXFLAGS) and the -O3 flag
#				 also defines NDEBUG so that asserts will not check
release: CXXFLAGS += -O3 -DNDEBUG
release: all

# make debug - will compile "all" with $(CXXFLAGS) and the -g flag
#              also defines DEBUG so that "#ifdef DEBUG /*...*/ #endif" works
debug: CXXFLAGS += -g3 -DDEBUG
debug: clean all

# make profile - will compile "all" with $(CXXFLAGS) and the -pg flag
profile: CXXFLAGS += -pg
profile: clean all

# highest target; sews together all objects into executable
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
ifeq ($(EXECUTABLE), executable)
	@echo Edit EXECUTABLE variable in Makefile.
	@echo Using default a.out.
	$(CXX) $(CXXFLAGS) $(OBJECTS)
else
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)
endif

# Automatically generate any build rules for test*.cpp files
define make_tests
SRCS = $$(filter-out $$(PROJECTFILE), $$(SOURCES))
OBJS = $$(SRCS:%.cpp=%.o)
HDRS = $$(wildcard *.h)
$(1): CXXFLAGS += -g3 -DDEBUG
$(1): $$(OBJS) $$(HDRS) $(1).cpp
ifeq ($$(PROJECTFILE),)
	@echo Edit PROJECTFILE variable to .cpp file with main\(\)
	@exit 1
endif
	$$(CXX) $$(CXXFLAGS) $$(OBJS) $(1).cpp -o $(1)
endef
$(foreach test, $(TESTS), $(eval $(call make_tests, $(test))))

alltests: clean $(TESTS)

# rule for creating objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

# make clean - remove .o files, executables, tarball
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TESTS) $(PARTIAL_SUBMITFILE) $(FULL_SUBMITFILE)

# make partialsubmit.tar.gz - cleans, runs dos2unix, creates tarball omitting test cases
PARTIAL_SUBMITFILES=$(filter-out $(TESTSOURCES), $(wildcard Makefile *.h *.cpp))
$(PARTIAL_SUBMITFILE): $(PARTIAL_SUBMITFILES)
	rm -f $(PARTIAL_SUBMITFILE) $(FULL_SUBMITFILE)
	-dos2unix $(PARTIAL_SUBMITFILES)
	tar -vczf $(PARTIAL_SUBMITFILE) $(PARTIAL_SUBMITFILES)
	@echo !!! WARNING: No test cases included. Use 'make fullsubmit' to include test cases. !!!

# make fullsubmit.tar.gz - cleans, runs dos2unix, creates tarball including test cases
FULL_SUBMITFILES=$(filter-out $(TESTSOURCES), $(wildcard Makefile *.h *.cpp test*.txt))
$(FULL_SUBMITFILE): $(FULL_SUBMITFILES)
	rm -f $(PARTIAL_SUBMITFILE) $(FULL_SUBMITFILE)
	-dos2unix $(FULL_SUBMITFILES)
	tar -vczf $(FULL_SUBMITFILE) $(FULL_SUBMITFILES)
	@echo !!! Final submission prepared, test cases included... READY FOR GRADING !!!


#######################
# TODO (begin) #
#######################
# individual dependencies for objects
# Examples:
# "Add a header file dependency"
# project2.o: project2.cpp project2.h
#
# "Add multiple headers and a separate class"
# HEADERS = some.h special.h header.h files.h
# myclass.o: myclass.cpp myclass.h $(HEADERS)
# project5.o: project5.cpp myclass.o $(HEADERS)
#
# ADD YOUR OWN DEPENDENCIES HERE

# tests

class.o: class.cpp class.h

project0.o: project0.cpp class.h

######################
# TODO (end) #
######################

# these targets do not create any files
.PHONY: all release debug profile clean alltests partialsubmit fullsubmit help
# disable built-in rules
.SUFFIXES:
