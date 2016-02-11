#include "OI.h"
#include "RobotMap.h"
OI::OI()
{
	drivestick = new Joystick(JOYSTICK_DRIVE);
	operatestick = new Joystick(JOYSTICK_OPERATOR);
	ButtonAShiftUp = new JoystickButton(drivestick,1);
	ButtonBShiftDown = new JoystickButton(drivestick,2);
	ButtonX = new JoystickButton(drivestick,3);
	ButtonY = new JoystickButton(drivestick,4);
	ButtonAOP = new JoystickButton(operatestick,1);
	ButtonBOP = new JoystickButton(operatestick,2);
	ButtonXOP = new JoystickButton(operatestick,3);
	ButtonYOP = new JoystickButton(operatestick,4);
	cam = new USBCamera("cam1",true);
}
