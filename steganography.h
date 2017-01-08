#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include "EasyBMP.h"


#pragma once

using namespace std;

class Steganography {

        public:

        Steganography();

        Steganography(char **ImageDetails, string textToEncode) : inputImageFile(*(ImageDetails + 1)), outputImageFile(*(ImageDetails + 2)), inputText(textToEncode) {}

        void imageDimensions();
        void prepareOutputImage();
        //void add_text_to_image(BMP outputImage,std::string input);
        void hide_text(BMP inputImage, std::string msg);
        void writeImage();

        //void copyImage();

        std::string inputImageFile;
        std::string outputImageFile;
        std::string inputText;

        BMP inputImage;
        BMP outputImage;

        int inputImageHeight;
        int inputImageWidth;
        int outputImageHeight;
        int outputImageWidth;
	int bitDepth;

        std::string msg;
};
