CXX      ?= c++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic
CPPFLAGS ?= -Iinclude -I.
DEBUGGER ?= $(shell command -v lldb || command -v gdb)

SRC         := main.cpp $(shell find src -name '*.cpp')
RELEASE_OBJ := $(SRC:%.cpp=build/release/obj/%.o)
DEBUG_OBJ   := $(SRC:%.cpp=build/debug/obj/%.o)

.PHONY: all build-release build-debug run debug-run clean-release clean-debug clean-all docs diagrams compile_commands.json

all: build-release build-debug

build-release: build/release/grocery compile_commands.json
build-debug:   build/debug/grocery compile_commands.json

run: build-release
	./build/release/grocery

debug-run: build-debug
	$(or $(DEBUGGER),$(error lldb or gdb is not installed)) build/debug/grocery

# ---- release ----
build/release/grocery: $(RELEASE_OBJ)
	$(CXX) $^ -o $@

build/release/obj/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -O2 -MMD -MP -c $< -o $@

# ---- debug ----
build/debug/grocery: $(DEBUG_OBJ)
	$(CXX) $^ -o $@

build/debug/obj/%.o: %.cpp Makefile
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -g -O0 -MMD -MP -c $< -o $@

-include $(RELEASE_OBJ:.o=.d) $(DEBUG_OBJ:.o=.d)

# ---- editor support (clangd): one entry per source file, rewritten on every build ----
compile_commands.json:
	@{ echo '['; for f in $(SRC); do \
	    echo "  {\"directory\": \"$(CURDIR)\", \"file\": \"$$f\", \"command\": \"$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $$f\"},"; \
	  done | sed '$$ s/,$$//'; echo ']'; } > $@

# ---- docs and diagrams ----
docs:
	doxygen Doxyfile

diagrams: diagrams/grocery_flowchart.png diagrams/grocery_class_diagram.png

diagrams/%.png: diagrams/%.dot
	dot -Tpng $< -o $@

# ---- cleaning ----
clean-release:
	rm -rf build/release

clean-debug:
	rm -rf build/debug

clean-all:
	rm -rf build compile_commands.json
