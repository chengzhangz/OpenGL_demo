
// OpenGL_Demo_dialogDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OpenGL_Demo_dialog.h"
#include "OpenGL_Demo_dialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COpenGL_Demo_dialogDlg �Ի���



COpenGL_Demo_dialogDlg::COpenGL_Demo_dialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpenGL_Demo_dialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenGL_Demo_dialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenGL_Demo_dialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//ON_MESSAGE(Timer, &COpenGL_Demo_dialogDlg::OnTimer)
//ON_WM_DEVMODECHANGE()
ON_WM_TIMER()
END_MESSAGE_MAP()


// COpenGL_Demo_dialogDlg ��Ϣ�������

BOOL COpenGL_Demo_dialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	///////////////////////OPENGL INIT///////////////////////// 
	CWnd *wnd=GetDlgItem(IDC_RENDER); 
	hrenderDC=::GetDC(wnd->m_hWnd); 
	if(SetWindowPixelFormat(hrenderDC)==FALSE) 
		return 0; 

	if(CreateViewGLContext(hrenderDC)==FALSE) 
		return 0; 

	glPolygonMode(GL_FRONT,GL_FILL); 
	glPolygonMode(GL_BACK,GL_FILL); 
	/////////////////////////////////////////// 
	glEnable(GL_TEXTURE_2D); 
	glShadeModel(GL_SMOOTH); 
	glViewport(0,0,800,480); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45,1,0.1,100.0); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	glShadeModel(GL_SMOOTH);       // Enable Smooth Shading 
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);    // Black Background 
	glClearDepth(1.0f);         // Depth Buffer Setup 
	glEnable(GL_DEPTH_TEST);       // Enables Depth Testing 
	glDepthFunc(GL_LEQUAL); // The Type Of Depth Testing To Do 
	///////////////////////////////////////////////////////////////////////// 
	glEnableClientState(GL_VERTEX_ARRAY); 
	glEnableClientState(GL_TEXTURE_COORD_ARRAY); 

	SetTimer(1,10,0); 

	////////////////////////////////////////////////////////////////
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COpenGL_Demo_dialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COpenGL_Demo_dialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		//��̬�޸Ĵ��ڵĴ�С
		//ClientToScreen(&rect);//ת��ΪӫĻ���� 
		//MoveWindow(rect.left, rect.top, 1920, 800);//���ô�����ʾ��λ���Լ���С 	
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COpenGL_Demo_dialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpenGL_Demo_dialogDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	RenderScene(); 
	m_yRotate +=3; 
	CDialogEx::OnTimer(nIDEvent);
}


BOOL COpenGL_Demo_dialogDlg::SetWindowPixelFormat(HDC hDC) 
{ 
	PIXELFORMATDESCRIPTOR pixelDesc; 

	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR); 
	pixelDesc.nVersion = 1; 

	pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW |  
		PFD_SUPPORT_OPENGL | 
		PFD_DOUBLEBUFFER | 
		PFD_TYPE_RGBA; 

	pixelDesc.iPixelType = PFD_TYPE_RGBA; 
	pixelDesc.cColorBits = 32; 
	pixelDesc.cRedBits = 0; 
	pixelDesc.cRedShift = 0; 
	pixelDesc.cGreenBits = 0; 
	pixelDesc.cGreenShift = 0; 
	pixelDesc.cBlueBits = 0; 
	pixelDesc.cBlueShift = 0; 
	pixelDesc.cAlphaBits = 0; 
	pixelDesc.cAlphaShift = 0; 
	pixelDesc.cAccumBits = 0; 
	pixelDesc.cAccumRedBits = 0; 
	pixelDesc.cAccumGreenBits = 0; 
	pixelDesc.cAccumBlueBits = 0; 
	pixelDesc.cAccumAlphaBits = 0; 
	pixelDesc.cDepthBits = 0; 
	pixelDesc.cStencilBits = 1; 
	pixelDesc.cAuxBuffers = 0; 
	pixelDesc.iLayerType = PFD_MAIN_PLANE; 
	pixelDesc.bReserved = 0; 
	pixelDesc.dwLayerMask = 0; 
	pixelDesc.dwVisibleMask = 0; 
	pixelDesc.dwDamageMask = 0; 

	PixelFormat = ChoosePixelFormat(hDC,&pixelDesc); 
	if(PixelFormat==0) // Choose default 
	{ 
		PixelFormat = 1; 
		if(DescribePixelFormat(hDC,PixelFormat, 
			sizeof(PIXELFORMATDESCRIPTOR),&pixelDesc)==0) 
		{ 
			return FALSE; 
		} 
	} 

	if(SetPixelFormat(hDC,PixelFormat,&pixelDesc)==FALSE) 

	{  
		return FALSE; 
	} 

	return TRUE; 
}

BOOL COpenGL_Demo_dialogDlg::CreateViewGLContext(HDC hDC) 
{ 
	hrenderRC = wglCreateContext(hDC); 

	if(hrenderRC==NULL) 
		return FALSE; 

	if(wglMakeCurrent(hDC,hrenderRC)==FALSE) 
		return FALSE; 



	return TRUE; 
}

void COpenGL_Demo_dialogDlg::RenderScene()    
{ 
	///////////////////////////////////////////////// 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity(); 
	glTranslatef(0.0f,0.0f,-6.0f);      // Move Left 1.5 Units And Into The Screen 6.0 
	glRotated(m_yRotate, 0.0, 1.0, 0.0); 
	glBegin(GL_TRIANGLES); // Drawing Using Triangles 

	glVertex3f( 0.0f, 1.0f, 0.0f);     // Top 
	glVertex3f(-1.0f,-1.0f, 0.0f);     // Bottom Left 
	glVertex3f( 1.0f,-1.0f, 0.0f);     // Bottom Right 
	glEnd();           // Finished Drawing The Triangle 
	SwapBuffers(hrenderDC); 
}