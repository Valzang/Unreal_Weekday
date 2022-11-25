// Copyright Epic Games, Inc. All Rights Reserved.


#include "Unreal_WeekDayGameModeBase.h"
#include "Global.h"

AUnreal_WeekDayGameModeBase::AUnreal_WeekDayGameModeBase()
{
	// 블루프린트의 경우 뒤에 _C를 붙여줘야함. 약속임.
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");

}