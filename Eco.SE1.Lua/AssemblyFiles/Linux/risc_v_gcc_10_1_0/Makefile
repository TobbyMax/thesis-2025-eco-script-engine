﻿ifeq ($(OS), Windows_NT)
	#WINDOWS USE THESE DEFINITIONS
	RM = -del /q /f
	SLASH = \\
	SWALLOW_OUTPUT = >nul 2>nul
	TOOLCHAIN = 
	TOOL = 
else
	#LINUX USE THESE DEFINITIONS
	RM = -rm -f
	SLASH = /
	SWALLOW_OUTPUT =
	TOOLCHAIN = 
	TOOL = 
endif 

ifeq ($(TARGET), 1)
OUT_TARGET = libA42A420FC14D43879877877F8E62028C.a
ifeq ($(DEBUG), 1)
CONFIG_TARGET = StaticDebug
CCFLAGS_TARGET = -Wall -g -DECO_LIB
LDFLAGS_TARGET =
ARCH_TARGET = rv64gcv
else
CONFIG_TARGET = StaticRelease
CCFLAGS_TARGET = -O3 -DECO_LIB
LDFLAGS_TARGET =
ARCH_TARGET = rv64gcv
endif
else
OUT_TARGET = A42A420FC14D43879877877F8E62028C.so
ifeq ($(DEBUG), 1)
CONFIG_TARGET = DynamicDebug
CCFLAGS_TARGET = -Wall -fPIC -g -DECO_DLL
LDFLAGS_TARGET = -shared
ARCH_TARGET = rv64gcv
else
CONFIG_TARGET = DynamicRelease
CCFLAGS_TARGET = -O3 -fPIC -DECO_DLL
LDFLAGS_TARGET = -shared
ARCH_TARGET = rv64gcv
endif
endif

# include directories
INC = \
-I ..$(SLASH)..$(SLASH)..$(SLASH)HeaderFiles \
-I ..$(SLASH)..$(SLASH)..$(SLASH)SharedFiles \
-I $(ECO_FRAMEWORK)$(SLASH)Eco.Core1$(SLASH)SharedFiles \
-I $(ECO_FRAMEWORK)$(SLASH)Eco.InterfaceBus1$(SLASH)SharedFiles \
-I $(ECO_FRAMEWORK)$(SLASH)Eco.MemoryManager1$(SLASH)SharedFiles \
-I $(ECO_FRAMEWORK)$(SLASH)Eco.FileSystemManagement1$(SLASH)SharedFiles 


# source files.
SRC = \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoSE1Lua.c \
..$(SLASH)..$(SLASH)..$(SLASH)SourceFiles$(SLASH)CEcoSE1LuaFactory.c

OBJ = $(SRC:.c=.o)

OUT = $(OUT_TARGET)
OUT_DIR = ..$(SLASH)..$(SLASH)..$(SLASH)BuildFiles$(SLASH)Linux$(SLASH)$(ARCH_TARGET)$(SLASH)$(CONFIG_TARGET)

 
# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = $(CCFLAGS_TARGET) -DECO_LINUX -DUGUID_UTILITY
 
# compiler
GNU = $(TOOLCHAIN)
CC = $(TOOL)gcc
AR = $(TOOL)gcc-ar

ifeq ($(TARGET), 1)
CMD_TARGET=$(GNU)$(AR) rcs
else
CMD_TARGET=$(GNU)$(CC) -o
endif

# library paths
LIBS = -lc -lm -lgcc
 
# compile flags
LDFLAGS = $(LDFLAGS_TARGET)
 
.SUFFIXES: .c

all: $(OUT)

.c.o:
	$(GNU)$(CC) $(INC) $(CCFLAGS) -c $< -o $@
 
$(OUT): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(CMD_TARGET) $(OUT_DIR)$(SLASH)$(OUT) $(OBJ) $(LDFLAGS)
	rm $(OBJ)

clean:
	$(RM) $(OBJ) $(OUT_DIR)$(SLASH)$(OUT)
