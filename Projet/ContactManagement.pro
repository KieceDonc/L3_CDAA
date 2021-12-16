QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/mapinteractiontodo.cpp \
    Model/todo.cpp \
    Model/contact.cpp \
    Model/interaction.cpp \
    Model/date.cpp \
    View/customform.cpp \
    View/findcontact.cpp \
    View/infocontact.cpp \
    View/infointeractions.cpp \
    View/jsonform.cpp \
    View/mainwindow.cpp \
    Others/main.cpp \
    Others/sqlinterface.cpp \
    Others/jsoninterface.cpp


HEADERS += \
    Model/mapinteractiontodo.h \
    Model/structid.h \
    Model/todo.h \
    Model/contact.h \
    Model/interaction.h \
    Model/date.h \
    View/customform.h \
    View/findcontact.h \
    View/infocontact.h \
    View/infointeractions.h \
    View/jsonform.h \
    View/mainwindow.h \
    Others/sqlinterface.h \
    Others/jsoninterface.h

FORMS += \
    View/findcontact.ui \
    View/infocontact.ui \
    View/infointeractions.ui \
    View/jsonform.ui \
    View/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
