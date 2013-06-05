TARGET = GraphicsService-sfml

include(../../../core/Graphics/Graphics.pri)

SOURCES += \
	\
	SfmlGraphicsService.cpp \
	\
	SfmlCanvas.cpp SfmlFont.cpp SfmlImage.cpp SfmlSprite.cpp SfmlWindow.cpp

HEADERS += \
	\
	SfmlGraphicsService.h \
	\
	SfmlCanvas.h SfmlFont.h SfmlImage.h SfmlSprite.h SfmlWindow.h

INCLUDEPATH += ../deps/SFML/include

LIBS += -L../deps/SFML/build/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s
win32 {
	LIBS += -L../deps/SFML/extlibs/libs-mingw/x86 -lglew
}
else {
	LIBS += -lGL -lXrandr -lGLEW -lrt
}
LIBS += -ljpeg -lfreetype
