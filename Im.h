#include <iostream>
#include <string>
#include <Magick++.h>

using namespace std;
using namespace Magick;

#ifndef TEST_IM_IM_H
#define TEST_IM_IM_H

class Im {
public:
    int getMetaData();

    Im crop(string src, string dist);

private:
    string src;
    Image image;
};

#endif //TEST_IM_IM_H
