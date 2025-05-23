cmake_minimum_required(VERSION 3.22)
project(FSM1_UnitTest C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "/TC /Gz")
set(CMAKE_SHARED_LINKER_FLAGS "/DYNAMICBASE")
set(CMAKE_EXE_LINKER_FLAGS "/DYNAMICBASE")
set(CMAKE_EXE_LINKER_FLAGS "/NODEFAULTLIB:libcmt.lib")

add_definitions(-DECO_WINDOWS)
add_definitions(-D_DEBUG)
add_definitions(-DECO_DLL)
add_definitions(-DUGUID_UTILITY)
add_definitions(-DECO_X86_32)
add_definitions(-DECO_WIN32)
add_definitions(-DWIN32)
add_definitions(-D_WINDOWS)
add_definitions(-D_CONSOLE)

include_directories(../../../HeaderFiles)
include_directories(../../../SharedFiles)
include_directories(../../../../Eco.Data1/HeaderFiles)
include_directories(../../../../Eco.Data1/SharedFiles)

include_directories(
        $ENV{ECO_FRAMEWORK}/Eco.List1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Core1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.System1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Data1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.String1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.Log1/SharedFiles
        $ENV{ECO_FRAMEWORK}/Eco.DateTime1/SharedFiles
)

add_library(
        5A0F0DD57E6448EC9EE0E5D67572B47E
        SHARED

        ../../../../Eco.Data1/SharedFiles/IdEcoData1.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Factory.h
        ../../../../Eco.Data1/HeaderFiles/CEcoData1.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1.c
        ../../../../Eco.Data1/SourceFiles/CEcoData1Factory.c


        ../../../../Eco.Data1/SourceFiles/CEcoData1Column.c
        ../../../../Eco.Data1/HeaderFiles/CEcoData1Column.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Column.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Row.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Row.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1Row.c

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Table.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Table.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1Table.c

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Item.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Item.h
        ../../../../Eco.Data1/SourceFiles/CEcoData1Item.c
)

add_library(
        5E7C610CB846447DB59A3C5A2C4F446F
        SHARED
        ../../../SourceFiles/CEcoFSM1.c
        ../../../SourceFiles/CEcoFSM1Factory.c
        ../../../SharedFiles/IdEcoFSM1.h
        ../../../SharedFiles/IEcoFSM1.h
        ../../../SharedFiles/IEcoFSM1State.h
        ../../../HeaderFiles/CEcoFSM1.h
        ../../../HeaderFiles/CEcoFSM1Factory.h

        ../../../SourceFiles/CEcoFSM1Event.c
        ../../../HeaderFiles/CEcoFSM1Event.h

        ../../../SourceFiles/CEcoFSM1State.c
        ../../../HeaderFiles/CEcoFSM1State.h

        ../../../SourceFiles/CEcoFSM1Transition.c
        ../../../HeaderFiles/CEcoFSM1Transition.h

        ../../../SourceFiles/CEcoFSM1StateMachine.c
        ../../../HeaderFiles/CEcoFSM1StateMachine.h

        ../../../SourceFiles/CEcoFSM1EventProcessing.c
        ../../../HeaderFiles/CEcoFSM1EventProcessing.h

        ../../../SharedFiles/IEcoFL1.h

        ../../../SourceFiles/CEcoFL1Alphabet.c
        ../../../HeaderFiles/CEcoFL1Alphabet.h

        ../../../SourceFiles/CEcoFL1SymbolSet.c
        ../../../HeaderFiles/CEcoFL1SymbolSet.h
)

add_executable(
        UnitTest
        ../../../UnitTestFiles/SourceFiles/EcoFSM1.c

        ../../../SharedFiles/IdEcoFSM1.h
        ../../../SharedFiles/IEcoFSM1.h
        ../../../HeaderFiles/CEcoFSM1.h
        ../../../HeaderFiles/CEcoFSM1Factory.h

        ../../../HeaderFiles/CEcoFSM1Event.h
        ../../../HeaderFiles/CEcoFSM1State.h
        ../../../HeaderFiles/CEcoFSM1Transition.h
        ../../../HeaderFiles/CEcoFSM1StateMachine.h
        ../../../HeaderFiles/CEcoFSM1EventProcessing.h

        ../../../SharedFiles/IEcoFL1.h
        ../../../HeaderFiles/CEcoFL1Alphabet.h
        ../../../HeaderFiles/CEcoFL1SymbolSet.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Factory.h
        ../../../../Eco.Data1/HeaderFiles/CEcoData1.h

        ../../../../Eco.Data1/SharedFiles/IdEcoData1.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Column.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Column.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Row.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Row.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Table.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Table.h

        ../../../../Eco.Data1/HeaderFiles/CEcoData1Item.h
        ../../../../Eco.Data1/SharedFiles/IEcoData1Item.h
)

target_link_libraries(
        UnitTest
        $ENV{ECO_FRAMEWORK}/Eco.InterfaceBus1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000042757331.lib
        $ENV{ECO_FRAMEWORK}/Eco.MemoryManager1/BuildFiles/Windows/x86/StaticRelease/0000000000000000000000004D656D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.FileSystemManagement1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000046534D31.lib
        $ENV{ECO_FRAMEWORK}/Eco.System1/BuildFiles/Windows/x86/StaticRelease/00000000000000000000000053595332.lib
        $ENV{ECO_FRAMEWORK}/Eco.List1/BuildFiles/Windows/x86/StaticRelease/53884AFC93C448ECAA929C8D3A562281.lib
        $ENV{ECO_FRAMEWORK}/Eco.String1/BuildFiles/Windows/x86/StaticRelease/84CC0A7DBABD44EEBE749C9A8312D37E.lib
        $ENV{ECO_FRAMEWORK}/Eco.Log1/BuildFiles/Windows/x86/StaticRelease/97322B6765B74342BBCE38798A0B40B5.lib
        $ENV{ECO_FRAMEWORK}/Eco.DateTime1/BuildFiles/Windows/x86/StaticRelease/5B2BA17BEA704527BC708F88568FE115.lib

        5E7C610CB846447DB59A3C5A2C4F446F
        5A0F0DD57E6448EC9EE0E5D67572B47E
)