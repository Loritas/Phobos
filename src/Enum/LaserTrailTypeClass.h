#pragma once

#include "_Enumerator.hpp"
#include <Utilities/Template.h>

class LaserTrailTypeClass final : public Enumerable<LaserTrailTypeClass>
{
public:
    Valueable<bool> IsHouseColor;
    Valueable<ColorStruct> InnerColor;
    Valueable<ColorStruct> OuterColor;
    Valueable<ColorStruct> OuterSpread;
    Valueable<int> Duration;
    Valueable<int> Thickness;
    Valueable<int> Distance;
    Valueable<bool> IgnoreVertical;
    Valueable<int> InitialDelay;

    LaserTrailTypeClass (const char* pTitle) : Enumerable<LaserTrailTypeClass>(pTitle),
        IsHouseColor(false),
        InnerColor({ 204, 64, 6 }),
        OuterColor({ 102, 32, 3 }),
        OuterSpread({ 0, 0, 0 }),
        Duration(15),
        Thickness(2),
        Distance(100),
        IgnoreVertical(false),
        InitialDelay(0)
    { }

    virtual ~LaserTrailTypeClass() override = default;

	static void LoadListSection(CCINIClass* pINI);
	virtual void LoadFromINI(CCINIClass* pINI) override;
	virtual void LoadFromStream(PhobosStreamReader& Stm);
	virtual void SaveToStream(PhobosStreamWriter& Stm);

    void SetHouseColor(HouseClass* pHouse);

private:
	template <typename T>
	void Serialize(T& Stm);
};