cmake_minimum_required(VERSION 3.22)

project(cmake_component)

file(WRITE a.cpp "")
file(WRITE doc.html "")

install(FILES a.cpp
DESTINATION src COMPONENT src
)

install(FILES doc.html
DESTINATION doc COMPONENT src
)

# cmake -S . -B build -DCMAKE_INSTALL_PREFIX=out
# cd build
# cmake -DCOMPONENT=src -P cmake_install.cmake
# cmake -DCOMPONENT=doc -P cmake_install.cmake