
// coilDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "coil.h"
#include "coilDlg.h"
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


// CcoilDlg �Ի���




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


// CcoilDlg ��Ϣ�������

BOOL CcoilDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcoilDlg::OnPaint()
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
HCURSOR CcoilDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcoilDlg::OnBnClickedCalc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	//������Ƥ���Ϊ0.025,����ϵ��Ϊ0.875

	double turns=( m_OutsideDiameter/2 - m_InsideDiameter/2 ) * m_Height / ( m_PaintDiameter/2 * m_PaintDiameter/2 * 3.1415926) * 0.85;
	double total_len=turns * ( m_OutsideDiameter/2 + m_InsideDiameter/2) * 3.1415926;
	double resister= total_len * 1.75e-5 / (3.1415926 * m_WireDiameter * m_WireDiameter / 4);

	CString str;
	str.Format(_T("������: %.1f\n����: %.1f"), turns,resister);

	this->GetDlgItem(IDC_RESULT)->SetWindowTextW(str);
}


void CcoilDlg::OnStnClickedResult()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
