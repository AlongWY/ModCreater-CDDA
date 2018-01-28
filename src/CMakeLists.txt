CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(ModCreater-CDDA)

SET(CMAKE_CXX_STANDARD 11)

# 资源文件
SET(RESOURCES ${RES_PATH}/Resources.qrc)
SET(UIS ${UI_PATH}/Window.ui)

QT5_ADD_RESOURCES(RES_SOURCES ${RESOURCES})
QT5_WRAP_UI(UI_HEADERS ${UIS})

# 源码
SET(CODE_SOURCES MainCreater.cpp)   # Main
SET(CODE_SOURCES ${CODE_SOURCES}    # Model
        Model/ModInfo.cpp
        Model/Bionics.cpp
        Model/Material.cpp
        )
SET(CODE_SOURCES ${CODE_SOURCES}    # View
        View/MainWindow.cpp
        )
SET(CODE_SOURCES ${CODE_SOURCES}    # Controller
        )
SET(CODE_SOURCES ${CODE_SOURCES}    # Utils
        Utils/json.hpp
        Utils/macro.h
        )

# 编译
ADD_EXECUTABLE(Creater ${CODE_SOURCES} ${RES_SOURCES} ${UI_HEADERS})

# 链接
TARGET_LINK_LIBRARIES(Creater Qt5::Core Qt5::Widgets)
