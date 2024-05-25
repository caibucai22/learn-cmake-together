cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

file(MAKE_DIRECTORY unzip)

set(my_archive txts.tar)
file(ARCHIVE_EXTRACT INPUT ${my_archive} DESTINATION unzip/ VERBOSE)