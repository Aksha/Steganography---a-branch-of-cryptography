#include "steganography_test.h"

using namespace std;

void Steganography::imageDimensions() {

        inputImage.ReadFromFile(inputImageFile.c_str());
        inputImageHeight = inputImage.TellHeight();
        inputImageWidth = inputImage.TellWidth();
        outputImage.ReadFromFile(inputImageFile.c_str());
        hide_text(outputImage,inputText);
        writeImage();
}


void Steganography::hide_text(BMP outputImage,std::string msg) {
        SetEasyBMPwarningsOff();
        const int imgByteCount = outputImage.TellWidth() * outputImage.TellHeight();
        int bit=0;
        for(int i=0, j=0; i<imgByteCount && j<msg.length(); i++) {
                int each = (int)msg[j];
                RGBApixel pixel = outputImage.GetPixel(i/outputImage.TellWidth() , i%outputImage.TellWidth());
                if (bit == 8) { bit = 0; each = (int)msg[++j]; }
                int moderation = (each >> bit) & (1);
                pixel.Red = (ebmpBYTE)(((int)(pixel.Red) & (0xFE)) | moderation);
                ++bit;
                if (bit == 8) { bit = 0; each = (int)msg[++j]; }
                moderation = (each >> bit ) & (1);
                pixel.Green = (ebmpBYTE)(((int)(pixel.Green) & (0xFE)) | moderation);
                ++bit;
                if (bit == 8) { bit = 0; each = (int)msg[++j]; }
                moderation = (each >> bit) & (1);
                pixel.Blue = (ebmpBYTE)(((int)(pixel.Blue) & (0xFE)) | moderation);
                ++bit;
                pixel.Alpha = 0;
                outputImage.SetPixel(i/outputImage.TellWidth() , i%outputImage.TellWidth(), pixel);
                cout << "red: " << (int) outputImage( i/outputImage.TellWidth() , i%outputImage.TellWidth() )->Red << "green: " << (int) outputImage( i/outputImage.TellWidth() , i%outputImage.TellWidth() )-> Green << "blue: " << (int) outputImage( i/outputImage.TellWidth() , i%outputImage.TellWidth() )->Blue << endl;
        }
        SetEasyBMPwarningsOn();
}

void Steganography::writeImage() {
        cout << "The Height of the image is: " << outputImage.TellHeight() << endl;;
        cout << "The width of the image is: " << outputImage.TellWidth() << endl;;
        cout << " pixel starting is: 54" <<  endl;
        outputImage.WriteToFile(outputImageFile.c_str());
}

int main(int argc, char *argv[]) {
        Steganography obj(argv, argv[3]);
        obj.imageDimensions();
        return 0;
}
