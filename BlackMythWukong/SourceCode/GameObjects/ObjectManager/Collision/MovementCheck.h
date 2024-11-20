#pragma once
#include "../../../GameManager/ResourceManager.h"
class MovementCheck 
{
public:
	bool IsMoving();
	void FacingCheck();
	bool FacingLeft();
	bool FacingRight();
private:
	bool m_isMoving;
	bool m_leftfacing, m_rightfacing;
};