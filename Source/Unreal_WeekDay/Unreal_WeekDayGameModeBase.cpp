// Copyright Epic Games, Inc. All Rights Reserved.


#include "Unreal_WeekDayGameModeBase.h"
#include "Global.h"

AUnreal_WeekDayGameModeBase::AUnreal_WeekDayGameModeBase()
{
	// �������Ʈ�� ��� �ڿ� _C�� �ٿ������. �����.
	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'");

}