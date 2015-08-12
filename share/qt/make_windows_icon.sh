#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/bitcoin.png
ICON_DST=../../src/qt/res/icons/bitcoin.ico
convert ${ICON_SRC} -resize 16x16 bitcoin16.png
convert ${ICON_SRC} -resize 32x32 bitcoin32.png
convert ${ICON_SRC} -resize 64x64 bitcoin64.png
convert ${ICON_SRC} -resize 128x128 bitcoin128.png
convert ${ICON_SRC} -resize 256x256 bitcoin256.png
convert ${ICON_SRC} -resize 16x16 bitcoin16.xpm
convert ${ICON_SRC} -resize 32x32 bitcoin32.xpm
convert ${ICON_SRC} -resize 64x64 bitcoin64.xpm
convert ${ICON_SRC} -resize 128x128 bitcoin128.xpm
convert ${ICON_SRC} -resize 256x256 bitcoin256.xpm
convert bitcoin256.png -define icon:auto-resize=64,48,32,16 bitcoin.ico
