// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/I2C.h>
#include <frc/SerialPort.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

  ctre::phoenix::motorcontrol::can::VictorSPX m_right{1};
  ctre::phoenix::motorcontrol::can::VictorSPX m_left{2};
  ctre::phoenix::motorcontrol::can::VictorSPX m_right2{3};
  ctre::phoenix::motorcontrol::can::VictorSPX m_left2{4};
  frc::XboxController controller{0};
  ctre::phoenix::motorcontrol::can::TalonSRX flywheel{1};
// The serial port is defined here kOnboard is the default value although you
// might be able to use usb acording to the reference: https://github.wpilib.org/allwpilib/docs/release/cpp/classfrc_1_1_serial_port.html
  frc::SerialPort arduino{9600, frc::SerialPort::kUSB1};
  char senddata{1};
  char* sendpointer{&senddata};

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
