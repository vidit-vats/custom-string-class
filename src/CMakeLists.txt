add_library(custom_string
  string.cc
)
target_include_directories(custom_string
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)
