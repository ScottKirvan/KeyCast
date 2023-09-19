#include "keycastSettings.h"
#include "keycast.h"
#include <stdio.h>

LabelSettings labelSettings, previewLabelSettings;
WCHAR iniFile[MAX_PATH];
DWORD maximumLines = 10;
DWORD labelCount = 0;
POINT deskOrigin;
RECT desktopRect;
int alignment = 0;           // 0: left, 1: right -- todo add center
UINT tcModifiers = MOD_ALT;  // Toggle Capture - Alt
UINT tcKey = 0x42;           // 0x42 is 'b'  // Toggle Capture - b
WCHAR branding[BRANDINGMAX]; // Branding

void writeSettingInt(LPCTSTR lpSection, LPCTSTR lpKey, DWORD dwValue)
{
    WCHAR tmp[256];
    swprintf(tmp, 256, L"%d", dwValue);
    WritePrivateProfileString(L"KeyCast", lpKey, tmp, iniFile);
}

void saveSettings()
{
    // DebugPrint("void saveSettings()\n");
    WritePrivateProfileStruct(L"KeyCast", L"textFont", (LPVOID)&labelSettings.textFont, sizeof(labelSettings.textFont), iniFile);
    writeSettingInt(L"KeyCast", L"textColor", labelSettings.textColor);
    writeSettingInt(L"KeyCast", L"textOpacity", labelSettings.textOpacity);

    writeSettingInt(L"KeyCast", L"borderSize", labelSettings.borderSize);
    writeSettingInt(L"KeyCast", L"borderColor", labelSettings.borderColor);
    writeSettingInt(L"KeyCast", L"borderOpacity", labelSettings.borderOpacity);

    writeSettingInt(L"KeyCast", L"bgColor", labelSettings.bgColor);
    writeSettingInt(L"KeyCast", L"bgOpacity", labelSettings.bgOpacity);

    writeSettingInt(L"KeyCast", L"borderRadius", labelSettings.borderRadius);

    writeSettingInt(L"KeyCast", L"keyStrokeDelay", labelSettings.keyStrokeDelay);
    writeSettingInt(L"KeyCast", L"lingerTime", labelSettings.lingerTime);
    writeSettingInt(L"KeyCast", L"fadeDuration", labelSettings.fadeDuration);
    writeSettingInt(L"KeyCast", L"maximumLines", maximumLines);

    writeSettingInt(L"KeyCast", L"alignment", alignment);
    writeSettingInt(L"KeyCast", L"windowHeight", deskOrigin.x);
    writeSettingInt(L"KeyCast", L"windowWidth", deskOrigin.y);

    writeSettingInt(L"KeyCast", L"tcModifiers", tcModifiers);
    writeSettingInt(L"KeyCast", L"tcKey", tcKey);
    WritePrivateProfileString(L"KeyCast", L"branding", branding, iniFile);
}

void loadSettings(HWND hMainWnd)
{
    // DebugPrint("void loadSettings()\n");
    labelSettings.keyStrokeDelay = GetPrivateProfileInt(L"KeyCast", L"keyStrokeDelay", 500, iniFile);
    labelSettings.lingerTime = GetPrivateProfileInt(L"KeyCast", L"lingerTime", 3600, iniFile);
    labelSettings.fadeDuration = GetPrivateProfileInt(L"KeyCast", L"fadeDuration", 200, iniFile);
    labelSettings.bgColor = GetPrivateProfileInt(L"KeyCast", L"bgColor", RGB(75, 75, 75), iniFile);
    labelSettings.textColor = GetPrivateProfileInt(L"KeyCast", L"textColor", RGB(255, 255, 255), iniFile);
    labelSettings.bgOpacity = GetPrivateProfileInt(L"KeyCast", L"bgOpacity", 0, iniFile);
    labelSettings.textOpacity = GetPrivateProfileInt(L"KeyCast", L"textOpacity", 255, iniFile);
    labelSettings.borderOpacity = GetPrivateProfileInt(L"KeyCast", L"borderOpacity", 0, iniFile);
    labelSettings.borderColor = GetPrivateProfileInt(L"KeyCast", L"borderColor", RGB(0, 128, 255), iniFile);
    // DebugPrint("borderSize = %d\n", labelSettings.borderSize);
    labelSettings.borderSize = GetPrivateProfileInt(L"KeyCast", L"borderSize", 0, iniFile);
    // DebugPrint("borderSize = %d\n", labelSettings.borderSize);
    labelSettings.borderRadius = GetPrivateProfileInt(L"KeyCast", L"borderRadius", 0, iniFile);
    // labelSpacing = GetPrivateProfileInt(L"KeyCast", L"labelSpacing", 1, iniFile);
    maximumLines = GetPrivateProfileInt(L"KeyCast", L"maximumLines", 10, iniFile);
    if (maximumLines == 0)
    {
        maximumLines = 1;
    }
    deskOrigin.x = GetPrivateProfileInt(L"KeyCast", L"windowHeight", 2, iniFile);
    deskOrigin.y = GetPrivateProfileInt(L"KeyCast", L"windowWidth", 2, iniFile);
    MONITORINFO mi;
    GetWorkAreaByOrigin(deskOrigin, mi);
    CopyMemory(&desktopRect, &mi.rcWork, sizeof(RECT));
    MoveWindow(hMainWnd, desktopRect.left, desktopRect.top, 1, 1, TRUE);
    fixDeskOrigin();
    alignment = GetPrivateProfileInt(L"KeyCast", L"alignment", 0, iniFile);
    SetWindowLong(hMainWnd, GWL_EXSTYLE, GetWindowLong(hMainWnd, GWL_EXSTYLE) | WS_EX_TRANSPARENT);
    tcModifiers = GetPrivateProfileInt(L"KeyCast", L"tcModifiers", MOD_ALT, iniFile);
    tcKey = GetPrivateProfileInt(L"KeyCast", L"tcKey", 0x42, iniFile);
    GetPrivateProfileString(L"KeyCast", L"branding", L"Exit", branding, BRANDINGMAX, iniFile);
    memset(&labelSettings.textFont, 0, sizeof(labelSettings.textFont));
    labelSettings.textFont.lfCharSet = DEFAULT_CHARSET;
    labelSettings.textFont.lfHeight = -16;
    labelSettings.textFont.lfPitchAndFamily = DEFAULT_PITCH;
    labelSettings.textFont.lfWeight = FW_REGULAR;
    labelSettings.textFont.lfOutPrecision = OUT_DEFAULT_PRECIS;
    labelSettings.textFont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    labelSettings.textFont.lfQuality = ANTIALIASED_QUALITY;
    wcscpy_s(labelSettings.textFont.lfFaceName, LF_FACESIZE, TEXT("Tahoma"));
    GetPrivateProfileStruct(L"KeyCast", L"textFont", &labelSettings.textFont, sizeof(labelSettings.textFont), iniFile);
}