#include "GameStateBase.h"
#include "GSIntro.h"
#include "GSMenu.h"
#include "GSPlay.h"
#include "GSPlay2.h"
#include "GSEnd.h"
#include "GSSetting.h"
#include "GSHighScore.h"
#include "GSAbout.h"
#include "GSFinal.h"


GameStateBase* GameStateBase::CreateState(StateTypes st) {
	GameStateBase* gs = nullptr;
	switch ( st )
	{
	case INVALID:
		break;
	case INTRO:
		gs = new GSIntro();
		break;
	case MENU:
		gs = new GSMenu();
		break;
	case PLAY:
		gs = new GSPlay();
		break;
	case PLAY2:
		gs = new GSPlay2();
		break;
	case FINAL:
		gs = new GSFinal();
		break;
	case SETTING:
		gs = new GSSetting();
		break;
	case ABOUT:
		gs = new GSAbout();
		break;
	case HIGHSCORE:
		gs = new GSHighScore();
		break;
	case END:
		gs = new GSEnd();
		break;
	default:
		break;
	}
	return gs;
}