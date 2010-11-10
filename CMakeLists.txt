project(blankslade)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 QUIET)
find_package(OpenGL QUIET)

SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output CACHE PATH "Output directory for the dfhack tools" )

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
   message(SEND_ERROR "In-source builds are not allowed.")
endif("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")

IF(NOT DEFINED CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ENDIF(NOT DEFINED CMAKE_BUILD_TYPE)

if(QT4_FOUND AND OPENGL_FOUND AND OPENGL_GLU_FOUND)
    IF(QT_VERSION_MAJOR MATCHES 4 AND QT_VERSION_MINOR GREATER 6)
        add_subdirectory (src)
    ELSE(QT_VERSION_MAJOR MATCHES 4 AND QT_VERSION_MINOR GREATER 6)
        MESSAGE(STATUS "Your Qt libraries are too old. Use at least 4.7.0.")
    ENDIF(QT_VERSION_MAJOR MATCHES 4 AND QT_VERSION_MINOR GREATER 6)
else(QT4_FOUND AND OPENGL_FOUND AND OPENGL_GLU_FOUND)
    MESSAGE(STATUS "Required libraries (Qt, GL, GLU) not found - offset editor can't be built.")
endif(QT4_FOUND AND OPENGL_FOUND AND OPENGL_GLU_FOUND)
