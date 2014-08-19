
// coilDlg.h : 头文件
//

#pragma once


// CcoilDlg 对话框
class CcoilDlg : public CDialogEx
{
// 构造
public:
	CcoilDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_COIL_DIALOG };

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
