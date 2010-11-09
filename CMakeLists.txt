project(blankslade)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 QUIET)
find_package(OpenGL QUIET)
if(QT4_FOUND AND OPENGL_FOUND AND OPENGL_GLU_FOUND)
    # TEST THESE
    #  QT_VERSION_MAJOR The major version of Qt found.
    #  QT_VERSION_MINOR The minor version of Qt found.
    #  QT_VERSION_PATCH The patch version of Qt found.
    IF(QT_VERSION_MAJOR MATCHES 4 AND QT_VERSION_MINOR GREATER 6)
        add_subdirectory (src)
    ELSE(QT_VERSION_MAJOR MATCHES 4 AND QT_VERSION_MINOR GREATER 6)
        MESSAGE(STATUS "Your Qt libraries are too old. Use at least 4.7.0.")
    ENDIF(QT_VERSION_MAJOR MATCHES 4 AND QT_VERSION_MINOR GREATER 6)
else(QT4_FOUND AND OPENGL_FOUND AND OPENGL_GLU_FOUND)
    MESSAGE(STATUS "Required libraries (Qt, GL, GLU) not found - offset editor can't be built.")
endif(QT4_FOUND AND OPENGL_FOUND AND OPENGL_GLU_FOUND)
