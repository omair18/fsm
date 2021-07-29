cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(fsm)

add_executable(fsm main.cpp ConcreteFanStates.cpp Fan.cpp)
target_link_libraries(fsm pthread)