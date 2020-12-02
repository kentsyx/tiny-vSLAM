//
// modified on 20-11-30
//
#pragma once

#ifndef MYSLAM_FEATURE_H
#define MYSLAM_FEATURE_H

#include <memory>
#include <opencv2/features2d.hpp>
#include "myslam/common_include.h"

namespace myslam {

struct Frame;
struct MapPoint;

/**
 * 2D features
 * after triangulation it will be linked to a Map point
 */
struct Feature {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Feature> Ptr;

    std::weak_ptr<Frame> frame_;         // frame that has that feature
    cv::KeyPoint position_;              // 2D extract position
    std::weak_ptr<MapPoint> map_point_;  // linkedin Map point

    bool is_outlier_ = false;       // whether it is an outlier
    bool is_on_left_image_ = true;  // true is left image other right

   public:
    Feature() {}

    Feature(std::shared_ptr<Frame> frame, const cv::KeyPoint &kp)
        : frame_(frame), position_(kp) {}
};
}  // namespace myslam

#endif  // MYSLAM_FEATURE_H
