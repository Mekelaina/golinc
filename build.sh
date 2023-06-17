#! /usr/bin/bash

CC=gcc

SRC=src
BIN=bin
EXE=golinc

CFLAGS="$(pkg-config --cflags --libs sdl2) -Wall -MMD -MP -fsanitize=address"  

SOURCES=$SRC/*.c

rm $BIN/*

$CC $SOURCES $CFLAGS -o $BIN/$EXE

