## -----------------------------------------------------------------------------
##
## Project created by __QBP_GENERATOR_NAME__ __QBP_CREATION_TIME__
##
## -----------------------------------------------------------------------------

QT += \
  core

QT -= \
  gui

CONFIG += \
  c++14 \
  warn_on \
  no_keywords \
  qt \
  exceptions \
  rtti \
  stl \
  thread

CONFIG (release, release | debug) {
  message ("Using `release' config")
#  QMAKE_CXXFLAGS_RELEASE += -O3 -mtune=native
#  QMAKE_CXXFLAGS_RELEASE += -O3 -march=native
} else {
  message ("Using `debug' config")
#  QMAKE_CXXFLAGS_DEBUG += -O0 -march=native
}

equals (QT_ARCH, x86_64) {
  message ("Building for `x86_64' target arch")
#  QMAKE_CXXFLAGS += -m64
} else {
  equals (QT_ARCH, i386) {
    message ("Building for `i386' target arch")
#    QMAKE_CXXFLAGS += -m32
  } else {
    message ("Unknown target arch `$$QT_ARCH' detected")
  }
}

QMAKE_CXX = ccache g++

QMAKE_CXXFLAGS_WARN_ON += \
  -fdiagnostics-color=auto \
  -Wpedantic \
  -Wall \
  -Wextra \
  -Wdouble-promotion \
  -Wformat=2 \
  -Wformat-signedness

TEMPLATE = app

TARGET = __QBP_TARGET_NAME__

win32 {
  VERSION = __QBP_WIN32_TARGET_VERSION__
} else {
  VERSION = __QBP_TARGET_VERSION__
}

win32 {
  message ("Windows platform detected")
  CONFIG += console
  ## 1200 : Unicode UTF-16, little endian byte order (BMP of ISO 10646);
  ## available only to managed applications
  RC_CODEPAGE = 1200
  RC_ICONS = $$PWD/resources/icons/application/application.ico
  ## English (United States)
  RC_LANG = 1033
  QMAKE_TARGET_COMPANY = "__QBP_QMAKE_TARGET_COMPANY__"
  QMAKE_TARGET_PRODUCT = "__QBP_QMAKE_TARGET_PRODUCT__"
  QMAKE_TARGET_DESCRIPTION = "__QBP_QMAKE_TARGET_DESCRIPTION__"
  QMAKE_TARGET_COPYRIGHT = "__QBP_QMAKE_TARGET_COPYRIGHT__"
}

macx {
  message ("macOS platform detected")
  CONFIG -= app_bundle
}

unix {
  message ("UNIX platform detected")
  CONFIG += \
    largefile \
    separate_debug_info
}

QMAKE_EXT_CPP += cxx

QMAKE_EXT_H += \
  hxx \
  txx

CONFIG(release, release | debug) {
  DEFINES += \
    QT_NO_DEBUG_OUTPUT \
    QT_NO_INFO_OUTPUT \
    QT_NO_WARNING_OUTPUT
}

SOURCES += \
  sources/main.cxx \
  sources/utils/utils.cxx

HEADERS += \
  sources/config/application.hxx \
  sources/definitions.hxx \
  sources/utils/utils.hxx
