#include"rclcpp/rclcpp.hpp"

//creat a class named "Node_03"
class Node_03 : public rclcpp::Node
{
    public:
        Node_03(std::string name):Node(name)
        {
            //print message to the screen
            RCLCPP_INFO(this->get_logger(), "helle,my name is %s.", name.c_str());
        }
private:

};


int main(int argc ,char **argv)
{
    // 调用rclcpp的初始化函数
    rclcpp::init(argc, argv);
    //create a node named "node_03"
    auto node = std::make_shared<Node_03>("node_03");
    //spin the node
    rclcpp::spin(node);
    //shutdown the node
    rclcpp::shutdown();
    

    return 0;
}