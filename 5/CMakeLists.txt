cmake_minimum_required(VERSION 3.23)
project(program5_template)

set(CMAKE_CXX_STANDARD 14)

add_executable(program5_template main.cpp DLTNetwork.cpp DLTNetwork.h Transaction.cpp Transaction.h Peer.cpp Peer.h User.cpp User.h)
