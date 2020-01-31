set(TARGET_NAME 01_hello)

add_executable(${TARGET_NAME} WIN32)

target_sources(${TARGET_NAME}
    PRIVATE
        main.cpp
)

target_link_libraries(${TARGET_NAME}
    PRIVATE
        third::wx
)
