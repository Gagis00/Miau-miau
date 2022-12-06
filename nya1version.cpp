#include "Robot.h"
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc/motorcontrol/Talon.h>
#include <fmt/core.h>
#include "ctre/Phoenix.h"

#include <frc/smartdashboard/SmartDashboard.h>
using namespace frc;

void Robot::RobotInit() {}


void Robot::RobotPeriodic() {}


void Robot::TeleopInit() {}

AHRS gyro{SPI::Port::kMXP}; 
frc::Ultrasonic ultrasonic{1, 2};
frc::Ultrasonic ultrasonic2{1, 2};
WPI_TalonSRX m_left{1};
  WPI_TalonSRX m_right{2};
  WPI_TalonSRX m_left2{3};
  WPI_TalonSRX m_right2{4};
  MotorControllerGroup m_leftGroup{m_left, m_right}
  MotorControllerGroup m_rightGroup{m_left2, m_right2}

  frc::DifferentialDrive m_robotDrive{m_leftGroup, m_rightGroup};

  frc::Joystick m_stick{0};

void Robot::TeleopPeriodic() {  
   m_robotDrive.TankDrive(-m_stick.GetY(), m_stick.GetX());
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif