cmake_minimum_required(VERSION 2.8)
project( aigroupproject )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( aigroupproject src/main.cpp )
target_link_libraries( aigroupproject ${OpenCV_LIBS} )
#