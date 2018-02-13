#!/bin/bash

set -e

./build.sh

./brAInConsole/bin/brain -v -l 2 3 1
