/*
https://habr.com/ru/articles/729260/
*/

#include "include/task3.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <openssl/sha.h>
#include <openssl/evp.h>
#include <fstream>
#include<string>
#include<vector>

std::string hash(const cv::Mat img){
    unsigned char hs[SHA256_DIGEST_LENGTH];

    SHA256(img.data, img.total()*img.elemSize(), hs);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hs[i];
    }
    return ss.str();
}

long long load_and_compare(const std::string& path){
    cv::Mat img, img_mod;
    // Read an image
    try{
        img = cv::imread(path);
        img_mod = img.clone();
    }
    catch(std::exception e){
        std::cout << e.what() << '\n';
        return -1;
    }
    
    std::string orig_hash = hash(img);
    std::cout << "Original: " << orig_hash << std::endl;

    cv::Vec3b& pixel = img_mod.at<cv::Vec3b>(0, 0);
    pixel[0] = (pixel[0] + 1) % 256;


    std::string mod_hash = hash(img_mod);
    std::cout << "Modified SHA256: " << mod_hash << std::endl;

    bool equal_hash = (orig_hash == mod_hash);

    std::cout << "Matching hashes: " << (bool)equal_hash << '\n';
    
    std::ofstream out("output.txt");
    out << "Original hash: " << orig_hash << '\n';
    out << "Modified hash: " << mod_hash << '\n';
    out << "Hashes matching: " << equal_hash << '\n';

    return 0;

}
