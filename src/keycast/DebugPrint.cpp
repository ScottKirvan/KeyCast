#include < Windows.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>

// This function redirects the C/C++ standard input, output and error
void RedirectIOToConsole()
{
    if (AttachConsole(ATTACH_PARENT_PROCESS) == false)
        return;

    HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    int SystemOutput = _open_osfhandle(intptr_t(ConsoleOutput), _O_TEXT);

    // check if output is a console and not redirected to a file
    if (_isatty(SystemOutput) == false)
        return; // return if it's not a TTY

    FILE *COutputHandle = _fdopen(SystemOutput, "w");

    // Get STDERR handle
    HANDLE ConsoleError = GetStdHandle(STD_ERROR_HANDLE);
    int SystemError = _open_osfhandle(intptr_t(ConsoleError), _O_TEXT);
    FILE *CErrorHandle = _fdopen(SystemError, "w");

    // Get STDIN handle
    HANDLE ConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    int SystemInput = _open_osfhandle(intptr_t(ConsoleInput), _O_TEXT);
    FILE *CInputHandle = _fdopen(SystemInput, "r");

    // make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog point to console as well
    // ios::sync_with_stdio(true);
    std::ios_base::sync_with_stdio(true);

    // Redirect the CRT standard input, output, and error handles to the console
    freopen_s(&CInputHandle, "CONIN$", "r", stdin);
    freopen_s(&COutputHandle, "CONOUT$", "w", stdout);
    freopen_s(&CErrorHandle, "CONOUT$", "w", stderr);

    // Clear the error state for each of the C++ standard stream objects.
    std::wcout.clear();
    std::cout.clear();
    std::wcerr.clear();
    std::cerr.clear();
    std::wcin.clear();
    std::cin.clear();
}

static BOOL firstCallToDebugPrint = TRUE;

void _DebugPrint(const char *file, int line, const char *format, ...)
{
    if (firstCallToDebugPrint)
    {
        firstCallToDebugPrint = FALSE;
        printf("\n");
    }
    printf("%s(%d): ", file, line);
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
}
