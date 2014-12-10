#pragma once

#include "CherryWnd.h"
#include "CherryRadioButton.h"

#include <vector>

using namespace std;

// Message
#define WM_CHERRY_TABCTRL_PAGE_CHANGED WM_USER + 2

// Register Message Map
#define ON_WM_CHERRY_TABCTRL_PAGE_CHANGED(id, memberFxn) \
	ON_CONTROL(WM_CHERRY_TABCTRL_PAGE_CHANGED, id, memberFxn)

///////////////////////////////////////////////////////////////////////////
///
/// \class		CCherryTabCtrl
/// \brief		4���� Tab control
/// \author		����ö
/// \date		2014-04-10
/// \remark		
/// \section	
///
///////////////////////////////////////////////////////////////////////////

class AFX_EXT_CLASS CCherryTabCtrl : public CCherryWnd
{
	DECLARE_DYNAMIC(CCherryTabCtrl)

	enum STYLE
	{
		STYLE_TAB_TOP		= 0x0001,
		STYLE_TAB_BOTTOM	= 0x0002,
		STYLE_TAB_LEFT		= 0x0004,
		STYLE_TAB_RIGHT		= 0x0008,
	};

// Constructors
public:
	CCherryTabCtrl();
	CHERRY_RET Create(
		LPCTSTR lpszTabImagePath,
		DWORD dwCherryStyle,
		DWORD dwStyle,
		const RECT &rect,
		CWnd *pParentWnd,
		UINT nID);

// Attributes
protected:
	DWORD								m_dwCherryStyle;

	CCherryRadioButton					*m_pHeadTab;
	vector<CCherryRadioButton *>		m_tabVector;
	vector<CCherryWnd *>				m_pageVector;

	LPCTSTR								m_lpszTabImagePath;
	UINT								m_nTabGap;

	UINT								m_nCtrlIDCount;
	
// Operations
public:
	CHERRY_RET						AddPage(CCherryWnd *pWnd);
	void							SetCurPage(DWORD dwIndex);
	
	DWORD							GetCurPage();
	DWORD							GetPageCount() const;
	DWORD							DeleteTabPage(DWORD dwIndex);
	DWORD							DeleteTabPageAll();
	
	CCherryRadioButton				*GetTab(UINT nIndex) const;
	CCherryWnd						*GetPage(UINT nIndex) const;

	vector<CCherryRadioButton *>	*GetTabVector();
	vector<CCherryWnd *>			*GetPageVector();

	void							SetTabGap(UINT nGap);

protected:
	void	ResizeWindow();

	DWORD	GetCherryStyle() const;
	void	ModifyCherryStyle(DWORD dwRemove, DWORD dwAdd);

// Implementation
public:
	virtual ~CCherryTabCtrl();

protected:
	DECLARE_MESSAGE_MAP()

	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnDrawCherry(CCherryMemDC *pDC);
	void OnPageChange(DWORD dwIndex);
};