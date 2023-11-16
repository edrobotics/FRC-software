// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <math.h>
#include <iostream>
#include <fmt/core.h>
#include <frc/Timer.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser); 
  m_left.SetInverted(true);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  double lY = controller.GetLeftY();
  double rX = controller.GetRightX();

//Square input, reapply sign  
  double speed = std::copysign(lY * lY, lY);
  double rotation = std::copysign(rX * rX, rX);

//Arcade drive
  double maximum = fmax(abs(speed), abs(rotation));
  double total = speed + rotation;
  double difference = speed - rotation;
  double leftspeed{0};
  double rightspeed{0};

  if (speed >= 0)
    if (rotation >= 0) {
      leftspeed = maximum;
      rightspeed = difference;
      }
    else {
      leftspeed = total;
      rightspeed = maximum;
      }
  else
    if (rotation >= 0) {
      leftspeed = total;
      rightspeed = -maximum;
      }
    else {
      leftspeed = -maximum;
      rightspeed = difference;
      }

  m_right.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, rightspeed);
  m_right2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, rightspeed);
  m_left.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, leftspeed);
  m_left2.Set(ctre::phoenix::motorcontrol::VictorSPXControlMode::PercentOutput, leftspeed);

// Flywheel
  double flywheel_speed = controller.GetRightTriggerAxis();
  flywheel.Set(ctre::phoenix::motorcontrol::TalonSRXControlMode::PercentOutput, flywheel_speed);
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif