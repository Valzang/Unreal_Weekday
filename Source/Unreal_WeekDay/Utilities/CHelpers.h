#pragma once
#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

class UNREAL_WEEKDAY_API CHelpers
{
public :
	template<typename T> static void GetAsset(T** outObject, FString inPath)
	{
		// inPath���� ���� ��������
		ConstructorHelpers::FObjectFinder<T> asset(*inPath);
		// ������ �����ߴٰ� �����, ������ �� ����
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outObject = asset.Object;
	}
};