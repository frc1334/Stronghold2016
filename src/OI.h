#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick* drivestick;
	Joystick* operatestick;
	Button* ButtonAShiftUp;
	Button* ButtonBShiftDown;
	Button* ButtonX;
	Button* ButtonY;
	Button* ButtonAOP;
	Button* ButtonBOP;
	Button* ButtonXOP;
	Button* ButtonYOP;
	USBCamera *cam;
public:
	OI();
	inline float GetSteering() { return -AddDeadZone(drivestick->GetX(), 0.15f); }
	inline float GetPickupManual() {return -AddDeadZone(operatestick->GetRawAxis(1), 0.15f);}
	inline float GetRoller() {return -AddDeadZone(operatestick->GetRawAxis(5),0.15f);}
	inline float GetDriveLeftTrigger() { return drivestick->GetRawAxis(2); }
	inline float GetDriveRightTrigger() { return drivestick->GetRawAxis(3); }
	inline float GetOPLeftTrigger() { return operatestick->GetRawAxis(2); }
	inline float GetOPRightTrigger() { return operatestick->GetRawAxis(3); }
	bool GetDriveA(){ return ButtonAShiftUp->Get();}
	bool GetDriveB(){ return ButtonBShiftDown->Get();}
	bool GetDriveX(){ return ButtonX->Get();}
	bool GetDriveY(){ return ButtonY->Get();}
	bool GetOPA(){ return ButtonAOP->Get();}
	bool GetOPB(){ return ButtonBOP->Get();}
	bool GetOPX(){ return ButtonXOP->Get();}
	bool GetOPY(){ return ButtonYOP->Get();}
	inline float AddDeadZone(float original, float deadzone)
	{
		//Joystick_Drive.get
		  return ((fabs(original) <= deadzone) ? 0 : original);
	}
};

#endif
