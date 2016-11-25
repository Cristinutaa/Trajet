cmake_minimum_required(VERSION 3.6)
project(Trajet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Trajet.cpp Trajet.h TrajetCompose.cpp TrajetCompose.h TrajetSimple.cpp TrajetSimple.h Catalogue.cpp Catalogue.h TabDynamique.cpp TabDynamique.h)
add_executable(Trajet ${SOURCE_FILES})