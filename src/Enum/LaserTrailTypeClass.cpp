#include "LaserTrailTypeClass.h"

#include <Utilities/TemplateDef.h>


Enumerable<LaserTrailTypeClass>::container_t Enumerable<LaserTrailTypeClass>::Array;

// pretty nice, eh
const char* Enumerable<LaserTrailTypeClass>::GetMainSection()
{
    return "LaserTrailTypes";
}


void LaserTrailTypeClass::LoadListSection(CCINIClass * pINI)
{
    for (int i = 0; i < pINI->GetKeyCount(GetMainSection()); ++i)
    {
        if (pINI->ReadString(GetMainSection(), pINI->GetKeyName(GetMainSection(), i), "", Phobos::readBuffer))
        {
            FindOrAllocate(Phobos::readBuffer);
            Debug::Log("LaserTrailTypeClass :: LoadListSection check [%s] \n", Phobos::readBuffer);
        }
    }

    for (auto &trailType: Array)
        trailType->LoadFromINI(pINI);
}

void LaserTrailTypeClass::LoadFromINI(CCINIClass * pINI)
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
    this->InitialDelay.Read(exINI, section, "InitialDelay");
}

template <typename T>
void LaserTrailTypeClass::Serialize(T & Stm)
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
        .Process(this->InitialDelay)
        ;
};

void LaserTrailTypeClass::LoadFromStream(PhobosStreamReader & Stm)
{
    this->Serialize(Stm);
}

void LaserTrailTypeClass::SaveToStream(PhobosStreamWriter & Stm)
{
    this->Serialize(Stm);
}
