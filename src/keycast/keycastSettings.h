#ifndef _KEYCASTSETTINGS_H
#define _KEYCASTSETTINGS_H

struct LabelSettings
{
    DWORD keyStrokeDelay;
    DWORD lingerTime;
    DWORD fadeDuration;
    LOGFONT font;
    COLORREF bgColor, textColor, borderColor;
    DWORD bgOpacity, textOpacity, borderOpacity;
    int borderSize;
    int cornerSize;
};

#endif // _KEYCASTSETTINGS_H