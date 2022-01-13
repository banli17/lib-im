#include <iostream>
#include "Im.h"

using namespace std;

int main() {
    Im im;
    im.crop(
            "/Users/banli/Desktop/course/course-cpp/test-im/a.jpeg",
            "out.png"
    );
    return 0;
}
