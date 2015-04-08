#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/monetaryunit.png
ICON_DST=../../src/qt/res/icons/monetaryunit.ico
convert ${ICON_SRC} -resize 16x16 monetaryunit-16.png
convert ${ICON_SRC} -resize 32x32 monetaryunit-32.png
convert ${ICON_SRC} -resize 48x48 monetaryunit-48.png
convert monetaryunit-16.png monetaryunit-32.png monetaryunit-48.png ${ICON_DST}

