# wxWidgets version
set(WX_VERSION 3.1.3)

set(WX_SRC_ARCHIVE "${CMAKE_CURRENT_SOURCE_DIR}/wxWidgets-${WX_VERSION}.tar.bz2")
set(WX_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/wxWidgets-${WX_VERSION}")
set(WX_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/wxWidgets-${WX_VERSION}-build")

if(NOT EXISTS ${WX_SRC_ARCHIVE})
    message(STATUS "Downloading wxWidgets ${WX_VERSION} source. Please wait...")
    file(DOWNLOAD
        "https://github.com/wxWidgets/wxWidgets/releases/download/v${WX_VERSION}/wxWidgets-${WX_VERSION}.tar.bz2"
        ${WX_SRC_ARCHIVE}
        SHOW_PROGRESS
    )
endif()

# Extracting files
if(NOT EXISTS ${WX_SRC_DIR})
    execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${WX_SRC_DIR})
    message(STATUS "Extracting wxWidgets ${WX_VERSION} files. Please wait...")
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xjf ${WX_SRC_ARCHIVE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

# wxWidgets config
set(wxBUILD_SHARED OFF)
set(wxBUILD_INSTALL OFF)

set(wxUSE_OPENGL OFF)
set(wxUSE_WEBVIEW OFF)
set(wxUSE_MEDIACTRL OFF)
set(wxUSE_RIBBON OFF)
set(wxUSE_STC OFF)
set(wxUSE_PROPGRID OFF)

if(wxBUILD_SHARED)
    add_definitions(-DWXUSINGDLL)
endif()

# Add as subproject
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/wxWidgets-${WX_VERSION}" EXCLUDE_FROM_ALL)

# Aliases
add_library(wx::adv ALIAS adv)
add_library(wx::aui ALIAS aui)
add_library(wx::base ALIAS base)
add_library(wx::core ALIAS core)
add_library(wx::html ALIAS html)
add_library(wx::net ALIAS net)
add_library(wx::qa ALIAS qa)
add_library(wx::richtext ALIAS richtext)
add_library(wx::xml ALIAS xml)
add_library(wx::xrc ALIAS xrc)
if(wxUSE_PROPGRID)
    add_library(wx::propgrid ALIAS propgrid)
endif()
if(wxUSE_STC)
    add_library(wx::stc ALIAS stc)
endif()
if(wxUSE_RIBBON)
    add_library(wx::ribbon ALIAS ribbon)
endif()
if(wxUSE_WEBVIEW)
    add_library(wx::webview ALIAS webview)
endif()
if(wxUSE_MEDIACTRL)
    add_library(wx::media ALIAS media)
endif()
if(wxUSE_OPENGL)
    add_library(wx::gl ALIAS gl)
endif()
