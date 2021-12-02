QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contact.cpp \
    date.cpp \
    interaction.cpp \
    interactiontodo.cpp \
    interactiontodos.cpp \
    log.cpp \
    logs.cpp \
    main.cpp \
    mainwindow.cpp \
    photo.cpp \
    sqlinterface.cpp \
    todo.cpp

HEADERS += \
    contact.h \
    date.h \
    interaction.h \
    interactiontodo.h \
    interactiontodos.h \
    log.h \
    logs.h \
    mainwindow.h \
    photo.h \
    sqlinterface.h \
    todo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
