
// TrucoCppView.cpp : implementation of the CTrucoCppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TrucoCpp.h"
#endif

#include "TrucoCppDoc.h"
#include "TrucoCppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTrucoCppView

IMPLEMENT_DYNCREATE(CTrucoCppView, CView)

BEGIN_MESSAGE_MAP(CTrucoCppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTrucoCppView construction/destruction

CTrucoCppView::CTrucoCppView() noexcept
{
	// TODO: add construction code here

}

CTrucoCppView::~CTrucoCppView()
{
}

BOOL CTrucoCppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTrucoCppView drawing

void CTrucoCppView::OnDraw(CDC* /*pDC*/)
{
	CTrucoCppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTrucoCppView printing

BOOL CTrucoCppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTrucoCppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTrucoCppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTrucoCppView diagnostics

#ifdef _DEBUG
void CTrucoCppView::AssertValid() const
{
	CView::AssertValid();
}

void CTrucoCppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrucoCppDoc* CTrucoCppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTrucoCppDoc)));
	return (CTrucoCppDoc*)m_pDocument;
}
#endif //_DEBUG


// CTrucoCppView message handlers
