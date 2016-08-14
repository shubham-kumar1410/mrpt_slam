/*
 *  File:mrpt_ekf_slam_3d.h
 *  Author: Vladislav Tananaev
 *
 */


#ifndef MRPT_EKF_SLAM_3D_H
#define MRPT_EKF_SLAM_3D_H

#include <mrpt/obs/CObservationOdometry.h>
#include <mrpt/utils/CConfigFile.h>
#include <mrpt/utils/CFileGZInputStream.h>
#include <mrpt/utils/CFileGZOutputStream.h>
#include <mrpt/system/os.h>
#include <mrpt/system/string_utils.h>
#include <mrpt/system/filesystem.h>
#include <mrpt/slam/CRangeBearingKFSLAM.h>
#include <mrpt/obs/CRawlog.h>
#include <mrpt/math/ops_containers.h>
#include <mrpt/opengl/CGridPlaneXY.h>
#include <mrpt/opengl/CSetOfLines.h>
#include <mrpt/opengl/stock_objects.h>
#include <mrpt/obs/CObservationBearingRange.h>
#include <mrpt/obs/CActionRobotMovement3D.h>
using namespace mrpt;
using namespace mrpt::slam;
using namespace mrpt::maps;
using namespace mrpt::opengl;
using namespace mrpt::system;
using namespace mrpt::math;
using namespace mrpt::poses;
using namespace mrpt::utils;
using namespace mrpt::obs;
using namespace std;


class EKFslam{

public:
    EKFslam();
    ~EKFslam();
    void read_iniFile(std::string ini_filename);
    void observation(CSensoryFramePtr _sf, CObservationOdometryPtr _odometry);

protected:
    CRangeBearingKFSLAM mapping;

    mrpt::system::TTimeStamp timeLastUpdate_;///< last update of the pose and map

    CActionCollectionPtr action;///< actions
	CSensoryFramePtr sf;///< observations
 
    mrpt::poses::CPose3D odomLastObservation_; ///< last observation of odometry
	CActionRobotMovement3D::TMotionModelOptions motion_model_options_;         ///< used with odom value motion noise

};


#endif /* MRPT_EKF_SLAM_3D_H */
