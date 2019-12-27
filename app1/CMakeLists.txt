add_executable(app1 WIN32)

target_sources(app1
    PRIVATE
        main.cpp
)

target_link_libraries(app1
    PRIVATE
        wx::base
        wx::core
)
