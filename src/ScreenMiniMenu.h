/* ScreenMiniMenu - Displays a simple menu over the top of another screen. */

#ifndef SCREEN_MINI_MENU_H
#define SCREEN_MINI_MENU_H

#include "ScreenOptions.h"
#include "GameConstantsAndTypes.h"

typedef bool (*MenuRowUpdateEnabled)();

struct MenuRowDef
{
	int			iRowCode;
	RString		sName;
	bool		bEnabled;
	MenuRowUpdateEnabled	pfnEnabled;	// if ! nullptr, used instead of bEnabled
	EditMode	emShowIn;
	int			iDefaultChoice;
	std::vector<RString>		choices;
	bool		bThemeTitle;
	bool		bThemeItems;

	MenuRowDef(): iRowCode(0), sName(""), bEnabled(false),
		pfnEnabled(), emShowIn(), iDefaultChoice(0),
		choices(), bThemeTitle(false), bThemeItems(false) {}
	MenuRowDef( int r, RString n, MenuRowUpdateEnabled pe, EditMode s, 
		   bool bTT, bool bTI, int d, const char *c0=nullptr, 
		   const char *c1=nullptr, const char *c2=nullptr, 
		   const char *c3=nullptr, const char *c4=nullptr, 
		   const char *c5=nullptr, const char *c6=nullptr, 
		   const char *c7=nullptr, const char *c8=nullptr, 
		   const char *c9=nullptr, const char *c10=nullptr, 
		   const char *c11=nullptr, const char *c12=nullptr, 
		   const char *c13=nullptr, const char *c14=nullptr, 
		   const char *c15=nullptr, const char *c16=nullptr, 
		   const char *c17=nullptr, const char *c18=nullptr, 
		   const char *c19=nullptr, const char *c20=nullptr, 
		   const char *c21=nullptr, const char *c22=nullptr, 
		   const char *c23=nullptr, const char *c24=nullptr, 
		   const char *c25=nullptr ): iRowCode(r), sName(n),
			bEnabled(true), pfnEnabled(pe), emShowIn(s),
			iDefaultChoice(d), choices(),
			bThemeTitle(bTT), bThemeItems(bTI)
	{
#define PUSH( c )	if(c) choices.push_back(c);
		PUSH(c0);PUSH(c1);PUSH(c2);PUSH(c3);PUSH(c4);PUSH(c5);
		PUSH(c6);PUSH(c7);PUSH(c8);PUSH(c9);PUSH(c10);PUSH(c11);
		PUSH(c12);PUSH(c13);PUSH(c14);PUSH(c15);PUSH(c16);PUSH(c17);
		PUSH(c18);PUSH(c19);PUSH(c20);PUSH(c21);PUSH(c22);PUSH(c22);
		PUSH(c23);PUSH(c23);PUSH(c24);PUSH(c25);
#undef PUSH
	}
	
	MenuRowDef(int r, RString n, bool e, EditMode s,
			   bool bTT, bool bTI, int d, std::vector<RString> options):
			iRowCode(r), sName(n), bEnabled(e), pfnEnabled(nullptr),
			emShowIn(s), iDefaultChoice(d), choices(),
			bThemeTitle(bTT), bThemeItems(bTI)
	{
		for (RString &str : options)
		{
			if (str != "") choices.push_back(str);
		}
	}
	
	MenuRowDef( int r, RString n, bool e, EditMode s, bool bTT, bool bTI, 
		   int d, const char *c0=nullptr, const char *c1=nullptr, 
		   const char *c2=nullptr, const char *c3=nullptr, 
		   const char *c4=nullptr, const char *c5=nullptr, 
		   const char *c6=nullptr, const char *c7=nullptr, 
		   const char *c8=nullptr, const char *c9=nullptr, 
		   const char *c10=nullptr, const char *c11=nullptr, 
		   const char *c12=nullptr, const char *c13=nullptr, 
		   const char *c14=nullptr, const char *c15=nullptr, 
		   const char *c16=nullptr, const char *c17=nullptr, 
		   const char *c18=nullptr, const char *c19=nullptr, 
		   const char *c20=nullptr, const char *c21=nullptr, 
		   const char *c22=nullptr, const char *c23=nullptr, 
		   const char *c24=nullptr, const char *c25=nullptr ):
		iRowCode(r), sName(n), bEnabled(e), pfnEnabled(nullptr),
		emShowIn(s), iDefaultChoice(d), choices(),
		bThemeTitle(bTT), bThemeItems(bTI)
	{
#define PUSH( c )	if(c) choices.push_back(c);
		PUSH(c0);PUSH(c1);PUSH(c2);PUSH(c3);PUSH(c4);PUSH(c5);
		PUSH(c6);PUSH(c7);PUSH(c8);PUSH(c9);PUSH(c10);PUSH(c11);
		PUSH(c12);PUSH(c13);PUSH(c14);PUSH(c15);PUSH(c16);PUSH(c17);
		PUSH(c18);PUSH(c19);PUSH(c20);PUSH(c21);PUSH(c22);PUSH(c22);
		PUSH(c23);PUSH(c23);PUSH(c24);PUSH(c25);
#undef PUSH
	}
	
	MenuRowDef( int r, RString n, bool e, EditMode s, bool bTT, bool bTI,
		   int d, int low, int high ):
		iRowCode(r), sName(n), bEnabled(e), pfnEnabled(nullptr),
		emShowIn(s), iDefaultChoice(d), choices(),
		bThemeTitle(bTT), bThemeItems(bTI)
	{
		for ( int i = low; i <= high; i++ )
		{
			choices.push_back(std::to_string(i));
		}
	}

	void SetOneUnthemedChoice( const RString &sChoice )
	{
		choices.resize(1);
		choices[0] = "|" + sChoice;
	}

	bool SetDefaultChoiceIfPresent( RString sChoice )
	{
		iDefaultChoice = 0;
		for (unsigned i = 0; i < choices.size(); ++i)
		{
			if (choices[i] == sChoice)
			{
				iDefaultChoice = i;
				return true;
			}
		}
		return false;
	}
};

struct MenuDef
{
	RString sClassName;
	std::vector<MenuRowDef> rows;

	MenuDef( RString c, MenuRowDef r0=MenuRowDef(), 
		MenuRowDef r1=MenuRowDef(), MenuRowDef r2=MenuRowDef(), 
		MenuRowDef r3=MenuRowDef(), MenuRowDef r4=MenuRowDef(), 
		MenuRowDef r5=MenuRowDef(), MenuRowDef r6=MenuRowDef(), 
		MenuRowDef r7=MenuRowDef(), MenuRowDef r8=MenuRowDef(), 
		MenuRowDef r9=MenuRowDef(), MenuRowDef r10=MenuRowDef(), 
		MenuRowDef r11=MenuRowDef(), MenuRowDef r12=MenuRowDef(), 
		MenuRowDef r13=MenuRowDef(), MenuRowDef r14=MenuRowDef(), 
		MenuRowDef r15=MenuRowDef(), MenuRowDef r16=MenuRowDef(), 
		MenuRowDef r17=MenuRowDef(), MenuRowDef r18=MenuRowDef(), 
		MenuRowDef r19=MenuRowDef(), MenuRowDef r20=MenuRowDef(), 
		MenuRowDef r21=MenuRowDef(), MenuRowDef r22=MenuRowDef(), 
		MenuRowDef r23=MenuRowDef(), MenuRowDef r24=MenuRowDef(), 
		MenuRowDef r25=MenuRowDef(), MenuRowDef r26=MenuRowDef(), 
		MenuRowDef r27=MenuRowDef(), MenuRowDef r28=MenuRowDef(),
		MenuRowDef r29=MenuRowDef() ): sClassName(c), rows()
	{
#define PUSH( r )	if(!r.sName.empty()) rows.push_back(r);
		PUSH(r0);PUSH(r1);PUSH(r2);PUSH(r3);PUSH(r4);PUSH(r5);PUSH(r6);
		PUSH(r7);PUSH(r8);PUSH(r9);PUSH(r10);PUSH(r11);PUSH(r12);
		PUSH(r13);PUSH(r14);PUSH(r15);PUSH(r16);PUSH(r17);PUSH(r18);
		PUSH(r19);PUSH(r20);PUSH(r21);PUSH(r22);PUSH(r23);PUSH(r24);
		PUSH(r25);PUSH(r26);PUSH(r27);PUSH(r28);PUSH(r29);
#undef PUSH
	}
};


class ScreenMiniMenu : public ScreenOptions
{
public:
	static void MiniMenu( const MenuDef* pDef, ScreenMessage smSendOnOK, 
			     ScreenMessage smSendOnCancel = SM_None, 
			     float fX = 0, float fY = 0 );

	void Init();
	void BeginScreen();
	void HandleScreenMessage( const ScreenMessage SM );

protected:
	virtual void AfterChangeValueOrRow( PlayerNumber pn );
	virtual void ImportOptions( int iRow, const std::vector<PlayerNumber> &vpns );
	virtual void ExportOptions( int iRow, const std::vector<PlayerNumber> &vpns );

	virtual bool FocusedItemEndsScreen( PlayerNumber pn ) const;

	void LoadMenu( const MenuDef* pDef );

	ScreenMessage		m_SMSendOnOK;
	ScreenMessage		m_SMSendOnCancel;

	std::vector<MenuRowDef>	m_vMenuRows;

public:
	ScreenMiniMenu(): m_SMSendOnOK(), m_SMSendOnCancel(), m_vMenuRows() {}
	
	static bool s_bCancelled;
	static int s_iLastRowCode;
	static std::vector<int>	s_viLastAnswers;
};

#endif

/*
 * (c) 2003-2004 Chris Danford
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
