/*
-----------------------------------------------------------------------------
 Class: ScreenGraphicOptions

 Desc: Change video-related options.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/
#ifndef SCREEN_GRAPHIC_OPTIONS_H
#define SCREEN_GRAPHIC_OPTIONS_H

#include "ScreenOptions.h"

class ScreenGraphicOptions : public ScreenOptions
{
public:
	ScreenGraphicOptions( CString sClassName );

private:
	void UpdateRefreshRates();

	void ImportOptions();
	void ExportOptions();

	void GoToNextState();
	void GoToPrevState();
};

#endif
