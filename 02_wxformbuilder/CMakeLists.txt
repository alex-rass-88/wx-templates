set(TARGET_NAME 02_wxformbuilder)

add_executable(${TARGET_NAME} WIN32)

target_sources(${TARGET_NAME}
    PRIVATE
        app.cpp
        gui.cpp
        gui.h
        gui_mainframe.cpp
        gui_mainframe.h
)

target_link_libraries(${TARGET_NAME}
    PRIVATE
        third::wx
)
