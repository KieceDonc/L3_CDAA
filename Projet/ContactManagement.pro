QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/contactid.cpp \
    Model/main.cpp \
    Model/log.cpp \
    Model/logs.cpp \
    Model/todo.cpp \
    Model/photo.cpp \
    Model/contact.cpp \
    Model/findcontact.cpp \
    Model/interaction.cpp \
    Model/interactiontodo.cpp \
    Model/interactiontodos.cpp \
    Model/date.cpp \
    View/customform.cpp \
    View/mainwindow.cpp \
    Others/sqlinterface.cpp


HEADERS += \
    Model/contactid.h \
    Model/log.h \
    Model/logs.h \
    Model/todo.h \
    Model/photo.h \
    Model/contact.h \
    Model/contactID.h \
    Model/findcontact.h \
    Model/interaction.h \
    Model/interactiontodo.h \
    Model/interactiontodos.h \
    Model/date.h \
    View/customform.h \
    View/mainwindow.h \
    Others/sqlinterface.h

FORMS += \
    View/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
