cmake_minimum_required(VERSION 3.15...4.4)

project(HTTP_Server VERSION 1.0
                    DESCRIPTION "A Multithreaded HTTP Server in C++"
                    LANGUAGES CXX)
                    
add_subdirectory(src)
add_subdirectory(apps)