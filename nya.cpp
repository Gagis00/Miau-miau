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

void Robot::RobotInit() {
  m_rightGroup.SetInverted(true);
  ultrasonic.SetAutomaticMode(true);
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}


void Robot::RobotPeriodic() {}


void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
 
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {

    
  
  } else {
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {

    if(ultrasonic.GetRangeInches() > 7) {
      
      drive.TankDrive(.5, .5);
    } else {
      drive.TankDrive(0, 0);
    }

    giroizqui();

    m_robotDrive.TankDrive(m_leftGroup(1), m_rightGroup(1));


  }
}

//you spin me right roung baby right round

void giroderecha() {
  m_robotDrive.TankDrive(m_leftGroup(.5), m_rightGroup(-.5));
}

void giroderecha2() {

  m_rightGroup.setInverted(true);
  m_robotDrive.TankDrive(m_leftGroup(.5), m_rightGroup(-.5));
}

//so

void giroizq() {
  m_robotDrive.TankDrive(m_leftGroup(-.5), m_rightGroup(.5));
}

void giroizq2() {

  m_leftGroup.setInverted(true);
  m_robotDrive.TankDrive(m_leftGroup(-.5), m_rightGroup(.5));
}

//you spin me right roung baby right round

//giros

void giroder() {
  double error = 90 - gyro.GetAngle();

  drive.TankDrive(kP * error, -kP * error);
}

void giroizqui() {
  double error = -90 - gyro.GetAngle();

  drive.TankDrive(kP * error, -kP * error);
}

//giros

double kP = 0.05;

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