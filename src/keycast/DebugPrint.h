
#ifndef _DEBUG_PRINT_H_
#define _DEBUG_PRINT_H_

#define DebugPrint(format, ...) _DebugPrint(__FILE__, __LINE__, format, __VA_ARGS__)

void RedirectIOToConsole();
void _DebugPrint(const char *file, int line, const char *format, ...);

#endif // _DEBUG_PRINT_H_