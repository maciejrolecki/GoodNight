TEMPLATE = subdirs
SUBDIRS += \
    src/nuitcore \
    src/gui

# Note that the / was replaced by - in the target name
src-gui.depends = src/nuitcore

#tests.depends = src/abalonecore
OTHER_FILES += config.pri\
                Doxyfile
