TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/source/Abstraction.cpp \
    src/source/AbstractionImp.cpp \
    src/source/Adapter.cpp \
    src/source/Builder.cpp \
    src/source/Character.cpp \
    src/source/ClassAdapter.cpp \
    src/source/Command.cpp \
    src/source/Composite.cpp \
    src/source/Decorator.cpp \
    src/source/Facade.cpp \
    src/source/Factory.cpp \
    src/source/Handle.cpp \
    src/source/Interpret.cpp \
    src/source/Iterator.cpp \
    src/source/Mediator.cpp \
    src/source/Memento.cpp \
    src/source/Observer.cpp \
    src/source/Product.cpp \
    src/source/Prototype.cpp \
    src/source/Proxy.cpp \
    src/source/Singleton.cpp \
    src/source/Strategy.cpp \
    src/source/TemplateMethod.cpp \
    src/source/Visitor.cpp \
    src/memcache.cpp \
    src/lru.cpp \
    src/mru.cpp \
    src/lfu.cpp \
    test/main.cpp \
    test/lrutest.cpp \
    test/designtest.cpp

HEADERS += \
    src/include/*.hpp \
    src/*.h \

INCLUDEPATH += \
    src \
    src/include \


LIBS += \
    -L$$PWD/3rdlib/gtest/buildmingw32/lib/ -lgtest \
    -L$$PWD/3rdlib/gtest/buildmingw32/lib/ -lgmock

INCLUDEPATH += $$PWD/3rdlib/gtest/buildmingw32/include
DEPENDPATH += $$PWD/3rdlib/gtest/buildmingw32/include
PRE_TARGETDEPS += \
    $$PWD/3rdlib/gtest/buildmingw32/lib/libgtest.a \
    $$PWD/3rdlib/gtest/buildmingw32/lib/libgmock.a
