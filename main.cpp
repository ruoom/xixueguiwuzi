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
        if (IDYES == MessageBox(hWnd, L"out?", L"退出", MB_YESNO))
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
    wcx.cbClsExtra = 0;//int cbClsExtra 给类而外预留的空间默认设为0 当你需要的时候自然会明白它的用处。  
    wcx.cbWndExtra = 0;//int cbWndExtra 同上  
    wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcx.hCursor = NULL;//HCURSOR hCursor  该窗口光标形式的句柄 
    wcx.hIcon = NULL;//HICON hIcon  该窗口的图标的句柄 
    wcx.hIconSm = NULL;//HICON hIconSm这个图标显示的是窗口在任务栏处显示的图标。 
    wcx.hInstance = g_hInstace;//HINSTANCE hInstance    该窗口的句柄 

    //WNDPROC lpfnWndProc 这个应该是该结构中最重要的一个成员，类型WNDPROC的实质是一个指向函数的长整类型的指针。   
    //也就是说我们定义一个窗口，当鼠标在该窗口上操作，或键盘按键时，该窗口收到了这个消息。此时他的lpfnWndProc指向一个回调函数， 
    //（回调函数见下方讲解）该窗口将参数送到回调函数，由回调函数执行动作，之后则可以对动作作出相应。 
    wcx.lpfnWndProc = WndProc;

    wcx.lpszClassName = lpszClassName;//LPCTSTR lpszClassName该类的名字。即给该类起一个名字。 
    wcx.lpszMenuName = NULL;
    wcx.style = CS_HREDRAW | CS_VREDRAW;//定义窗口的风格，style 虽然是一个无符号整数，但是他的取值，是系统定义好的一组宏变量 
    ATOM nAtom = RegisterClassEx(&wcx);//该函数注册在随后调用CreateWindow函数和CreateWindowEx函数中使用的窗口类。 
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
    if (!RegisterWnd(TEXT("吸血鬼物资"), WindowProc))
    {
        MessageBox(NULL, TEXT("创建窗口失败"), TEXT("Warning"), MB_YESNOCANCEL);
        return -1;
    }
    HWND hWnd = CreateWnd(TEXT("吸血鬼物资"), TEXT("吸血鬼物资"));
    DisplayWnd(hWnd);
    gameInit();
    Message();

    return 0;
}
