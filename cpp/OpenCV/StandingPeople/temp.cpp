#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/gpu/gpu.hpp>

#include <stdio.h>

using namespace cv;

int main(int argc, char** argv){
    Mat img;
    vector<Rect> found;

     img = imread(argv[1]);

    if(argc != 2 || !img.data){
        printf("There is no picture\n");
        return -1;
    }

    HOGDescriptor defaultHog;
    defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    //check
    defaultHog.detectMultiScale(img, found);

    //draw tect
    for(int i = 0; i < found.size(); i++){
        Rect r = found[i];
        rectangle(img, r.tl(), r.br(), Scalar(0, 0, 255), 3);
    }


    namedWindow("check people", CV_WINDOW_AUTOSIZE);
    imshow("check people", img);

    waitKey(0);

    return 0;
}
