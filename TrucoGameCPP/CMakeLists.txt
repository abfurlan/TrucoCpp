# CMakeList.txt : CMake project for TrucoGameCPP, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

project ("TrucoCPP")

include(FetchContent)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(FETCHCONTENT_QUIET FALSE)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

#Dear SFML
FetchContent_Declare(
    SFML
    URL https://github.com/SFML/SFML/archive/69ea0cd863aed1d4092b970b676924a716ff718b.zip
)
FetchContent_MakeAvailable(SFML)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR}/bin)

# Add source to this project's executable.
add_executable (TrucoCPP "TrucoGameCPP.cpp" "TrucoGameCPP.h")

target_link_libraries(TrucoCPP sfml-graphics)

install(TARGETS TrucoCPP 
ARCHIVE DESTINATION "teste/lib"
RUNTIME DESTINATION "teste/lib")
install(DIRECTORY "include"
        DESTINATION "teste"
)

# TODO: Add tests and install targets if needed.
