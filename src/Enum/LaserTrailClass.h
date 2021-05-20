#pragma once

#include <GeneralStructures.h>
#include <LaserDrawClass.h>
#include <Enum/LaserTrailTypeClass.h>

#include <vector>

class LaserTrailClass
{
public:
    Valueable<LaserTrailTypeClass*> Type;
    Valueable<bool> Visible;
    // Valueable<int> Delay;
    // Valueable<bool> Ready;
    Nullable<CoordStruct> LastLocation;

    LaserTrailClass(LaserTrailTypeClass* pTrailType, HouseClass* pHouse = nullptr) :
        Type(pTrailType),
        Visible(true),
        // Delay(pTrailType->InitialDelay),
        // Ready(pTrailType->InitialDelay <= 0),
        LastLocation()
    {
        if (this->Type->IsHouseColor && pHouse)
            this->Type->SetHouseColor(pHouse);
    }

    LaserTrailClass() :
        Type(),
        Visible(false),
        // Delay(pTrailType->InitialDelay),
        // Ready(pTrailType->InitialDelay <= 0),
        LastLocation()
    { }

	virtual void LoadFromStream(PhobosStreamReader& Stm);
	virtual void SaveToStream(PhobosStreamWriter& Stm);

    bool Draw(CoordStruct location);

private:
	template <typename T>
	void Serialize(T& Stm);
};