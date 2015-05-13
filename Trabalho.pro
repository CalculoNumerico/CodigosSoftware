TEMPLATE = app
CONFIG  += console
CONFIG  -= app_bundle

QT      += opengl widgets
LIBS    += -lfreeglut \


SOURCES += main.cpp \
    Conversao/conversao.cpp \
    PontoFlutuante/pontflutuante.cpp \
    SistemasLineares/sistemaslineares.cpp \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.cpp \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/src/graphicLibs/glview.cpp \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/src/graphicLibs/grafics.cpp \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/src/graphicLibs/graphicproperties.cpp \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/src/primitiveLibs/polynom.cpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.cpp \
    SistemasdeControle/src/graphicLibs/glview.cpp \
    SistemasdeControle/src/graphicLibs/grafics.cpp \
    SistemasdeControle/src/graphicLibs/graphicproperties.cpp \
    SistemasdeControle/src/primitiveLibs/polynom.cpp \
    MetodosPolinomiais/interpolacaopolinomial.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Conversao/conversao.h \
    PontoFlutuante/pontflutuante.h \
    SistemasLineares/sistemaslineares.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/graphicLibs/glview.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/graphicLibs/grafics.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/graphicLibs/graphicproperties.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/headers/primitiveLibs/polynom.h \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
#    ../../../../../GitHub/CodigosSoftware/SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    SistemasdeControle/headers/graphicLibs/glview.h \
    SistemasdeControle/headers/graphicLibs/grafics.h \
    SistemasdeControle/headers/graphicLibs/graphicproperties.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/identifiers.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/headers/primitiveLibs/polynom.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    MetodosPolinomiais/interpolacaopolinomial.h

OTHER_FILES +=

