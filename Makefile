CXX = g++
CXXFLAGS = -std=c++17 `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4` -lstdc++fs

all: face_detector

face_detector: face_detector.cpp
	$(CXX) $(CXXFLAGS) -o face_detector face_detector.cpp $(LDFLAGS)

clean:
	rm -f face_detector

