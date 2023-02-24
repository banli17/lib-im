#include <iostream>
#include <string>
#include <Magick++.h>

using namespace std;
using namespace Magick;

#ifndef TEST_IM_IM_H
#define TEST_IM_IM_H

struct Layer {
  string type;
  bool required; // 必填项
  string value;
  signed short int width;
  signed short int height;
  signed short int left;
  signed short int top;
  signed short int rotate; // 旋转角度
  bool grayscale; // 灰度
  bool flip;
  bool flop;
  float blur; // 模糊
  int opacity;
  bool resize;
  double perspective[];
};

template<class T>
int getlength(T &array) {
  return (sizeof(array) / sizeof(array[0]));
}
// 图层转图片
Image *layer2png(Image *image, Layer layer) {
  if (!layer.perspective[15]) {
    size_t numberOfArguments = 16;
    double *listOfArguments = new double[numberOfArguments];//;layer.perspective;
    listOfArguments[0] = 0.0;
    listOfArguments[1] = 0.0;
    listOfArguments[2] = 0.0;
    listOfArguments[3] = 0.0;
    listOfArguments[4] = 500;
    listOfArguments[5] = 0.0;
    listOfArguments[6] = 500;
    listOfArguments[7] = 100;
    listOfArguments[8] = 0;
    listOfArguments[9] = 400;
    listOfArguments[10] = 0;
    listOfArguments[11] = 300;
    listOfArguments[12] = 500;
    listOfArguments[13] = 400;
    listOfArguments[14] = 500;
    listOfArguments[15] = 500;
    image->backgroundColor(Color());
    image->distort(MagickCore::PerspectiveDistortion,
                   numberOfArguments, listOfArguments,
                   MagickCore::MagickFalse);
  }

  // 变灰
  if (layer.grayscale) {
    image->type(GrayscaleType);
  }
  if (layer.flip) {
    image->flip();
  }
  if (layer.flop) {
    image->flop();
  }

  if (layer.rotate > 0) {
    image->backgroundColor(Color("#00000000"));
    image->rotate(layer.rotate);
  }

  if (isnumber(layer.opacity)) {
    image->matteColor(Magick::Color("red"));
  }
  if (layer.resize) {
    string wh = to_string(layer.width) + "x" +
        to_string(layer.height);
    string g = wh + "+0+0" + ">^";
    cout << g << endl;
    image->resize(Geometry(g));
    image->extent(wh, CenterGravity);
  }

  if (layer.blur) {
    image->blur(0, layer.blur);
  }

  return image;
}

Image *text2imageLayer() {

}

void initLayer(Layer *layer) {
  if (!layer->left) layer->left = 0;
  if (!layer->top) layer->top = 0;
}

int process(Layer *layer[], string output) {
  InitializeMagick(NULL);

  Image bg("300x300", "green");
  try {
    Image *images[] = {};
    for (int i = 0; i < 1; i++) {
      initLayer(layer[i]);

      if (layer[i]->type == "image") {
        images[i] = new Image(layer[i]->value);
      } else if (layer[i]->type == "sharp") {
        images[i] = new Image(Geometry(layer[i]->width, layer[i]->height),
                              Color("#ffffff00"));
      } else if (layer[i]->type == "text") {
        images[i] = new Image(Geometry(layer[i]->width, layer[i]->height),
                              Color("#ffffffff"));
        images[i]->font("/Users/banli/Desktop/lib-im/汉仪旗黑-55S.otf");
        images[i]->fontPointsize(30);
//        images[i]->fillColor(Color("firebrick"));
//        images[i]->strokeColor(Color("red"));
        images[i]->draw(Magick::DrawableText(100, 100, "朋友们"));
      }

      layer2png(images[i], *layer[i]);
      bg.composite(*images[i],
                   Geometry(layer[i]->width, layer[i]->height, layer[i]->left, layer[i]->top),
                   InCompositeOp);
    }
    bg.compressType(MagickCore::WebPCompression);
    bg.write(output);
  } catch (Exception &error_) {
    cout << "Caught exception: " << error_.what() << endl;
    return 1;
  }
  return 0;
}
#endif //TEST_IM_IM_H
