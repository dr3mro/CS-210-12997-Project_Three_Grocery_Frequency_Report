CXX       ?= c++
CXXFLAGS  ?= -std=c++17 -Wall -Wextra -pedantic
CPPFLAGS  ?= -Iinclude -I.
RELEASE_CXXFLAGS ?= $(CXXFLAGS) -O2
DEBUG_CXXFLAGS   ?= $(CXXFLAGS) -g -O0
RELEASE_TARGET   ?= build/release/grocery
DEBUG_TARGET     ?= build/debug/grocery
DEBUGGER         ?= $(shell command -v lldb 2>/dev/null || command -v gdb 2>/dev/null)
DOT              ?= dot

# clang can write compile_commands.json pieces with -MJ (GCC can't, so it's skipped there)
IS_CLANG := $(shell $(CXX) --version 2>/dev/null | grep -qi clang && echo 1)
MJFLAGS   = $(if $(IS_CLANG),-MJ $@.json)
comma    := ,

# Merge the per-file pieces for a build ($1 = its object list) into compile_commands.json
define merge_compdb
	$(if $(IS_CLANG),@{ echo '['; for f in $(1:.o=.o.json); do [ -f "$$f" ] && cat "$$f"; done | sed '$$ s/$(comma)$$//'; echo ']'; } > compile_commands.json)
endef

SRC       := main.cpp $(shell find src -type f -name '*.cpp' 2>/dev/null)
RELEASE_OBJ := $(patsubst %.cpp,build/release/obj/%.o,$(SRC))
DEBUG_OBJ   := $(patsubst %.cpp,build/debug/obj/%.o,$(SRC))
DEP         := $(RELEASE_OBJ:.o=.d) $(DEBUG_OBJ:.o=.d)
DIAGRAM_TARGETS := diagrams/grocery_flowchart.png diagrams/grocery_class_diagram.png

.PHONY: all clean-release clean-debug clean-all build-release build-debug run debug-run docs diagrams

all: build-release build-debug

build-release: $(RELEASE_TARGET)
	$(call merge_compdb,$(RELEASE_OBJ))

$(RELEASE_TARGET): $(RELEASE_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(RELEASE_CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/release/obj/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(RELEASE_CXXFLAGS) -MMD -MP $(MJFLAGS) -c $< -o $@

build-debug: $(DEBUG_TARGET)
	$(call merge_compdb,$(DEBUG_OBJ))

$(DEBUG_TARGET): $(DEBUG_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(DEBUG_CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/debug/obj/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(DEBUG_CXXFLAGS) -MMD -MP $(MJFLAGS) -c $< -o $@

-include $(DEP)

run: build-release
	./$(RELEASE_TARGET)

debug-run: build-debug
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

clean-release:
	$(RM) -r build/release

clean-debug:
	$(RM) -r build/debug

clean-all:
	$(RM) -r build
	$(RM) compile_commands.json
