#include "odometry.h"
using namespace std;
void callback(const nav_msgs::Odometry::ConstPtr& ptr)
{
    cout << "std_msgs/Header 头部" << endl;
    cout << "    uint32 序列号: " << ptr->header.seq << endl;
    cout << "    时间戳: " << ptr->header.stamp << endl;
    cout << "    字符串 坐标系ID: " << ptr->header.frame_id << endl;
    cout << "字符串 子坐标系ID: " << ptr->child_frame_id << endl;
    cout << "geometry_msgs/PoseWithCovariance 姿态" << endl;
    cout << "    geometry_msgs/Pose 姿态" << endl;
    cout << "        geometry_msgs/Point 位置" << endl;
    cout << "        float64 x: " << ptr->pose.pose.position.x << endl;
    cout << "        float64 y: " << ptr->pose.pose.position.y << endl;
    cout << "        float64 z: " << ptr->pose.pose.position.z << endl;
    cout << "    geometry_msgs/Quaternion 方向" << endl;
    cout << "        float64 x: " << ptr->pose.pose.orientation.x << endl;
    cout << "        float64 y: " << ptr->pose.pose.orientation.y << endl;
    cout << "        float64 z: " << ptr->pose.pose.orientation.z << endl;
    cout << "        float64 w: " << ptr->pose.pose.orientation.w << endl;
    cout << "    float64[36] 协方差" << endl;
    cout << "        ";
    for (int i = 0; i < 36; ++i) {
        cout << ptr->pose.covariance[i] << " ";
    }
    cout << endl;
    cout << "geometry_msgs/TwistWithCovariance 速度" << endl;
    cout << "    geometry_msgs/Twist 速度" << endl;
    cout << "        geometry_msgs/Vector3 线速度" << endl;
    cout << "            float64 x: " << ptr->twist.twist.linear.x << endl;
    cout << "            float64 y: " << ptr->twist.twist.linear.y << endl;
    cout << "            float64 z: " << ptr->twist.twist.linear.z << endl;
    cout << "        geometry_msgs/Vector3 角速度" << endl;
    cout << "            float64 x: " << ptr->twist.twist.angular.x << endl;
    cout << "            float64 y: " << ptr->twist.twist.angular.y << endl;
    cout << "            float64 z: " << ptr->twist.twist.angular.z << endl;
    cout << "    float64[36] 协方差" << endl;
    cout << "        ";
    for (int i = 0; i < 36; ++i) {
        cout << ptr->twist.covariance[i] << " ";
    }
    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "show_odometry");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("/odom", 1000, callback);
    ros::spin();
    return 0;
}
