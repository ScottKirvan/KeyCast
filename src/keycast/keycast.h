// Copyright © 2014 Brook Hong. All Rights Reserved.
//

#ifndef _KEYCAST_H
#define _KEYCAST_H

void GetWorkAreaByOrigin(const POINT &pt, MONITORINFO &mi);
void fixDeskOrigin();
void showText(LPCWSTR text, int behavior);
void fadeLastLabel(BOOL whether);
void positionOrigin(int action, POINT &pt);

#endif // _KEYCAST_H
