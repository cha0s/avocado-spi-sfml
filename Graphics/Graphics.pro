TARGET = GraphicsService-sfml

include(../../../core/Graphics/Graphics.pri)

SOURCES += \
	\
	SfmlGraphicsService.cpp \
	\
	SfmlCanvas.cpp SfmlFont.cpp SfmlImage.cpp SfmlWindow.cpp

HEADERS += \
	\
	SfmlGraphicsService.h \
	\
	SfmlCanvas.h SfmlFont.h SfmlImage.h SfmlWindow.h

INCLUDEPATH += ../deps/SFML/include
LIBS += -L../deps/SFML/build/lib
LIBS += -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lGL -lXrandr -ljpeg -lGLEW -lrt -lfreetype
