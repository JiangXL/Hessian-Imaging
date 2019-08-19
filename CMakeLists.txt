cmake_minimum_required(VERSION 2.8)

# Executable name
project( hessian )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( hessian hessian.cpp  hessian.h)

target_link_libraries( hessian ${OpenCV_LIBS} )
