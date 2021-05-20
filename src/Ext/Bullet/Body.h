#pragma once
#include <BulletClass.h>

#include <Helpers/Macro.h>
#include "../_Container.hpp"
#include "../../Utilities/TemplateDef.h"

#include <Enum/LaserTrailClass.h>

class BulletExt
{
public:
	using base_type = BulletClass;

	class ExtData final : public Extension<BulletClass>
	{
	public:
		Valueable<bool> Intercepted;
		Valueable<bool> ShouldIntercept;
        std::unique_ptr<LaserTrailClass> LaserTrail;

		ExtData(BulletClass* OwnerObject) : Extension<BulletClass>(OwnerObject),
			Intercepted(false),
			ShouldIntercept(false),
            LaserTrail()
		{ }

		virtual ~ExtData() = default;

        virtual void Initialize() override;

		virtual void InvalidatePointer(void* ptr, bool bRemoved) override {}

		virtual void LoadFromStream(PhobosStreamReader& Stm) override;
		virtual void SaveToStream(PhobosStreamWriter& Stm) override;

		void ApplyRadiationToCell(CellStruct Cell, int Spread, int RadLevel);

	private:
		template <typename T>
		void Serialize(T& Stm);
	};

	class ExtContainer final : public Container<BulletExt> {
	public:
		ExtContainer();
		~ExtContainer();
	};

	static ExtContainer ExtMap;
};
