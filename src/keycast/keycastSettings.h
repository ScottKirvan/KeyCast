#ifndef _KEYCASTSETTINGS_H
#define _KEYCASTSETTINGS_H

#include <windows.h>

#define BRANDINGMAX 256

struct LabelSettings
{
    DWORD keyStrokeDelay;
    DWORD lingerTime;
    DWORD fadeDuration;
    LOGFONT textFont;
    COLORREF bgColor, textColor, borderColor;
    DWORD bgOpacity, textOpacity, borderOpacity;
    int borderSize;
    int borderRadius;
};

extern WCHAR iniFile[MAX_PATH];
extern WCHAR branding[BRANDINGMAX]; // Branding
extern LabelSettings labelSettings, previewLabelSettings;
extern DWORD maximumLines;
extern DWORD labelCount;
extern POINT deskOrigin;
extern RECT desktopRect;
extern int alignment;
extern UINT tcModifiers; // Toggle Capture - Alt
extern UINT tcKey;       // 0x42 is 'b'  // Toggle Capture - b

void loadSettings(HWND hMainWnd);
void saveSettings();

#endif // _KEYCASTSETTINGS_H