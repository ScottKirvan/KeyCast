// Copyright © 2014 Brook Hong. All Rights Reserved.
//

#ifndef _KEYCAST_H
#define _KEYCAST_H

#include <gdiplus.h>
using namespace Gdiplus;

extern Color clearColor;
extern Font *fontPlus;
extern BOOL positioning;
extern WCHAR deferredLabel[64];

void GetWorkAreaByOrigin(const POINT &pt, MONITORINFO &mi);
void fixDeskOrigin();
void showText(LPCWSTR text, int behavior);
void fadeLastLabel(BOOL whether);
void positionOrigin(int action, POINT &pt);

#endif // _KEYCAST_H
