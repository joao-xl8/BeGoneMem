#!/bin/zsh

echo "build bgm project"

output=$(g++ main.cpp \
  -o ./bgm \
  -I include/*.hpp \
  -std=c++20 \
)


