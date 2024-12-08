#include <stdio.h>

#include <iostream>

#include "Cimg.h"
using namespace std;
using namespace cimg_library;

int main() {
    CImg<unsigned int>* img = new CImg<unsigned int>("image.jpg");
    int x = (*img).width();
    int y = (*img).height();
    int h = x * y / 5;
    int image[x][y] = {0};
    int data[256] = {0};
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            image[i][j] = (*img).atXY(i, j);
            data[(*img).atXY(i, j)]++;
        }
    }
    CImg<unsigned char> out(512, h, 1, 3);
    CImgDisplay show(out, "display");
    out.fill(0);
    for (int i = 0; i < 256; i++) {
        for (int j = h - 1 - 2 * data[i]; j >= 0; j--) {
            out(2 * i, j, 0, 0) = 255;
            out(2 * i, j, 0, 1) = 255;
            out(2 * i, j, 0, 2) = 255;
            out(2 * i + 1, j, 0, 0) = 255;
            out(2 * i + 1, j, 0, 1) = 255;
            out(2 * i + 1, j, 0, 2) = 255;
        }
    }
    // for (int i = 0; i < 256; i++) {
    //     for (int j = h - 1 - data[i]; j >= 0; j--) {
    //         out(2 * i, j, 0, 0) = 255;
    //         out(2 * i, j, 0, 1) = 255;
    //         out(2 * i, j, 0, 2) = 255;
    //         out(2 * i + 1, j, 0, 0) = 255;
    //         out(2 * i + 1, j, 0, 1) = 255;
    //         out(2 * i + 1, j, 0, 2) = 255;
    //     }
    // }
    while (!show.is_closed()) {
        out.display(show);
    }
}