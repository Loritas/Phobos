#pragma once

#include "../SavegameDef.h"

#include <BuildingClass.h>

class FoggedObject
{
public:
	CoordStruct Location;
	RectangleStruct Bound;

public:
	FoggedObject(CoordStruct& location, RectangleStruct& bound);
	FoggedObject(ObjectClass* pObject);

	virtual ~FoggedObject();
	virtual void Draw(RectangleStruct& rect) = 0;
	virtual int GetType();
	virtual BuildingTypeClass* GetBuildingType();
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange);
	virtual bool Save(PhobosStreamWriter& Stm) const;
};

class FoggedSmudge : public FoggedObject
{
public:
	int Smudge;

public:
	FoggedSmudge(CoordStruct& location, RectangleStruct& bound, int smudge);
	FoggedSmudge(ObjectClass* pObject, int smudge);

	virtual ~FoggedSmudge();
	virtual void Draw(RectangleStruct& rect) override;
	virtual int GetType() override;
	virtual BuildingTypeClass* GetBuildingType() override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;
};

class FoggedTerrain : public FoggedObject
{
public:
	int Terrain;

public:
	FoggedTerrain(CoordStruct& location, RectangleStruct& bound, int terrain);
	FoggedTerrain(ObjectClass* pObject, int terrain);

	virtual ~FoggedTerrain();
	virtual void Draw(RectangleStruct& rect) override;
	virtual int GetType() override;
	virtual BuildingTypeClass* GetBuildingType() override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;
};

class FoggedOverlay : public FoggedObject
{
public:
	int Overlay;
	unsigned char OverlayData;

public:
	FoggedOverlay(CoordStruct& location, RectangleStruct& bound, int overlay, unsigned char overlayData);
	FoggedOverlay(ObjectClass* pObject, int overlay, unsigned char overlayData);

	virtual ~FoggedOverlay();
	virtual void Draw(RectangleStruct& rect) override;
	virtual int GetType() override;
	virtual BuildingTypeClass* GetBuildingType() override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;
};

class FoggedBuilding : public FoggedObject
{
public:
	HouseClass* Owner;
	BuildingTypeClass* Type;
	bool FireStormWall;

public:
	FoggedBuilding(CoordStruct& location, RectangleStruct& bound, BuildingClass* building, bool bTranslucent);
	FoggedBuilding(BuildingClass* pObject, bool bTranslucent);

	virtual ~FoggedBuilding();
	virtual void Draw(RectangleStruct& rect) override;
	virtual int GetType() override;
	virtual BuildingTypeClass* GetBuildingType() override;
	virtual bool Load(PhobosStreamReader& Stm, bool RegisterForChange) override;
	virtual bool Save(PhobosStreamWriter& Stm) const override;
};