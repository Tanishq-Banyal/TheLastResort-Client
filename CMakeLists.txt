cmake_minimum_required(VERSION 3.10)

project(TheLastResort-Client)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# --------------COMPILER SPECIFIC---------------- #

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "-O3 -Wall -flto -fsanitize=address -stdlib=libc++")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(CMAKE_CXX_FLAGS "-O3 -Wall -flto -fsanitize=address -s")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
#	Nobody Uses Windows Anyways ;)
#	set(CMAKE_CXX_FLAGS "/O1 /strip /Wall")
	MESSAGE("For MSVC you need to Compile Manually !!")
endif()

# ----------------------------------------------- #

add_executable(TheLastResort-Client "main.cpp")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CNGui)
target_link_libraries(cngui)

target_link_libraries(TheLastResort-Client sfml-audio sfml-system sfml-window sfml-network sfml-graphics)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets
	 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})