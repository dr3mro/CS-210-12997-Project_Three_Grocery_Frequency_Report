CXX       ?= c++
CXXFLAGS  ?= -std=c++17 -Wall -Wextra -pedantic
CPPFLAGS  ?= -Iinclude -I.
RELEASE_CXXFLAGS ?= $(CXXFLAGS) -O2
DEBUG_CXXFLAGS   ?= $(CXXFLAGS) -g -O0 -std=c++17
RELEASE_TARGET   ?= build/release/grocery
DEBUG_TARGET     ?= build/debug/grocery
DEBUGGER         ?= $(shell command -v lldb 2>/dev/null || command -v gdb 2>/dev/null)
DOT              ?= dot

# clang can write compile_commands.json pieces with -MJ (GCC can't, so it's skipped there)
IS_CLANG := $(shell $(CXX) --version 2>/dev/null | grep -qi clang && echo 1)
MJFLAGS   = $(if $(IS_CLANG),-MJ $@.json)
COMPDB   := $(if $(IS_CLANG),compile_commands.json)

SRC       := main.cpp $(shell find src -type f -name '*.cpp' 2>/dev/null)
RELEASE_OBJ := $(patsubst %.cpp,build/release/obj/%.o,$(SRC))
DEBUG_OBJ   := $(patsubst %.cpp,build/debug/obj/%.o,$(SRC))
DEP         := $(RELEASE_OBJ:.o=.d) $(DEBUG_OBJ:.o=.d)
DIAGRAM_TARGETS := diagrams/grocery_flowchart.png diagrams/grocery_class_diagram.png

.PHONY: all clean release run debug docs diagrams

all: release

release: $(RELEASE_TARGET) $(COMPDB)

$(RELEASE_TARGET): $(RELEASE_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(RELEASE_CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/release/obj/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(RELEASE_CXXFLAGS) -MMD -MP $(MJFLAGS) -c $< -o $@

compile_commands.json: $(RELEASE_OBJ)
	@{ echo '['; cat /dev/null $(wildcard $(RELEASE_OBJ:.o=.o.json)) | sed '$$ s/,$$//'; echo ']'; } > $@

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

diagrams: $(DIAGRAM_TARGETS)

diagrams/%.png: diagrams/%.dot
	@command -v $(DOT) >/dev/null 2>&1 || { echo "Error: Graphviz (dot) is not installed."; exit 1; }
	$(DOT) -Tpng $< -o $@

clean:
	$(RM) -r build
