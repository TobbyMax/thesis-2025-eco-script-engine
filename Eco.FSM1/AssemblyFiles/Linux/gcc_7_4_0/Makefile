ifeq ($(TARGET), 1)
OUT_TARGET = lib5E7C610CB846447DB59A3C5A2C4F446F.a
ifeq ($(DEBUG), 1)
CONFIG_TARGET = StaticDebug
CCFLAGS_TARGET = -Wall -O3 -g -DECO_LIB
LDFLAGS_TARGET =
else
CONFIG_TARGET = StaticRelease
CCFLAGS_TARGET = -O3 -DECO_LIB
LDFLAGS_TARGET =
endif
else
OUT_TARGET = 5E7C610CB846447DB59A3C5A2C4F446F.so
ifeq ($(DEBUG), 1)
CONFIG_TARGET = DynamicDebug
CCFLAGS_TARGET = -Wall -O3 -fPIC -g -DECO_DLL
LDFLAGS_TARGET = -shared
else
CONFIG_TARGET = DynamicRelease
CCFLAGS_TARGET = -O3 -fPIC -DECO_DLL
LDFLAGS_TARGET = -shared
endif
endif

# source files.
SRC = \
../../../SourceFiles/CEcoFSM1.c \
../../../SourceFiles/CEcoFSM1Event.c \
../../../SourceFiles/CEcoFSM1EventProcessing.c \
../../../SourceFiles/CEcoFSM1State.c \
../../../SourceFiles/CEcoFSM1StateMachine.c \
../../../SourceFiles/CEcoFSM1Transition.c \
../../../SourceFiles/CEcoFSM1Factory.c

# include directories
INCLUDES = \
-I ../../../HeaderFiles \
-I ../../../SharedFiles \
-I ../../../../Eco.Core1/SharedFiles \
-I ../../../../Eco.Data1/SharedFiles \
-I ../../../../Eco.List1/SharedFiles \
-I ../../../../Eco.String1/SharedFiles \
-I ../../../../Eco.InterfaceBus1/SharedFiles \
-I ../../../../Eco.MemoryManager1/SharedFiles

OBJ = $(SRC:.c=.o)

OUT = $(OUT_TARGET)
OUT_DIR = ../../../BuildFiles/Linux/x64/$(CONFIG_TARGET)

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = $(CCFLAGS_TARGET) -DECO_LINUX -DUGUID_UTILITY

# compiler
GNU =
CC = gcc
AR = gcc-ar

ifeq ($(TARGET), 1)
CMD_TARGET=$(AR) rcs
else
CMD_TARGET=$(CC) -o
endif

# library paths
LIBS =-lc -lm -lgcc

# link flags
LDFLAGS = $(LDFLAGS_TARGET)

.SUFFIXES: .c

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	mkdir -p $(OUT_DIR)
	$(CMD_TARGET) $(OUT_DIR)/$(OUT) $(OBJ) $(LDFLAGS)
	rm $(OBJ)

clean:
	rm $(OBJ) $(OUT_DIR)/$(OUT)

