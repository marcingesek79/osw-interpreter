cmake_minimum_required (VERSION 3.10)

add_executable (osw-interpreter "main.cpp")
target_link_libraries (osw-interpreter PRIVATE fmt::fmt)

if(MSVC)
  target_compile_options(osw-interpreter PRIVATE /W4 /WX)
else()
  target_compile_options(osw-interpreter PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
