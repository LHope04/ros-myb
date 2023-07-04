#include "imu_read.h"
using namespace std;
void callback(const sensor_msgs::Imu::ConstPtr& ptr)
{
    cout << "std_msgs/Header 头部信息" << endl;
    cout << "    uint32 序列号: " << ptr->header.seq << endl;
    cout << "    时间戳: " << ptr->header.stamp << endl;
    cout << "    string 坐标系ID: " << ptr->header.frame_id << endl;
    cout << "geometry_msgs/Quaternion 方向信息" << endl;
    cout << "    float64 x: " << ptr->orientation.x << endl;
    cout << "    float64 y: " << ptr->orientation.y << endl;
    cout << "    float64 z: " << ptr->orientation.z << endl;
    cout << "    float64 w: " << ptr->orientation.w << endl;
    cout << "float64[9] 方向协方差" << endl;
    cout << "    ";
    for (int i = 0; i < 9; ++i) {
        cout << ptr->orientation_covariance[i] << " ";
    }
    cout << endl;
    cout << "geometry_msgs/Vector3 角速度信息" << endl;
    cout << "    float64 x: " << ptr->angular_velocity.x << endl;
    cout << "    float64 y: " << ptr->angular_velocity.y << endl;
    cout << "    float64 z: " << ptr->angular_velocity.z << endl;
    cout << "float64[9] 角速度协方差" << endl;
    cout << "    ";
    for (int i = 0; i < 9; ++i) {
        cout << ptr->angular_velocity_covariance[i] << " ";
    }
    cout << endl;
    cout << "geometry_msgs/Vector3 线性加速度信息" << endl;
    cout << "    float64 x: " << ptr->linear_acceleration.x << endl;
    cout << "    float64 y: " << ptr->linear_acceleration.y << endl;
    cout << "    float64 z: " << ptr->linear_acceleration.z << endl;
    cout << "float64[9] 线性加速度协方差" << endl;
    cout << "    ";
    for (int i = 0; i < 9; ++i) {
        cout << ptr->linear_acceleration_covariance[i] << " ";
    }
    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "show_imu");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("/imu/data_raw", 1000, callback);
    ros::spin();
    return 0;
}
