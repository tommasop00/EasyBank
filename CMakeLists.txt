cmake_minimum_required(VERSION 3.5)
project(EasyBank)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_subdirectory(cmake-build-debug/test)

set(SOURCE_FILES Observer.h Subject.h Account/Account.cpp Account/Account.h Account/MyAccount.cpp Account/MyAccount.h Account/Transaction.cpp Account/Transaction.h FileManager.cpp FileManager.h Account/TransactionError.h)

add_executable(EasyBank main.cpp MethodClass.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(EasyBank core)