/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <etienne.doms@gmail.com> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return. Etienne Doms
 * ----------------------------------------------------------------------------
 */

#include "MainDlg.h"
#include "MainDlgSelect.h"
#include "MainDlgRefresh.h"
#include "MainDlgWrite.h"
#include "resource.h"

static INT_PTR CALLBACK MainDlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);

    switch (uMsg) {
    case WM_INITDIALOG:
        SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM) LoadIcon((HINSTANCE) lParam, MAKEINTRESOURCE(IDI_APP_ICON)));
        MainDlgRefreshClick(hwndDlg);
        return TRUE;

    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDC_MAINDLG_SELECT:
            switch (HIWORD(wParam)) {
            case BN_CLICKED:
                return MainDlgSelectClick(hwndDlg);

            default:
                return FALSE;
            }

        case IDC_MAINDLG_REFRESH:
            switch (HIWORD(wParam)) {
            case BN_CLICKED:
                return MainDlgRefreshClick(hwndDlg);

            default:
                return FALSE;
            }

        case IDC_MAINDLG_WRITE:
            switch (HIWORD(wParam)) {
            case BN_CLICKED:
                return MainDlgWriteClick(hwndDlg);

            default:
                return FALSE;
            }

        default:
            return FALSE;
        }

    default:
        return FALSE;
    }
}

INT_PTR MainDlg(HINSTANCE hInstance) {
    return DialogBoxParam(hInstance, MAKEINTRESOURCE(IDC_MAINDLG), NULL, MainDlgProc, (LPARAM) hInstance);
}
