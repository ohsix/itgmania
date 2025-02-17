/* ScreenDebugOverlay - credits and statistics drawn on top of everything else. */

#ifndef ScreenDebugOverlay_H
#define ScreenDebugOverlay_H

#include "Screen.h"
#include "BitmapText.h"
#include "Quad.h"

void ChangeVolume( float fDelta );
void ChangeVisualDelay( float fDelta );

class ScreenDebugOverlay : public Screen
{
public:
	virtual ~ScreenDebugOverlay();
	virtual void Init();

	bool Input( const InputEventPlus &input );

	void Update( float fDeltaTime );

private:
	void UpdateText();

	RString GetCurrentPageName() const { return m_asPages[m_iCurrentPage]; }
	std::vector<RString> m_asPages;
	int m_iCurrentPage;
	bool m_bForcedHidden;

	Quad m_Quad;
	BitmapText m_textHeader;
	std::vector<BitmapText*> m_vptextPages;
	std::vector<BitmapText*> m_vptextButton;
	std::vector<BitmapText*> m_vptextFunction;
};


#endif

/*
 * (c) 2001-2005 Chris Danford, Glenn Maynard
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
