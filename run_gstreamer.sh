#!/bin/bash

# Check if input file is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <input_file>"
  exit 1
fi

INPUT_FILE=$1

# GStreamer pipeline
gst-launch-1.0 filesrc location="$INPUT_FILE" ! \
  decodebin ! videoconvert ! videoscale ! \
  video/x-raw,width=640,height=640 ! jpegenc ! \
  multifilesink location="frame_%05d.jpg"

