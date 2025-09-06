#include <stdlib.h>
#include <conio.h>
#include <joystick.h>

int drawbox(int x, int y) {
    int xtemp;
    int ytemp;
    revers(1);
    if (x < 2 || y < 3) {
        return 1;
    }
    xtemp = x - 2;
    cprintf("%c", 0x14);
    while (xtemp > 0) {
        cprintf("%c", 0x0B);
        xtemp = xtemp - 1;
    }
    cprintf("%c", 0x12);
    cprintf("\n");
    ytemp = y - 2;
    while (ytemp > 0) {
        gotox(wherex() - x);
        xtemp = x - 2;
        if (ytemp == 2) {
            cprintf("%c", 0x0F);
            while (xtemp > 0) {
                cprintf("%c", 0x0B);
                xtemp = xtemp - 1;
            }
        }
        else {
            cprintf("%c", 0x0E);
        }
        while (xtemp > 0) {
            cprintf(" ");
            xtemp = xtemp - 1;
        }
        if (ytemp == 2) {
            cprintf("%c", 0x17);
        }
        else {
            cprintf("%c", 0x0E);
        }
        cprintf("\n");
        ytemp = ytemp - 1;
    }
    xtemp = x - 2;
    gotox(wherex() - x);
    cprintf("%c", 0x11);
    while (xtemp > 0) {
        cprintf("%c", 0x0B);
        xtemp = xtemp - 1;
    }
    cprintf("%c", 0x08);
    revers(0);
    return 0;
}

int main() {
    int screenx;
    int screeny;
    int screenxtemp;
    screensize(&screenx, &screeny);
    screenxtemp = screenx;
    clrscr();
    bgcolor(COLOR_BLUE);
    cprintf("HelpMii Support Program\n\r");
    while (screenxtemp > 0) {
        cprintf("%c", 0x0B);
        screenxtemp = screenxtemp - 1;
    }
    gotoxy(6, 4);
    drawbox(18, 14);
    //gotoxy(17, 10);
    //drawbox(5, 5);

    joy_install(joy_static_stddrv);
    while(!joy_read(JOY_1));
    joy_uninstall();
    return EXIT_SUCCESS;
}
