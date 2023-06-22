#include"rclcpp/rclcpp.hpp"

int main(int argc, char **argv)
{
    // 调用rclcpp的初始化函数
    rclcpp::init(argc, argv);
    //create a node named "node_01"
    auto node = std::make_shared<rclcpp::Node>("node_01");
    //print message to the screen
    RCLCPP_INFO(node->get_logger(), "node_01 is running");
    //spin the node
    rclcpp::spin(node);
    //shutdown the node
    rclcpp::shutdown();
    

    return 0;
}