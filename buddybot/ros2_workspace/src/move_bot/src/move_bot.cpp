#include "rclcpp/rclcpp.hpp"
#include "move_bot/msg/movement.hpp"  // Include the header for the custom message
extern "C" {
    #include "../include/move_bot/spi.h"  // Adjust the include path if necessary
}

class Move : public rclcpp::Node
{
public:
  Move()
      : Node("move_node")
  {
    // Initialize SPI connection
    if (!spi_open())
    {
      RCLCPP_ERROR(this->get_logger(), "Failed to initialize SPI connection");
    }
    else
    {
      RCLCPP_INFO(this->get_logger(), "SPI connection initialized successfully");
    }

    // Use the correct namespace and message name
    subscription_ = this->create_subscription<move_bot::msg::Movement>(
        "movement_commands", 10,
        std::bind(&Move::movement_command_callback, this, std::placeholders::_1));
  }

private:
  void movement_command_callback(const move_bot::msg::Movement::SharedPtr msg)
  {
    auto command = msg->command;
    auto speed = msg->speed;

    if (command == "forward")
    {
      move_forward(speed);
    }
    else if (command == "stop")
    {
      move_stop(get_spi_fd());
    }
    else if (command == "left")
    {
        move_left(get_spi_fd());
    }
    else if (command == "right")
    {
        move_right(get_spi_fd());
    }
    else if (command == "backwards")
    {
        move_back(get_spi_fd());
    }
  }

  rclcpp::Subscription<move_bot::msg::Movement>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Move>());
  rclcpp::shutdown();
  return 0;
}
