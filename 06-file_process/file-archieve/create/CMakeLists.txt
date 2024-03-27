cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

file(TOUCH 1.txt)
file(MAKE_DIRECTORY files/)
file(TOUCH files/1.txt)
file(MAKE_DIRECTORY files/subdir)
file(TOUCH files/subdir/1.txt)



file(ARCHIVE_CREATE OUTPUT txts.tar PATHS 1.txt files/1.txt files/subdir/1.txt FORMAT gnutar VERBOSE)

file(MAKE_DIRECTORY unzip)

set(my_archive txts.tar)
file(ARCHIVE_EXTRACT INPUT ${my_archive} DESTINATION unzip/ VERBOSE)