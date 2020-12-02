//
// modified on 20-11-30
//

#ifndef MYSLAM_BACKEND_H
#define MYSLAM_BACKEND_H

#include "myslam/common_include.h"
#include "myslam/frame.h"
#include "myslam/map.h"

namespace myslam {
class Map;

/**
 * backend
 * has a separate optimization thread, initializes then Map is started
 * Map is triggered by front-end
 */
class Backend {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Backend> Ptr;

    // init optimization thread in constructor and hangs
    Backend();

    // set left and right cameras to get intrinsics
    void SetCameras(Camera::Ptr left, Camera::Ptr right) {
        cam_left_ = left;
        cam_right_ = right;
    }

    // set up Map
    void SetMap(std::shared_ptr<Map> map) { map_ = map; }

    // trigger Map update, init optimization
    void UpdateMap();

    // close backend thread
    void Stop();

   private:
    // backend thread
    void BackendLoop();

    // optimize given keyframe and landmark
    void Optimize(Map::KeyframesType& keyframes, Map::LandmarksType& landmarks);

    std::shared_ptr<Map> map_;
    std::thread backend_thread_;
    std::mutex data_mutex_;

    std::condition_variable map_update_;
    std::atomic<bool> backend_running_;

    Camera::Ptr cam_left_ = nullptr, cam_right_ = nullptr;
};

}  // namespace myslam

#endif  // MYSLAM_BACKEND_H