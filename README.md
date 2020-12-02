## Tiny vSLAM

Tiny vSLAM is a minimalist implementation of a real-time stereo visual SLAM system. Example of running tiny-vSLAM on [KITTI dataset](http://www.cvlibs.net/datasets/kitti/eval_odometry.php) is provided. More support is to be added. 

## Prerequisites

### A C++11 compiler

### Pangolin

[Pangolin](https://github.com/stevenlovegrove/Pangolin) is used as visualization and user interface. Install instructions can found [here](https://github.com/stevenlovegrove/Pangolin/#Dependencies).

### OpenCV

[OpenCV](https://opencv.org/) is used to perform necessary image operations and extract certain features. Here we pin its version at **4.2** (tested).

### Eigen3

Required by g2o. Install instructions can be found [here](http://eigen.tuxfamily.org/). Version required at least **3.1.0**.


### g2o

[g2o](https://github.com/RainerKuemmerle/g2o) is used to perform non-linear optimization. Install instructions can be found [here](https://github.com/RainerKuemmerle/g2o).


## Example Usage

First compile the library use ```cmake```

```
cd /path/to/tiny-vSLAM
mkdir build
cd build
cmake ..
make -j$(nproc)
```

Download KITTI visual odometry dataset from [here](http://www.cvlibs.net/datasets/kitti/eval_odometry.php). Extract the dataset and set the path to the corresponding sequence in ```config/default.yaml``` and run

```./bin/run_kitti_stereo```

Below is tiny-vSLAM running on KITTI sequence 05

[![Alt text](https://img.youtube.com/vi/7kLER7SKMXA/0.jpg)](https://youtu.be/7kLER7SKMXA)

