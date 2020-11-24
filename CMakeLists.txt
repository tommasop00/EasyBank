cmake_minimum_required(VERSION 3.17)
project(EasyBank)

set(CMAKE_CXX_STANDARD 14)

add_executable(EasyBank main.cpp Observer.h Subject.h Bank.cpp Bank.h Account.cpp Account.h Private.cpp Private.h Public.cpp Public.h)