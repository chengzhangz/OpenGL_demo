
// OpenGL_Demo_dialogDlg.h : 头文件
//

#pragma once


// COpenGL_Demo_dialogDlg 对话框
class COpenGL_Demo_dialogDlg : public CDialogEx
{
// 构造
public:
	COpenGL_Demo_dialogDlg(CWnd* pParent = NULL);	// 标准构造函数

	HDC hrenderDC;  //设备上下文
	HGLRC hrenderRC;  //渲染上下文
	float m_yRotate;  //转速
	int PixelFormat;    //像素格式

	BOOL SetWindowPixelFormat(HDC hDC);  //设定像素格式
	BOOL CreateViewGLContext(HDC hDC);   //view GL Context
	void RenderScene();  //绘制场景

// 对话框数据
	enum { IDD = IDD_OPENGL_DEMO_DIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
//	afx_msg LRESULT OnOntimer(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnTimer(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnTimer(WPARAM wParam, LPARAM lParam);
public:
//	afx_msg void OnDevModeChange(LPTSTR lpDeviceName);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
