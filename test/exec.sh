#!/bin/sh
dir=$(cd -P -- "$(dirname -- "$0")" && pwd -P)
LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$dir" $1
