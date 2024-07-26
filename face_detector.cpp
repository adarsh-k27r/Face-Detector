#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void detectAndSaveFaces(const std::string& imagePath, const std::string& outputDir, cv::CascadeClassifier& faceCascade) {
    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Could not read the image: " << imagePath << std::endl;
        return;
    }

    std::vector<cv::Rect> faces;
    cv::Mat imgGray;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(imgGray, imgGray);
    faceCascade.detectMultiScale(imgGray, faces);

    if (faces.empty()) {
        std::cout << "No faces found in " << imagePath << std::endl;
        return;
    }

    std::string frameDir = outputDir + "/" + fs::path(imagePath).stem().string();
    fs::create_directories(frameDir);

    for (size_t i = 0; i < faces.size(); ++i) {
        cv::Mat face = img(faces[i]);
        std::string facePath = frameDir + "/face_" + std::to_string(i+1) + ".jpg";
        if (!cv::imwrite(facePath, face)) {
            std::cerr << "Error saving face image: " << facePath << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_directory> <output_directory>" << std::endl;
        return 1;
    }

    std::string inputDir = argv[1];
    std::string outputDir = argv[2];

    std::cout << "Input directory: " << inputDir << std::endl;
    std::cout << "Output directory: " << outputDir << std::endl;

    cv::CascadeClassifier faceCascade;
    std::string cascadePath = "/home/kali/project/haarcascade_frontalface_alt.xml";
    std::cout << " XML PATH: " << cascadePath << std::endl;
    if (!faceCascade.load(cascadePath)) {
        std::cerr << "Could not load face cascade." << std::endl;
        return -1;
    }

    // Check if the input directory exists
    if (!fs::exists(inputDir) || !fs::is_directory(inputDir)) {
        std::cerr << "Input directory does not exist or is not a directory: " << inputDir << std::endl;
        return -1;
    }

    // Check if the output directory exists
    if (!fs::exists(outputDir) || !fs::is_directory(outputDir)) {
        std::cerr << "Output directory does not exist or is not a directory: " << outputDir << std::endl;
        return -1;
    }

    try {
        std::cout << "Reading files from directory: " << inputDir << std::endl;
        // Iterate over all files in the input directory
        for (const auto& entry : fs::directory_iterator(inputDir)) {
            if (entry.is_regular_file() && entry.path().extension() == ".jpg") {
                std::cout << "Processing file: " << entry.path() << std::endl;
                detectAndSaveFaces(entry.path().string(), outputDir, faceCascade);
            }
        }
    } catch (const fs::filesystem_error& ex) {
        std::cerr << "Filesystem error: " << ex.what() << std::endl;
        return -1;
    } catch (const cv::Exception& ex) {
        std::cerr << "OpenCV exception: " << ex.what() << std::endl;
        return -1;
    } catch (const std::exception& ex) {
        std::cerr << "Standard exception: " << ex.what() << std::endl;
        return -1;
    }

    return 0;
}
