
// coilDlg.h : ͷ�ļ�
//

#pragma once


// CcoilDlg �Ի���
class CcoilDlg : public CDialogEx
{
// ����
public:
	CcoilDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_COIL_DIALOG };

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
public:
	afx_msg void OnBnClickedCalc();
//	double m_InnerD;
//	CEdit m_Length;
//	CEdit m_LineD;
	double m_Height;
	double m_InsideDiameter;
	double m_OutsideDiameter;
	double m_WireDiameter;
	afx_msg void OnStnClickedResult();
	double m_PaintDiameter;
};
