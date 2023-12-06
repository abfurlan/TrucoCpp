
// TrucoCppView.h : interface of the CTrucoCppView class
//

#pragma once


class CTrucoCppView : public CView
{
protected: // create from serialization only
	CTrucoCppView() noexcept;
	DECLARE_DYNCREATE(CTrucoCppView)

// Attributes
public:
	CTrucoCppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTrucoCppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TrucoCppView.cpp
inline CTrucoCppDoc* CTrucoCppView::GetDocument() const
   { return reinterpret_cast<CTrucoCppDoc*>(m_pDocument); }
#endif

