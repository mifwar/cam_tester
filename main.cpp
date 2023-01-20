#include <opencv2/opencv.hpp> // Include OpenCV API
#include <stdio.h>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "the command should be \"./main index_number\". \
        \n index_number represents an index number of your camera.\"");
        return -1;
    }
    int camIndex = std::atoi(argv[1]);

    fprintf(stderr, "your cam index is %d\n", camIndex);

    char type;

    fprintf(stderr, "\npress ESC to end the program\n");

    cv::VideoCapture cap(camIndex);

    while (type != 27)
    {
        cv::Mat frame;
        cap.read(frame);
        imshow("frame", frame);
        type = cv::waitKey(1);
    }
    return 0;
}