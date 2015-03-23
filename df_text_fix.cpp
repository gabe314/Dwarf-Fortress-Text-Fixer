// Copyright (c) 2015 Gabriel De Repentigny
// Licensed to you under the MIT license. See LICENSE file for details.

/*
Program summary:
1) Find the Dwarf Fortress window
2) Tell the Dwarf Fortress window that it needs to redraw itself
3) Wait a little while
4) Go to step #1
*/

#include <stdio.h>
#include <windows.h>

// How long to wait between iterations of the main loop
// (in milliseconds)
#define SLEEP_TIME 40

int main()
{
    // Has the main loop been run at least once before?
    BOOL bStarted   = FALSE;
    // Have we found the Dwarf Fortress window?
    BOOL bConnected = FALSE;

    printf("-=Dwarf Fortress Text Fixer=-\n");
    printf("(Press Ctrl+C at anytime to exit)\n\n");

    // Main loop
    while (TRUE) {
        HWND hWndDF = FindWindow("SDL_app", "Dwarf Fortress");
        if (hWndDF) {
            // We found the Dwarf Fortress window
            // If we did not find it last time we looped, output a 
            // message to the user so they know the process's state has changed
            if (!bConnected) {
                printf("Connected to Dwarf Fortress\n");
                bConnected = TRUE; // Make note that we have now found DF
            }

            // The magic, tell the window that it needs to be redrawn
            InvalidateRect(hWndDF, NULL, TRUE);
        }
        else {
            // We did not find the Dwarf Fortress window
            // No worries: we'll look for it again in a few milliseconds
            // Print out an relevant error message based on the process's state
            if (!bStarted) {
                // We've just started the process
                printf("Dwarf Fortress process not found. " \
                       "Waiting for you to start it...\n");
            }
            else if (bConnected) {
                // We were previously connected to DF, but DF shut down
                printf("Disconnected from Dwarf Fortress. " \
                       "Waiting for you to restart it...\n");
                bConnected = FALSE;
            }
        }

        // Wait a little while before repeating
        Sleep(SLEEP_TIME);

        // Make note that we've completed the main loop at least once
        bStarted = TRUE;
    }
}
