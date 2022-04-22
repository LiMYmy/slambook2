#include "myslam/config.h"

namespace myslam {
bool Config::SetParameterFile(const std::string filename) 
{
    file_.open(filename.c_str(), cv::FileStorage::READ);
    if (file_.isOpened() == false) 
    {
        LOG(ERROR) << "parameter file " << filename << " does not exist.";
        file_.release();
        return false;
    }

    return true;
}

Config::~Config() {
    if (file_.isOpened())
        file_.release();
}

}
