#!/bin/sh
echo "Compile options macos(clang), linux(gcc), windows(wip)"
read OS
if [ $OS = "macos" ]; then
    # This is very ike but Apple is greedy and requires the GUI stack to contain like a million frameworks
    clang main.c internal.c cJSON.c ./raylib-5.5_macos/lib/libraylib.a  -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreGraphics -framework Foundation -o Atlantis
elif [ $OS = "linux" ]; then
    gcc main.c cJSON.c ./raylib-5.5_macos/lib/libraylib.a -lm -o Atlantis
elif [ $OS = "windows" ]; then
    echo "I'm sorry, I haven't bothered with windows version yet :("
else
    echo "Couldn't find compile option :["
fi
