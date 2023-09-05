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

find_package(Qt6 REQUIRED COMPONENTS Widgets LinguistTools)

set(TS_FILES
    translations/ToDo_en_US.ts
)

set(QRC_FILES
    resources/icons.qrc
)

set(UI_FILES
    src/ui/window/window.ui
    src/ui/taskcard/taskcard.ui
)

source_group("Translation Files" FILES ${TS_FILES})
source_group("Resource Files" FILES ${QRC_FILES})
source_group("UI Files" FILES ${UI_FILES})

set(PROJECT_SOURCES
    src/main.cpp
    src/core/database/database.cpp
    src/core/database/database.h
    src/ui/window/window.cpp
    src/ui/window/window.h
    src/ui/taskcard/taskcard.cpp
    src/ui/taskcard/taskcard.h
    src/ui/cstackedwidget/cstackedwidget.cpp
    src/ui/cstackedwidget/cstackedwidget.h
    src/ui/utils/utils.cpp
    src/ui/utils/utils.h
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
