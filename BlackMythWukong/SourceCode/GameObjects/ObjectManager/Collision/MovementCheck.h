#pragma once
#include "../../../GameManager/ResourceManager.h"
class MovementCheck 
{
public:
	bool IsMoving();
	void FacingCheck();
	void MFacingCheck(float monster_posx, float player_posx);
	bool FacingLeft();
	bool FacingRight();
private:
	bool m_isMoving;
	bool m_leftfacing, m_rightfacing;
};