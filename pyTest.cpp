/* python wrapper for depth based log boundary detector */


#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include <opencv2/opencv.hpp>
#include "conversion.h"
//#include "log_detect.hpp"

#include <iostream>

using namespace std;
namespace py = boost::python;

typedef unsigned char uchar_t;

std::vector<cv::Point2f> detectLog(cv::Mat image)
{
    std::vector<cv::Point2f> ret;
    cv::Size s = image.size();
    ret.push_back(cv::Point2f(float (s.width), float (s.height)));

    return ret;
}

boost::python::list log_detect(PyObject *depth_image_np)
{

    NDArrayConverter cvt;
    cv::Mat depth_image;
    depth_image = cvt.toMat(depth_image_np);

    PyThreadState *save_state = PyEval_SaveThread();

    std::vector<cv::Point2f> log_points = detectLog(depth_image);

    PyEval_RestoreThread(save_state);

    boost::python::list ret_log_points;
    for (int i = 0; i < log_points.size(); i++)  {
        boost::python::list point;
        point.append(log_points[i].x);
        point.append(log_points[i].y);
        ret_log_points.append(point);
    }


    return ret_log_points;
}


BOOST_PYTHON_MODULE(pyTest)
{
    using namespace boost::python;
    def("log_detect", log_detect);
}

