cmake_minimum_required(VERSION 3.17)
project(geometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(geometry Point.cpp Point.hpp Line.cpp Line.hpp Shape.cpp Shape.hpp Polygon.cpp Polygon.hpp Ellipse.cpp Ellipse.hpp main.cpp Circle.cpp Circle.hpp Rectangle.cpp Rectangle.hpp Square.cpp Square.hpp Triangle.cpp Triangle.hpp)