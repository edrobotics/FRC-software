// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import edu.wpi.first.wpilibj.TimedRobot;
import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.VictorSPX;

import edu.wpi.first.cameraserver.CameraServer;
import edu.wpi.first.wpilibj.XboxController;

/**
 * The VM is configured to automatically run this class, and to call the functions corresponding to
 * each mode, as described in the TimedRobot documentation. If you change the name of this class or
 * the package after creating this project, you must also update the build.gradle file in the
 * project.
 */
public class Robot extends TimedRobot {
  /**
   * This function is run when the robot is first started up and should be used for any
   * initialization code.
   */
  VictorSPX m_right = new VictorSPX(1);
  VictorSPX m_left = new VictorSPX(2);
  VictorSPX m_right2 = new VictorSPX(3);
  VictorSPX m_left2 = new VictorSPX(4);
  XboxController controller = new XboxController(0);

  @Override
  public void robotInit() {

    m_left.setInverted(true);
    m_left2.setInverted(true);
  }

  @Override
  public void robotPeriodic() {}

  @Override
  public void autonomousInit() {}

  @Override
  public void autonomousPeriodic() {
   
  }

  @Override
  public void teleopInit() {}

  @Override
  public void teleopPeriodic() {
    double lY = controller.getLeftY();
    double rX = controller.getRightX();
    double baseSpeed = lY * lY/2;
    double leftSpeed;
    double rightSpeed;
    if(lY < 0){
      baseSpeed = baseSpeed * -1;
    }
    if(rX>0){
      leftSpeed = baseSpeed;
      rightSpeed = baseSpeed *(1-2*rX);
    }else{
      rightSpeed = baseSpeed;
      leftSpeed = baseSpeed*(1+2*rX);

    }

    m_left.set(ControlMode.PercentOutput, leftSpeed);
    m_left2.set(ControlMode.PercentOutput, leftSpeed);
    m_right.set(ControlMode.PercentOutput, rightSpeed);
    m_right2.set(ControlMode.PercentOutput, rightSpeed);
  }

  @Override
  public void disabledInit() {}

  @Override
  public void disabledPeriodic() {}

  @Override
  public void testInit() {}

  @Override
  public void testPeriodic() {}

  @Override
  public void simulationInit() {}

  @Override
  public void simulationPeriodic() {}
}
