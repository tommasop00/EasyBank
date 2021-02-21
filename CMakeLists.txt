cmake_minimum_required(VERSION 3.5)
project(EasyBank)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_subdirectory(cmake-build-debug/test)

set(SOURCE_FILES Observer.h Subject.h Account/Account.cpp Account/Account.h Account/User.cpp Account/User.h Account/Movements.cpp Account/Movements.h FileManager/FileManager.cpp FileManager/FileManager.h Account/MovementError.h FileManager/AccountFileManager.cpp FileManager/AccountFileManager.h FileManager/UserFileManager.cpp FileManager/UserFileManager.h FileManager/LogFileManager.cpp FileManager/LogFileManager.h Account/Transaction.cpp Account/Transaction.h)

add_executable(EasyBank main.cpp Utility.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(EasyBank core)