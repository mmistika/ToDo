cmake_minimum_required(VERSION 3.20)

project(ToDo
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

find_package(Qt6 REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES
    translations/ToDo_en_US.ts
)
source_group("Translation Files" ${TS_FILES})

set(QRC_FILES
    resources/icons.qrc
)
source_group("Resource Files" ${QRC_FILES})

set(UI_FILES
    ui/window.ui
)
source_group("UI Files" ${UI_FILES})

set(PROJECT_SOURCES
        main.cpp
        window.cpp
        window.h

        ${UI_FILES}
        ${QRC_FILES}
        ${TS_FILES}
)

qt_add_executable(ToDo
    ${PROJECT_SOURCES}
)

set_source_files_properties(${TS_FILES}
    PROPERTIES OUTPUT_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/translations
)

qt_add_translations(ToDo TS_FILES
    ${TS_FILES}
)

target_link_libraries(ToDo PRIVATE Qt6::Widgets)

set_target_properties(ToDo PROPERTIES
    WIN32_EXECUTABLE TRUE
)
