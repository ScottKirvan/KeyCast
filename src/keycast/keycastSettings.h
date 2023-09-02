#ifndef _KEYCASTSETTINGS_H
#define _KEYCASTSETTINGS_H

#include <windows.h>

struct LabelSettings
{
    DWORD keyStrokeDelay;
    DWORD lingerTime;
    DWORD fadeDuration;
    LOGFONT textFont;
    COLORREF bgColor, textColor, borderColor;
    DWORD bgOpacity, textOpacity, borderOpacity;
    int borderSize;
    int cornerSize;
};

#endif // _KEYCASTSETTINGS_H