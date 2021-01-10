#include "gameElement.h"
#include <iostream>

#include <windows.h>


HINSTANCE g_hInstace = 0;
LRESULT CALLBACK WindowProc(
    HWND hWnd,
    UINT nMsg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (nMsg)
    {
    case WM_CHAR:
        break;
    case WM_CLOSE:
        /*
        if (IDYES == MessageBox(hWnd, L"out?", L"�˳�", MB_YESNO))
        {
            DestroyWindow(hWnd);
        }
        */
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, nMsg, wParam, lParam);
    }
}

BOOL RegisterWnd(LPCWSTR lpszClassName, WNDPROC WndProc)
{
    WNDCLASSEX wcx = { 0 };
    wcx.cbSize = sizeof(WNDCLASSEX);
    wcx.cbClsExtra = 0;//int cbClsExtra �������Ԥ���Ŀռ�Ĭ����Ϊ0 ������Ҫ��ʱ����Ȼ�����������ô���  
    wcx.cbWndExtra = 0;//int cbWndExtra ͬ��  
    wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcx.hCursor = NULL;//HCURSOR hCursor  �ô��ڹ����ʽ�ľ�� 
    wcx.hIcon = NULL;//HICON hIcon  �ô��ڵ�ͼ��ľ�� 
    wcx.hIconSm = NULL;//HICON hIconSm���ͼ����ʾ���Ǵ���������������ʾ��ͼ�ꡣ 
    wcx.hInstance = g_hInstace;//HINSTANCE hInstance    �ô��ڵľ�� 

    //WNDPROC lpfnWndProc ���Ӧ���Ǹýṹ������Ҫ��һ����Ա������WNDPROC��ʵ����һ��ָ�����ĳ������͵�ָ�롣   
    //Ҳ����˵���Ƕ���һ�����ڣ�������ڸô����ϲ���������̰���ʱ���ô����յ��������Ϣ����ʱ����lpfnWndProcָ��һ���ص������� 
    //���ص��������·����⣩�ô��ڽ������͵��ص��������ɻص�����ִ�ж�����֮������ԶԶ���������Ӧ�� 
    wcx.lpfnWndProc = WndProc;

    wcx.lpszClassName = lpszClassName;//LPCTSTR lpszClassName��������֡�����������һ�����֡� 
    wcx.lpszMenuName = NULL;
    wcx.style = CS_HREDRAW | CS_VREDRAW;//���崰�ڵķ��style ��Ȼ��һ���޷�����������������ȡֵ����ϵͳ����õ�һ������ 
    ATOM nAtom = RegisterClassEx(&wcx);//�ú���ע����������CreateWindow������CreateWindowEx������ʹ�õĴ����ࡣ 
    if (0 == nAtom)
        return FALSE;
    return TRUE;

}

HWND CreateWnd(LPCWSTR lpszClassName, LPCWSTR lpszWindowsName)
{
    HWND hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
        lpszClassName,
        lpszWindowsName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        g_hInstace,
        NULL);
    return hWnd;
}

void DisplayWnd(HWND hWnd)
{
    ShowWindow(hWnd, SW_NORMAL);
    UpdateWindow(hWnd);
}

WPARAM Message()
{
    MSG nMsg;
    while (GetMessage(&nMsg, NULL, 0, 0))
    {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg);   
    }
    return nMsg.wParam;
}
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nCmdShow)
{
    if (!RegisterWnd(TEXT("��Ѫ������"), WindowProc))
    {
        MessageBox(NULL, TEXT("��������ʧ��"), TEXT("Warning"), MB_YESNOCANCEL);
        return -1;
    }
    HWND hWnd = CreateWnd(TEXT("��Ѫ������"), TEXT("��Ѫ������"));
    DisplayWnd(hWnd);
    gameInit();
    Message();

    return 0;
}
