//
// Created by banli on 21/12/2021.
//

#include <iostream>
#include "Im.h"


int Im::getMetaData() {
    cout << 11 << endl;
    return 1;
}

Im Im::crop(string src, string dist) {
    try {
        image.read(src);
        image.crop(Geometry(100, 100, 100, 100));
        image.write(dist);
    } catch (Exception &error_) {
        cout << "Caught exception: " << error_.what() << endl;
    }
    return *this;
}