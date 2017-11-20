#ifndef C_SUNLIGHTSHADOWCONTROL_H
#define C_SUNLIGHTSHADOWCONTROL_H
#ifdef _WIN32
#pragma once
#endif

#include "c_baseentity.h"
#include "basetypes.h"
//------------------------------------------------------------------------------
// Purpose : Sunlights shadow control entity
//------------------------------------------------------------------------------
class C_SunlightShadowControl : public C_BaseEntity
{
public:
	DECLARE_CLASS(C_SunlightShadowControl, C_BaseEntity);

	DECLARE_CLIENTCLASS();

	virtual ~C_SunlightShadowControl();

	void OnDataChanged(DataUpdateType_t updateType);
	void Spawn();
	bool ShouldDraw();

	void ClientThink();

private:
	Vector m_shadowDirection;
	bool m_bEnabled;
	char m_TextureName[MAX_PATH];
	CTextureReference m_SpotlightTexture;
	color32	m_LightColor;
	Vector m_CurrentLinearFloatLightColor;
	float m_flCurrentLinearFloatLightAlpha;
	float m_flColorTransitionTime;
	float m_flSunDistance;
	float m_flFOV;
	float m_flNearZ;
	float m_flNorthOffset;
	bool m_bEnableShadows;
	bool m_bOldEnableShadows;

	//Be able to change shadowmap resolution
	int m_flShadowMapResolution;

	static ClientShadowHandle_t m_LocalFlashlightHandle;
};

#endif