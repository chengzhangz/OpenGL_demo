
// OpenGL_Demo_dialogDlg.h : ͷ�ļ�
//

#pragma once


// COpenGL_Demo_dialogDlg �Ի���
class COpenGL_Demo_dialogDlg : public CDialogEx
{
// ����
public:
	COpenGL_Demo_dialogDlg(CWnd* pParent = NULL);	// ��׼���캯��

	HDC hrenderDC;  //�豸������
	HGLRC hrenderRC;  //��Ⱦ������
	float m_yRotate;  //ת��
	int PixelFormat;    //���ظ�ʽ

	BOOL SetWindowPixelFormat(HDC hDC);  //�趨���ظ�ʽ
	BOOL CreateViewGLContext(HDC hDC);   //view GL Context
	void RenderScene();  //���Ƴ���

// �Ի�������
	enum { IDD = IDD_OPENGL_DEMO_DIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
