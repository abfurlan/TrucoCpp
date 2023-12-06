
// TrucoCpp.h : main header file for the TrucoCpp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTrucoCppApp:
// See TrucoCpp.cpp for the implementation of this class
//

class CTrucoCppApp : public CWinApp
{
public:
	CTrucoCppApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTrucoCppApp theApp;
