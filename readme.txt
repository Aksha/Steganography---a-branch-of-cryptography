The word steganography means "concealed writing." Steganography has been used for centuries to transmit secret messages. The secret message is hidden in some transportation medium such as an image, book, or music. The secret message can only be retrieved by a receiver that knows how to decode the message. For this project you will be creating a steganography bitmap image file (BMP) encoder. The encoder will store the bits of a secret message in the least significant bits of each RGB color byte of a BMP file.

The encoded image file appears visually to be mostly unaltered. This is because the least significant bit will not always be changed and when it is, the change will be imperceptible. For example a color value made up of RED 255, GREEN 255, and BLUE 255 (white) will become the color made up of RED 254, GREEN 254, and BLUE 254 (mostly white).

Details on Implementation:

Program is written using the C++ programming language (using only features supported by GCC 4.7.3)
Programs is compiled using the GCC 4.7.3 C++ compiler (g++) on ceclnx01 Linux server
I have used EasyBmp library.  It is a C++ library that assist with BMP manipulations. It doesn't account for negative heights.  It is advisable to write your own header file.

Steganography

Introduction

The word steganography means "concealed writing." Steganography has been used for centuries to transmit secret messages. The secret message is hidden in some transportation medium such as an image, book, or music. The secret message can only be retrieved by a receiver that knows how to decode the message. For this project you will be creating a steganography bitmap image file (BMP) encoder. The encoder will store the bits of a secret message in the least significant bits of each RGB color byte of a BMP file.

The encoded image file appears visually to be mostly unaltered. This is because the least significant bit will not always be changed and when it is, the change will be imperceptible. For example a color value made up of RED 255, GREEN 255, and BLUE 255 (white) will become the color made up of RED 254, GREEN 254, and BLUE 254 (mostly white).

Requirements

Program must be written using the C++ programming language (using only features supported by GCC 4.7.3)
Programs must compile using the GCC 4.7.3 C++ compiler (g++) on ceclnx01 Linux server
There exists C++ libraries that assist with BMP manipulations. Students may use these libraries if they wish.
Program Input

Your program should accept three command line arguments:

Argument 1: A path to an input file. An example is provided on ceclnx01 in /groups/cse467/sheldon.bmp . The input file has the following characteristics:
Uncompressed BMP file
32 bit pixel size
Argument 2: A path to an output file (file may or may not exist before running the program)
Argument 3: A secret message
Example 1: STDIN/STDOUT
$ ./encoder sheldon.bmp enc.bmp "hello world this is a secret message"
Pixels start at: 54
Width of image: 1024
Height of image: 640
Program Output

Your program should produce output to standard output (STDOUT) as shown in example 1 above. To find the pixel start, width and height, you will need to reference a BMP file format specification document. WikiPedia has a seemingly reasonable description of the file format: http://en.wikipedia.org/wiki/BMP_file_format
Write to STDOUT the starting position of the pixel array
Write to STDOUT the width of the image
Write to STDOUT the height (absolute value)
In addition to STDOUT, your program must create a new file that is stored in the file path provided as input to the program (enc.bmp in example 1)
The new file is a copy of the original with a secret message encoded in it using the method described in the steganography section next.
Steganography Method

Your program should use the following method for encoding the secret message:

Each pixel in the image is represented by 32 bits as illustrated in the following image:
image

(NOTE: The order of the colors may change between BMP files. The sample image uses this layout. Knowing the precise order of the colors is not paramount. You can assume that the color bytes will be represented by the first three bytes of each 32 bit pixel stored in the file.)

To encode the secret message into the new BMP file your program should reuse the least significant bit (LSB) of each color byte (red, green blue) in the following way:
The LSB of the first color byte of the first pixel will represent the LSB of the first character of the secret message
The LSB of the second color byte of the first pixel will represent the next LSB of the first character of the secret message
The LSB of the third color byte of the first pixel will represent the next LSB of the first character of the secret message
The LSB of the FIRST color of the second pixel will represent the next LSB of the first character of the secret message
...
It is safe to assume, for this project, that the image will have enough pixel to accommodate the secret message.
To indicate the end of the secret message you must include a single linebreak character at the end of the secret message hence your secret message must not include line breaks. The decoder will stop decoding when the first \n is encountered.
Testing

The program that you create is an encoder. To retrieve the secret message from an encoded BMP you must have a decoder. I have created the decoder and placed it in /groups/cse467/ on ceclnx01. You should be able to encode the message into a BMP and decode it using my decoder. An example is shown below:

$ ./encoder sheldon.bmp enc.bmp "hello world this is a secret message"
$ /groups/cse467/decoder enc.bmp 
Secret message: hello world this is a secret message

