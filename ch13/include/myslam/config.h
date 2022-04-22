#pragma once
#ifndef MYSLAM_CONFIG_H
#define MYSLAM_CONFIG_H

#include "myslam/common_include.h"

namespace myslam {

/**
 * 配置类，使用SetParameterFile确定配置文件
 * 然后用Get得到对应值
 * 单例模式
 */
class Config {
   private:
    cv::FileStorage file_;

    Config() {}  // private constructor makes a singleton
   public:
    ~Config();  // close the file when deconstructing

    static Config& Instance()
    {
        static Config config_;
        return config_;
    }

    // set a new config file
    bool SetParameterFile(const std::string filename);

    // access the parameter values
    template <typename T>
    T Get(const std::string key) {
        return T(file_[key]);
    }
};
}  // namespace myslam

#endif  // MYSLAM_CONFIG_H
