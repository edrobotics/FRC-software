// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot;

import com.ctre.phoenix.motorcontrol.ControlMode;
import com.ctre.phoenix.motorcontrol.can.TalonSRX;
import com.ctre.phoenix.motorcontrol.can.VictorSPX;

import edu.wpi.first.cameraserver.CameraServer;
import edu.wpi.first.wpilibj.TimedRobot;
import edu.wpi.first.wpilibj.XboxController;

/**
 * The VM is configured to automatically run this class, and to call the functions corresponding to
 * each mode, as described in the TimedRobot documentation. If you change the name of this class or
 * the package after creating this project, you must also update the build.gradle file in the
 * project.
 */
public class Robot extends TimedRobot {
  VictorSPX m_left = new VictorSPX(2);
  VictorSPX m_right = new VictorSPX(1);
  XboxController controller = new XboxController(0);

  /**
   * This function is run when the robot is first started up and should be used for any
   * initialization code.
   */
  @Override
  public void robotInit() {
   // myVictor.set(ControlMode.PercentOutput, 0);
    System.out.println(1);
    m_left.setInverted(true);
    CameraServer.startAutomaticCapture();
  }

  @Override
  public void robotPeriodic() {}

  @Override
  public void autonomousInit() {}

  @Override
  public void autonomousPeriodic() {

  //.set(ControlMode.PercentOutput, 0.2);
  }

  @Override
  public void teleopInit() {

  }

  @Override
  public void teleopPeriodic() {
    double lY = controller.getLeftY()/2.0;
    double rY = controller.getRightY()/2.0;
    m_left.set(ControlMode.PercentOutput, lY);
    m_right.set(ControlMode.PercentOutput, rY);
    


    //System.out.println(y);
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
