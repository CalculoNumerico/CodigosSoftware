#-------------------------------------------------
#
# Project created by QtCreator 2015-03-26T19:01:17
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT      += opengl widgets

LIBS += -lfreeglut \

TARGET = CalculoNum
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    conversions.cpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.cpp \
    SistemasdeControle/src/communicationLibs/serial/comunicacao.cpp \
    SistemasdeControle/src/externalLibs/externalfunctions.cpp \
    SistemasdeControle/src/graphicLibs/glview.cpp \
    SistemasdeControle/src/graphicLibs/grafics.cpp \
    SistemasdeControle/src/graphicLibs/graphicproperties.cpp \
    SistemasdeControle/src/modelLibs/armax.cpp \
    SistemasdeControle/src/modelLibs/arx.cpp \
    SistemasdeControle/src/modelLibs/fir.cpp \
    SistemasdeControle/src/modelLibs/ma.cpp \
    SistemasdeControle/src/modelLibs/model.cpp \
    SistemasdeControle/src/modelLibs/simfunction.cpp \
    SistemasdeControle/src/modelLibs/statespace.cpp \
    SistemasdeControle/src/modelLibs/transferfunction.cpp \
    SistemasdeControle/src/optimizationLibs/leastsquare.cpp \
    SistemasdeControle/src/optimizationLibs/optimization.cpp \
    SistemasdeControle/src/optimizationLibs/pid.cpp \
    SistemasdeControle/src/optimizationLibs/pso.cpp \
    SistemasdeControle/src/optimizationLibs/recursiveleastsquare.cpp \
    SistemasdeControle/src/optimizationLibs/relay.cpp \
    SistemasdeControle/src/primitiveLibs/polynom.cpp \
    SistemasdeControle/src/simulationLibs/eqdifsim.cpp \
    SistemasdeControle/src/simulationLibs/lsim.cpp \
    SistemasdeControle/src/simulationLibs/sim.cpp \
    SistemasdeControle/src/zeroFunctionLib/bisseccao.cpp \
    SistemasdeControle/src/zeroFunctionLib/fzero.cpp \
    SistemasdeControle/src/zeroFunctionLib/newton.cpp \
    SistemasdeControle/src/zeroFunctionLib/secant.cpp \
    SistemasdeControle/src/zeroFunctionLib/steffensen.cpp \

HEADERS += \
    conversions.h \
    SistemasdeControle/headers/communicationLibs/serial/comunicacao.h \
    SistemasdeControle/headers/externalLibs/externalfunctions.h \
    SistemasdeControle/headers/graphicLibs/glview.h \
    SistemasdeControle/headers/graphicLibs/grafics.h \
    SistemasdeControle/headers/graphicLibs/graphicproperties.h \
    SistemasdeControle/headers/modelLibs/armax.h \
    SistemasdeControle/headers/modelLibs/arx.h \
    SistemasdeControle/headers/modelLibs/conversions.h \
    SistemasdeControle/headers/modelLibs/fir.h \
    SistemasdeControle/headers/modelLibs/ma.h \
    SistemasdeControle/headers/modelLibs/model.h \
    SistemasdeControle/headers/modelLibs/simfunction.h \
    SistemasdeControle/headers/modelLibs/statespace.h \
    SistemasdeControle/headers/modelLibs/transferfunction.h \
    SistemasdeControle/headers/optimizationLibs/leastsquare.h \
    SistemasdeControle/headers/optimizationLibs/optimization.h \
    SistemasdeControle/headers/optimizationLibs/pid.h \
    SistemasdeControle/headers/optimizationLibs/pso.h \
    SistemasdeControle/headers/optimizationLibs/recursiveleastsquare.h \
    SistemasdeControle/headers/optimizationLibs/relay.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/headers/primitiveLibs/polynom.h \
    SistemasdeControle/headers/simulationLibs/eqdifsim.h \
    SistemasdeControle/headers/simulationLibs/lsim.h \
    SistemasdeControle/headers/simulationLibs/sim.h \
    SistemasdeControle/headers/zeroFunctionLib/bisseccao.h \
    SistemasdeControle/headers/zeroFunctionLib/fzero.h \
    SistemasdeControle/headers/zeroFunctionLib/newton.h \
    SistemasdeControle/headers/zeroFunctionLib/secant.h \
    SistemasdeControle/headers/zeroFunctionLib/steffensen.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp
