/*
-----------------------------------------------------------------------------
 Class: ScreenPrompt

 Desc: Displays a prompt over the top of another screen.  Must use by calling
	SCREENMAN->AddScreenToTop( new ScreenPrompt(...) );

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/

#include "Screen.h"
#include "BitmapText.h"
#include "Transition.h"
#include "Quad.h"
#include "RandomSample.h"


class ScreenPrompt : public Screen
{
public:
	ScreenPrompt( CString sName );
	ScreenPrompt( ScreenMessage SM_SendWhenDone, CString sText, bool bYesNoPrompt=false, bool bDefaultAnswer = false, void(*OnYes)(void*) = NULL, void(*OnNo)(void*) = NULL, void* pCallbackData = NULL );

	virtual void Update( float fDeltaTime );
	virtual void DrawPrimitives();
	virtual void Input( const DeviceInput& DeviceI, const InputEventType type, const GameInput &GameI, const MenuInput &MenuI, const StyleInput &StyleI );
	virtual void HandleScreenMessage( const ScreenMessage SM );

protected:
	void MenuLeft( PlayerNumber pn );
	void MenuRight( PlayerNumber pn );
	void MenuBack( PlayerNumber pn );
	void MenuStart( PlayerNumber pn );


	BGAnimation					m_Background;
	BitmapText		m_textQuestion;
	Quad			m_rectAnswerBox;
	BitmapText		m_textAnswer[2];	// "YES" or "NO"
	bool			m_bYesNoPrompt;		// false = OK prompt, true = YES/NO prompt
	bool			m_bAnswer;		// true = "YES", false = "NO";
	ScreenMessage	m_SMSendWhenDone;
	void(*m_pOnYes)(void*);
	void(*m_pOnNo)(void*);
	void* m_pCallbackData;
	Transition		m_In;
	Transition		m_Out;
};

