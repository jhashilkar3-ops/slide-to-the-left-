cmake_minimum_required(VERSION 3.24)

project(slide_to_the_left)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(slide_test tests/slide_test.cpp src/slide.cpp)
add_executable(main main.cpp src/slide.cpp)

target_link_libraries(slide_test PRIVATE Catch2::Catch2WithMain)
