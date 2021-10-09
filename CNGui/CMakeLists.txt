cmake_minimum_required(VERSION 3.11)

set(CNGUI_SHARED_LIBS TRUE CACHE BOOL "Build shared libraries (use shared SFML librares)")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(cngui)

set(cngui_VERSION_MAJOR 1)
set(cngui_VERSION_MINOR 0)

if(NOT CNGUI_SHARED_LIBS)
	set(SFML_STATIC_LIBRARIES TRUE)
endif()

#set(SFML_DIR "" CACHE PATH "Folder that contains SFMLConfig.cmake (usually in lib/cmake/SFML/)")

#if(NOT SFML_DIR)
#	message(SEND_ERROR "Please provide path for the folder that contains SFMLConfig.cmake in SFML_DIR (usually SFML/lib/cmake/SFML/)")
#endif()

find_package(OpenGL REQUIRED)
find_package(SFML COMPONENTS graphics main QUIET)

if(SFML_FOUND)
	message(STATUS "Found SFML in ${SFML_DIR}")
endif()

# Define sources
set(INCLUDE_PATH "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_PATH "${CMAKE_SOURCE_DIR}/src")

include_directories("${INCLUDE_PATH}")
include_directories("${SOURCE_PATH}")

add_library(cngui
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/CNGui.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Core/Style.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Core/Registration.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Core/EventHandler.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Core/Updatable.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Core/Container.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/Object.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/Button.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/ProgressIndicator.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/LineEdit.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/Poster.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/Category.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/KeyEdit.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/Box.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/Slider.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Objects/LineSelect.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Tools/Text.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Tools/Shape.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Tools/FunctionWrapper.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Tools/Font.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Tools/Easing.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/include/CNGui/Tools/Scissors.hpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Core/Registration.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Core/EventHandler.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Core/Updatable.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Core/Style.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/Object.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/LineEdit.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/Button.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/ProgressIndicator.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/Poster.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/Category.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/KeyEdit.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/Box.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/Slider.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Objects/LineSelect.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Tools/FunctionWrapper.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Tools/Text.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Tools/Shape.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Tools/Easing.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/CNGui/Tools/Scissors.cpp"
)

target_link_libraries(cngui sfml-graphics sfml-main ${OPENGL_gl_LIBRARY})
