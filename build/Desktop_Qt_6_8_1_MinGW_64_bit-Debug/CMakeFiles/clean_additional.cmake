# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\spammer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\spammer_autogen.dir\\ParseCache.txt"
  "spammer_autogen"
  )
endif()
