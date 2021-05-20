#include "LaserTrailTypeClass.h"

#include <Utilities/TemplateDef.h>
#include <HouseClass.h>

Enumerable<LaserTrailTypeClass>::container_t Enumerable<LaserTrailTypeClass>::Array;

const char* Enumerable<LaserTrailTypeClass>::GetMainSection()
{
    return "LaserTrailTypes";
}

void LaserTrailTypeClass::LoadFromINI(CCINIClass* pINI)
{
    const char* section = this->Name;

    INI_EX exINI(pINI);

    this->IsHouseColor.Read(exINI, section, "IsHouseColor");

    this->InnerColor.Read(exINI, section, "InnerColor");
    this->OuterColor.Read(exINI, section, "OuterColor");
    this->OuterSpread.Read(exINI, section, "OuterSpread");

    this->Duration.Read(exINI, section, "Duration");
    this->Thickness.Read(exINI, section, "Thickness");
    this->Distance.Read(exINI, section, "Distance");
    this->IgnoreVertical.Read(exINI, section, "IgnoreVertical");
    // this->InitialDelay.Read(exINI, section, "InitialDelay");

    /*
        CoordStruct tempFLH;
        for (int i = 0; i <= FLHList.size(); i++)
        {
            if (detail::read<CoordStruct>(tempFLH, exINI, section, "LaserTailFLH" + i))
            {
                if (i == FLHList.size())
                    FLHList.push_back(tempFLH);
                else
                    FLHList[i] = tempFLH;
            }
        }
    */
}

template <typename T>
void LaserTrailTypeClass::Serialize(T& Stm)
{
    Stm
        .Process(this->IsHouseColor)
        .Process(this->InnerColor)
        .Process(this->OuterColor)
        .Process(this->OuterSpread)
        .Process(this->Duration)
        .Process(this->Thickness)
        .Process(this->Distance)
        .Process(this->IgnoreVertical)
        // .Process(this->InitialDelay)
        ;
};

void LaserTrailTypeClass::LoadFromStream(PhobosStreamReader& Stm)
{
    this->Serialize(Stm);
}

void LaserTrailTypeClass::SaveToStream(PhobosStreamWriter& Stm)
{
    this->Serialize(Stm);
}

void LaserTrailTypeClass::SetHouseColor(HouseClass* pHouse) 
{
    auto c = pHouse->LaserColor;
    
    this->InnerColor = c;
    this->OuterColor = ColorStruct { (BYTE)(c.R / 2), (BYTE)(c.G / 2), (BYTE)(c.B / 2) };
    this->OuterSpread = ColorStruct { 0, 0, 0 };
}
