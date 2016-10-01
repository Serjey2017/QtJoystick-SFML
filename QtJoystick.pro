#-------------------------------------------------
#
# Project created by QtCreator 2011-07-01T00:41:09
#
#-------------------------------------------------

QT       += core gui

TARGET = QtJoystick-SFML
TEMPLATE = app

# Add SFML include directory, where SFML headers are located
INCLUDEPATH += "E:/Projects/SDK/SFML-2.0-rc/include"

# Add SFML library directory to search path
LIBS += -L"E:/Projects/SDK/SFML-2.0-rc/lib"

# Add SFML window library, where Joystick is located
LIBS += -lsfml-window



SOURCES += main.cpp\
        mainwindow.cpp \
    xinputGamepad.cpp

HEADERS  += mainwindow.h \
    xinputGamepad.h \
    xqTblMgr.h \
    version.h

FORMS    += mainwindow.ui

RC_FILE = qtJoystick.rc

RESOURCES += \
    resJoystick.qrc
