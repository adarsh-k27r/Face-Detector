# Face Detection using OpenCV and GStreamer Pipeline (C++)

<div style="height: 10px;"></div>

I primarily divided the whole task into two parts which are as follows:

<div style="height: 10px;"></div>

**Part 1:**

- Developed a **GStreamer pipeline** using the `gst-launch` command-line tool to read an MP4 video file.
- Scaled down the input video to a **640x640 resolution**.
- Output **JPEG-encoded frames** from the scaled-down video.

<div style="height: 10px;"></div>

**Part 2:**

- Extended Part 1 by writing a **C++ application** to process the JPEG frames sequentially.
- Utilized OpenCV’s `haarcascade_frontalface_alt.xml` classifier to detect and crop faces from each frame.
- Organized the cropped faces into a frame-wise folder structure.

<div style="height: 30px;"></div>

## Key Technologies and Tools Used:

<div style="height: 10px;"></div>

- **GStreamer**: For creating the **multimedia pipeline** and processing the video file.
- **OpenCV**: For image processing, including **face detection and cropping** using the `haarcascade_frontalface_alt.xml` classifier.
- **C++**: For implementing the application to read, process, and organize JPEG frames.
- **Linux Ubuntu**: Development environment.
- **Makefile**: For compiling the C++ application.

<div style="height: 30px;"></div>

## Implementation Overview:

<div style="height: 10px;"></div>

1. **GStreamer Pipeline Creation**:

   - Constructed a pipeline to read the MP4 video, scaled it to 640x640 resolution, and encoded the frames as JPEG images.
   - Executed the pipeline using the `gst-launch` command line tool.

<div style="height: 10px;"></div>

2. **Frame Processing Application**:
   - Developed a C++ application to read the JPEG frames sequentially.
   - Utilized OpenCV’s `haarcascade_frontalface_alt.xml` classifier to detect faces in each frame.
   - Cropped detected faces and saved them in a structured folder hierarchy based on the frame number.
   - Created a **Makefile to streamline the compilation** and build process of the C++ application.

<div style="height: 30px;"></div>

## Results:

<div style="height: 10px;"></div>

- Successfully created a **GStreamer pipeline** to process and encode video frames.
- Developed a robust C++ application that effectively reads JPEG frames from an MP4 video, **detects and crops faces using OpenCV**, and organizes them into a clear and manageable directory structure.
- Ensured a seamless development process using **Linux Ubuntu** and a well-defined Makefile for efficient compilation.

<div style="height: 30px;"></div>
