#include "gmapping_map.h"

cv::Mat map;
bool mapInitialized = false;
void drawMap(const nav_msgs::OccupancyGrid::ConstPtr& ptr)
{
    // 输出地图的分辨率、宽度和高度
    std::cout << "resolution: " << ptr->info.resolution << std::endl;
    std::cout << "width: " << ptr->info.width << std::endl;
    std::cout << "height: " << ptr->info.height << std::endl;

    // 定义绘制参数
    double scale = 1.0; // 缩放比例
    int width = 1200; // 绘制区域的宽度
    int height = 1200; // 绘制区域的高度
    cv::Point offset = {-1600, -1600}; // 绘制区域的偏移量
    map = cv::Mat::zeros(cv::Size(width, height), CV_8UC3); // 创建一个空白图像

    // 遍历地图的所有像素
    for (int i = 0; i < ptr->info.width * ptr->info.height; ++i) {
        // 计算像素的坐标
        int x = (i % ptr->info.width + offset.x) * scale;
        int y = (i / ptr->info.width + offset.y) * scale;

        // 根据地图数据的值，在map上绘制不同的区域
        if (ptr->data[i] == -1) {
            cv::rectangle(map, cv::Rect(x, y, scale, scale), cv::Scalar(220, 220, 220), -1); // 灰色矩形
        } else if (ptr->data[i] >= 80) {
            cv::rectangle(map, cv::Rect(x, y, scale, scale), cv::Scalar(50, 50, 50), -1); // 黑色矩形
        } else {
            cv::rectangle(map, cv::Rect(x, y, scale, scale), cv::Scalar(200, 240, 200), -1); // 绿色矩形
        }
    }

    // 设置mapInitialized的值为true，表示地图已经初始化完成
    mapInitialized = true;
}

void gmappingThread()
{
    system("rosrun gmapping slam_gmapping");
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "show_map");
    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe<nav_msgs::OccupancyGrid>("/map", 1000, drawMap);

    // 启动gmapping算法节点
    std::thread gmapping(gmappingThread);

    cv::namedWindow("Map", cv::WINDOW_NORMAL);

    while (ros::ok()) {
        ros::spinOnce();

        // 检查地图是否已初始化
        if (mapInitialized) {
            if (!map.empty()) {
                cv::imshow("Map", map);
                cv::waitKey(10);
            } else {
                std::cerr << "Failed to load map" << std::endl;
            }
        } else {
            std::cerr << "Failed to display map" << std::endl;
        }
    }

    // 关闭图像窗口
    cv::destroyAllWindows();

    return 0;
}
