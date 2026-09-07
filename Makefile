CXX ?= g++
CPPFLAGS += -Iinclude
CXXFLAGS ?= -std=c++17 -Wall -Wextra -O2

BUILD_DIR := build
COMMON_SOURCES := $(wildcard src/*.cpp)
HOMEWORK_SOURCES := $(wildcard src/homework/*.cpp)
CHECKER_OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,tools/checker.cpp $(COMMON_SOURCES) $(HOMEWORK_SOURCES))
HASH_OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,tools/hash-viewer.cpp $(COMMON_SOURCES))
OBJECTS := $(sort $(CHECKER_OBJECTS) $(HASH_OBJECTS))

ifeq ($(OS),Windows_NT)
SHELL := cmd.exe
.SHELLFLAGS := /C
EXE := .exe
mkdir = if not exist "$(subst /,\,$1)" mkdir "$(subst /,\,$1)"
else
EXE :=
mkdir = mkdir -p "$1"
endif

.PHONY: all checker hash-viewer check clean
all: checker hash-viewer

checker: $(BUILD_DIR)/checker$(EXE)
hash-viewer: $(BUILD_DIR)/hash-viewer$(EXE)

$(BUILD_DIR)/checker$(EXE): $(CHECKER_OBJECTS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BUILD_DIR)/hash-viewer$(EXE): $(HASH_OBJECTS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	$(call mkdir,$(@D))
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

check: checker
ifeq ($(OS),Windows_NT)
	.\$(BUILD_DIR)\checker$(EXE)
else
	./$(BUILD_DIR)/checker$(EXE)
endif

clean:
ifeq ($(OS),Windows_NT)
	if exist "$(BUILD_DIR)" rmdir /S /Q "$(BUILD_DIR)"
else
	rm -rf "$(BUILD_DIR)"
endif

-include $(OBJECTS:.o=.d)
