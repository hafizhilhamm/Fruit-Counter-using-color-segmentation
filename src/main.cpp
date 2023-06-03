#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <chrono>
#include <thread>

void millisecondDelay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    cv::VideoCapture cap(0);
    cv::Mat frame;
    int banana_counter = 0;
    int strawberry_counter = 0;
    int grape_counter = 0;

    bool banana_detected = false;
    bool strawberry_detected = false;
    bool grape_detected = false;

    while (true) {
        cap >> frame;
        cv::Mat hsv;
        cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        cv::Scalar lower_banana(0 , 125 , 141 );
        cv::Scalar upper_banana(49, 255, 255);

        cv::Mat banana;
        cv::inRange(hsv, lower_banana, upper_banana, banana);
        std::vector<std::vector<cv::Point>> contours_banana;
        std::vector<cv::Vec4i> hierarchy_banana;
        cv::findContours(banana, contours_banana, hierarchy_banana, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        double maxArea_banana = 0;
        size_t maxAreaIdx_banana = 0;
        for (size_t i = 0; i < contours_banana.size(); i++) {
            double area_banana = cv::contourArea(contours_banana[i]);
            if (area_banana > maxArea_banana) {
                maxArea_banana = area_banana;
                maxAreaIdx_banana = i;
            }

            if (area_banana > 500 && contours_banana.size() > 0) {
                cv::Rect boundingRect_banana = cv::boundingRect(contours_banana[maxAreaIdx_banana]);
                cv::rectangle(frame, boundingRect_banana, cv::Scalar(0, 255, 255), 4);
                cv::putText(frame, "banana", cv::Point(boundingRect_banana.x, boundingRect_banana.y), cv::FONT_HERSHEY_DUPLEX, 2, cv::Scalar(0, 255, 255), 5);
            }

            if (area_banana > 500 && contours_banana.size() > 0 && !banana_detected) {
                banana_counter += 1;
                banana_detected = true; 
            }
            
        }
 if(contours_banana.size() == 0){
    banana_detected = false;
    }

 cv::Scalar lower_strawberry(165 , 59 , 194);
 cv::Scalar upper_strawberry(199 , 255 , 255);

 cv::Mat strawberry;
 cv::inRange(hsv, lower_strawberry, upper_strawberry, strawberry);
        std::vector<std::vector<cv::Point>> contours_strawberry;
        std::vector<cv::Vec4i> hierarchy_strawberry;
        cv::findContours(strawberry, contours_strawberry, hierarchy_strawberry, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        double maxArea_strawberry = 0;
        size_t maxAreaIdx_strawberry = 0;
        for (size_t i = 0; i < contours_strawberry.size(); i++) {
            double area = cv::contourArea(contours_strawberry[i]);
            if (area > maxArea_strawberry) {
                maxArea_strawberry = area;
                maxAreaIdx_strawberry = i;
            }
        

        if (area > 500 && contours_strawberry.size() > 0) {
            cv::Rect boundingRect_strawberry = cv::boundingRect(contours_strawberry[maxAreaIdx_strawberry]);
            cv::rectangle(frame, boundingRect_strawberry, cv::Scalar(0, 0, 255), 4);
            cv::putText(frame , "strawberry" , cv::Point(boundingRect_strawberry.x, boundingRect_strawberry.y), cv::FONT_HERSHEY_DUPLEX, 2, cv::Scalar(0,0,255),5);
        }

        if (area > 500 && contours_strawberry.size() > 0 && !strawberry_detected) {
            strawberry_counter += 1;
            strawberry_detected = true; 
        }
        }
 if(contours_strawberry.size() == 0){
    strawberry_detected = false;
    }

 cv::Scalar lower_grape(124 , 58 , 124);
 cv::Scalar upper_grape(171 , 158 , 255);

 cv::Mat grape;
 cv::inRange(hsv, lower_grape, upper_grape, grape);
        std::vector<std::vector<cv::Point>> contours_grape;
        std::vector<cv::Vec4i> hierarchy_grape;
        cv::findContours(grape, contours_grape, hierarchy_grape, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        double maxArea_grape = 0;
        size_t maxAreaIdx_grape = 0;
        for (size_t i = 0; i < contours_grape.size(); i++) {
            double area = cv::contourArea(contours_grape[i]);
            if (area > maxArea_grape) {
                maxArea_grape = area;
                maxAreaIdx_grape = i;
            }
        

        if (area > 500 && contours_grape.size() > 0) {
            cv::Rect boundingRect_grape = cv::boundingRect(contours_grape[maxAreaIdx_grape]);
            cv::rectangle(frame, boundingRect_grape, cv::Scalar(0, 0, 255), 4);
            cv::putText(frame , "grape" , cv::Point(boundingRect_grape.x, boundingRect_grape.y), cv::FONT_HERSHEY_DUPLEX, 2, cv::Scalar(0,0,255),5);
        }


        if (area > 500 && contours_grape.size() > 0 && !grape_detected) {
            grape_counter += 1;
            grape_detected = true; 
        }
 if(contours_grape.size() == 0){
    grape_detected = false;
    }

        }
 int total = banana_counter + strawberry_counter + grape_counter;
 std::cout << "----------" << std::endl;
 std::cout << "Banana : " << banana_counter << std::endl;
 std::cout << "Strawberry : " << strawberry_counter << std::endl;
 std::cout << "Grape : " << grape_counter << std::endl;
 std::cout << "Total : " << total << std::endl;
 std::cout << "----------" << std::endl;

 cv::imshow("img",frame);
 cv::imshow("banana",banana);
//  cv::imshow("strawberry",strawberry);
//  cv::imshow("grape",grape);
 cv::waitKey(1);
}
}
