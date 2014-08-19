
// coilDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "coil.h"
#include "coilDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CcoilDlg 对话框




CcoilDlg::CcoilDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcoilDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  m_InnerD = 0.0;
	m_Height = 49.4;
	m_InsideDiameter = 12;
	m_OutsideDiameter = 41;
	m_WireDiameter = 0.14;
	m_PaintDiameter = 0.17;
}

void CcoilDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_INNER_D, m_InnerD);
	//  DDX_Control(pDX, IDC_EDIT_LENGTH, m_Length);
	//  DDX_Control(pDX, IDC_EDIT_LINE_D, m_LineD);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_Height);
	DDV_MinMaxDouble(pDX, m_Height, 1, 1000);
	DDX_Text(pDX, IDC_EDIT_INSIDE_DIAMETER, m_InsideDiameter);
	DDV_MinMaxDouble(pDX, m_InsideDiameter, 1, 1000);
	DDX_Text(pDX, IDC_EDIT_OUTSIDE_DIAMETER, m_OutsideDiameter);
	DDV_MinMaxDouble(pDX, m_OutsideDiameter, 2, 1000);
	DDX_Text(pDX, IDC_EDIT_WIRE_DIAMETER, m_WireDiameter);
	DDV_MinMaxDouble(pDX, m_WireDiameter, 0.01, 10);
	DDX_Text(pDX, IDC_EDIT_PAINT_DIAMETER, m_PaintDiameter);
	DDV_MinMaxDouble(pDX, m_PaintDiameter, 0.02, 10);
}

BEGIN_MESSAGE_MAP(CcoilDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALC, &CcoilDlg::OnBnClickedCalc)
	ON_STN_CLICKED(IDC_RESULT, &CcoilDlg::OnStnClickedResult)
END_MESSAGE_MAP()


// CcoilDlg 消息处理程序

BOOL CcoilDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcoilDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcoilDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcoilDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcoilDlg::OnBnClickedCalc()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	//假设漆皮厚度为0.025,绕线系数为0.875

	double turns=( m_OutsideDiameter/2 - m_InsideDiameter/2 ) * m_Height / ( m_PaintDiameter/2 * m_PaintDiameter/2 * 3.1415926) * 0.85;
	double total_len=turns * ( m_OutsideDiameter/2 + m_InsideDiameter/2) * 3.1415926;
	double resister= total_len * 1.75e-5 / (3.1415926 * m_WireDiameter * m_WireDiameter / 4);

	CString str;
	str.Format(_T("总匝数: %.1f\n电阻: %.1f"), turns,resister);

	this->GetDlgItem(IDC_RESULT)->SetWindowTextW(str);
}


void CcoilDlg::OnStnClickedResult()
{
	// TODO: 在此添加控件通知处理程序代码
}
