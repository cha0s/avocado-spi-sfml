TARGET = TimingService-sfml

include(../../../core/Timing/Timing.pri)

SOURCES += \
	\
	SfmlTimingService.cpp \
	\
	SfmlCounter.cpp

HEADERS += \
	\
	SfmlTimingService.h \
	\
	SfmlCounter.h

INCLUDEPATH += ../deps/SFML/include

LIBS += -L../deps/SFML/build/lib -lsfml-system-s
!win32 {
	LIBS += -lrt
}
	