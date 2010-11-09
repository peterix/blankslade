set( QT_USE_QTGUI TRUE )
set( QT_USE_QTOPENGL TRUE )
INCLUDE( ${QT_USE_FILE} )

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} "../libs/glm/")

set ( blankslade_SRCS
    blankslade.cpp
    main.cpp
    glwidget.cpp
)

SET ( blankslade_UI
    gui/main.ui
)

SET( blankslade_RCS
    gui/resources.qrc
)

# this command will generate rules that will run rcc on all files from blankslade_RCS
# in result blankslade_RC_SRCS variable will contain paths to files produced by rcc
QT4_ADD_RESOURCES( blankslade_RC_SRCS ${blankslade_RCS} )

QT4_WRAP_UI(blankslade_UI_h ${blankslade_UI})
qt4_automoc(${blankslade_SRCS})

add_executable(blankslade ${blankslade_SRCS} ${blankslade_RC_SRCS} ${blankslade_UI_h})
target_link_libraries(blankslade ${OPENGL_LIBRARIES} ${QT_LIBRARIES} )