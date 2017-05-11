TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11

SOURCES += \
    code/main/main.cpp \
    code/src/source/Abstraction.cpp \
    code/src/source/AbstractionImp.cpp \
    code/src/source/Adapter.cpp \
    code/src/source/Builder.cpp \
    code/src/source/Character.cpp \
    code/src/source/ClassAdapter.cpp \
    code/src/source/Command.cpp \
    code/src/source/Composite.cpp \
    code/src/source/Decorator.cpp \
    code/src/source/Facade.cpp \
    code/src/source/Factory.cpp \
    code/src/source/Handle.cpp \
    code/src/source/Interpret.cpp \
    code/src/source/Iterator.cpp \
    code/src/source/Mediator.cpp \
    code/src/source/Memento.cpp \
    code/src/source/Observer.cpp \
    code/src/source/Product.cpp \
    code/src/source/Prototype.cpp \
    code/src/source/Proxy.cpp \
    code/src/source/Singleton.cpp \
    code/src/source/Strategy.cpp \
    code/src/source/TemplateMethod.cpp \
    code/src/source/Visitor.cpp \
    code/src/memcache.cpp \
    code/src/lru.cpp \
    code/src/lfu.cpp \
    code/src/mru.cpp

HEADERS += \
    code/src/include/*.hpp \
    code/src/include/util.hpp \
    code/src/lru.h \
    code/src/lfu.h \
    code/src/mru.h \
    code/src/memcache.h

INCLUDEPATH += \
    code/src \
    code/src/include \

LIBS += \

