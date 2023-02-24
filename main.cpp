#include <Magick++.h>
#include <iostream>
#include <string>
#include "Im.h"
using namespace std;
using namespace Magick;

int main(int argc, char **argv) {
  InitializeMagick(NULL);
  string input = "/Users/banli/Desktop/lib-im/a.jpeg";
  string output = "/Users/banli/Desktop/lib-im/out.png";
//  process(input, output);
  try {
    cout << "hi0" << endl;
    Layer l1 = {type : "image", value: input, blur:6,
        resize: false, width: 100, height: 200};
    cout << "hi1" << endl;
    Image *images[] = {};
    Layer l2 = {
        value: "/Users/banli/Desktop/lib-im/b.jpg",
        width: 50, height: 80,
        left: 30, top: 100,
        type:"sharp"
    };

    Layer l3 = {
        value: "hello world",
        width: 200, height: 200,
        type:"text"
    };
    Layer *layers[] = {&l3};

    process(layers, output);

//    Image image;
//    cout << "hi2" << endl;
//    layer2png(&image, l1);
//    Image image2;
//    layer2png(&image2, {
//        value: "/Users/banli/Desktop/lib-im/b.jpg",
//        width: 50, height: 50,
//        type:"sharp"
//    });
//    composite(&image, &image2);
//    image.write(output);
  } catch (Exception &error_) {
    cout << "Caught exception: " << error_.what() << endl;
    return 1;
  }
  return 0;
}