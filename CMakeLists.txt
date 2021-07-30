cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(fsm)
INCLUDE_DIRECTORIES (
	${CMAKE_SOURCE_DIR}
    )
file( GLOB_RECURSE 
        STATES
        ${CMAKE_SOURCE_DIR}/States/*.cpp
    )
add_executable(fsm main.cpp ${STATES} Fan.cpp)
target_link_libraries(fsm pthread)