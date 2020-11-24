cmake_minimum_required(VERSION 3.17)
project(EasyBank)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)
set(SOURCE_FILES Observer.h Subject.h Bank.cpp Bank.h Account.cpp Account.h Private.cpp Private.h Public.cpp Public.h)

add_executable(EasyBank main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(EasyBank core)