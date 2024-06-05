# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/fullBread_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/fullBread_autogen.dir/ParseCache.txt"
  "fullBread_autogen"
  )
endif()
