TARGET = SoundService-sfml

include(../../../core/Sound/Sound.pri)

SOURCES += \
	\
	SfmlSoundService.cpp \
	\
	SfmlSample.cpp SfmlMusic.cpp

HEADERS += \
	\
	SfmlSoundService.h \
	\
	SfmlSample.h SfmlMusic.h

INCLUDEPATH += ../deps/SFML/include

LIBS += -L../deps/SFML/build/lib -lsfml-audio-s -lsfml-system-s
win32 {
	LIBS += -L../deps/SFML/extlibs/libs-mingw/x64 -lopenal32
}
else {
	LIBS += -lopenal
}
LIBS += -lsndfile
