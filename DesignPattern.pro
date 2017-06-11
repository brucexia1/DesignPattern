TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/designpattern/Abstraction.cpp \
    src/designpattern/AbstractionImp.cpp \
    src/designpattern/Adapter.cpp \
    src/designpattern/Builder.cpp \
    src/designpattern/Character.cpp \
    src/designpattern/ClassAdapter.cpp \
    src/designpattern/Command.cpp \
    src/designpattern/Composite.cpp \
    src/designpattern/Decorator.cpp \
    src/designpattern/Facade.cpp \
    src/designpattern/Factory.cpp \
    src/designpattern/Handle.cpp \
    src/designpattern/Interpret.cpp \
    src/designpattern/Iterator.cpp \
    src/designpattern/Mediator.cpp \
    src/designpattern/Memento.cpp \
    src/designpattern/Observer.cpp \
    src/designpattern/Product.cpp \
    src/designpattern/Prototype.cpp \
    src/designpattern/Proxy.cpp \
    src/designpattern/Singleton.cpp \
    src/designpattern/Strategy.cpp \
    src/designpattern/TemplateMethod.cpp \
    src/designpattern/Visitor.cpp \
    src/algorithm/demo.cpp \
    src/algorithm/graph.cpp \
    src/algorithm/tree.cpp \
    src/algorithm/xsSort.cpp \
    src/algorithm/xsSearch.cpp \
    src/other/memcache.cpp \
    src/other/lru.cpp \
    src/other/mru.cpp \
    src/other/lfu.cpp \
    test/main.cpp \
    test/lrutest.cpp \
    test/designtest.cpp \
    test/myalg.cpp \
    test/testlibrary.cpp \

HEADERS += \
    src/designpattern/*.hpp \
    src/algorithm/*.h \
    src/other/*.h \
    test/*.h \

INCLUDEPATH += \
    src/designpattern \
    src/algorithm \
    src/other \
    test \


LIBS += \
    -L$$PWD/3rdlib/gtest/buildmingw32/lib/ -lgtest \
    -L$$PWD/3rdlib/gtest/buildmingw32/lib/ -lgmock

INCLUDEPATH += $$PWD/3rdlib/gtest/buildmingw32/include
DEPENDPATH += $$PWD/3rdlib/gtest/buildmingw32/include
PRE_TARGETDEPS += \
    $$PWD/3rdlib/gtest/buildmingw32/lib/libgtest.a \
    $$PWD/3rdlib/gtest/buildmingw32/lib/libgmock.a
