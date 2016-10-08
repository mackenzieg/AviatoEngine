#!/bin/sh

# $0 first arg, $1 arg two

COMPILE = $0

cmake -H. -BBuild

if [[ $COMPILE == *"vs"* ]]; then
    cmake -G "Visual Studios 14" --Build Build
fi

if [[ $COMPILE ]]; then

fi