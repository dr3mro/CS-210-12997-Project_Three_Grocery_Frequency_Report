CXX       ?= c++
CXXFLAGS  ?= -std=c++17 -Wall -Wextra -pedantic
CPPFLAGS  ?= -Iinclude -I.
RELEASE_CXXFLAGS ?= $(CXXFLAGS) -O2
DEBUG_CXXFLAGS   ?= $(CXXFLAGS) -g -O0
RELEASE_TARGET   ?= build/release/grocery
DEBUG_TARGET     ?= build/debug/grocery
DEBUGGER         ?= $(shell command -v lldb 2>/dev/null || command -v gdb 2>/dev/null)

SRC       := main.cpp $(shell find src -type f -name '*.cpp' 2>/dev/null)
RELEASE_OBJ := $(patsubst %.cpp,build/release/obj/%.o,$(SRC))
DEBUG_OBJ   := $(patsubst %.cpp,build/debug/obj/%.o,$(SRC))
DEP         := $(RELEASE_OBJ:.o=.d) $(DEBUG_OBJ:.o=.d)

.PHONY: all clean release run debug docs

all: release

release: $(RELEASE_TARGET)

$(RELEASE_TARGET): $(RELEASE_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(RELEASE_CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/release/obj/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(RELEASE_CXXFLAGS) -MMD -MP -c $< -o $@

$(DEBUG_TARGET): $(DEBUG_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(DEBUG_CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/debug/obj/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(DEBUG_CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

run: $(RELEASE_TARGET)
	./$(RELEASE_TARGET)

debug: $(DEBUG_TARGET)
	@test -n "$(DEBUGGER)" && command -v $(DEBUGGER) >/dev/null 2>&1 || { echo "Error: lldb or gdb is not installed."; exit 1; }
	$(DEBUGGER) $(DEBUG_TARGET)

docs:
	@command -v doxygen >/dev/null 2>&1 || { echo "Error: doxygen is not installed."; exit 1; }
	@mkdir -p docs
	@doxygen Doxyfile

clean:
	$(RM) -r build