# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BD_course_autogen"
  "CMakeFiles\\BD_course_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BD_course_autogen.dir\\ParseCache.txt"
  )
endif()
