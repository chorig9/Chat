CXX := clang++
CXXFLAGS := -O2 -std=c++11 -stdlib=libstdc++ -march=native -ggdb -pipe -Wall -Wextra -Wshadow $(EXTRA_CXXFLAGS)
LDFLAGS := -lsqlite3 -lboost_system -lboost_date_time
CLANG_FORMAT := $(shell command -v clang-format-3.8 2> /dev/null)

CPP_FILES := $(wildcard *.cpp)
OBJECTS := $(CPP_FILES:.cpp=.o)
LIBS := $(wildcard libs/*.a)

main: $(OBJECTS) $(LIBS)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

format:
ifndef CLANG_FORMAT
	clang-format -i *.cpp *.h
else
	clang-format-3.8 -i *.cpp *.h
endif

clean:
	rm -f *.o
	rm -f main

.PHONY: clean format

CXXFLAGS += -MMD
-include $(OBJECTS:.o=.d)
