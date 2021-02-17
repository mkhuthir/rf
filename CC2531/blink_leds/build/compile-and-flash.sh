#!/bin/bash

sdcc ../main.c
packihx main.ihx > main.hex
cc-tool -e -w main.hex
