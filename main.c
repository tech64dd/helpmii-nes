#include <stdlib.h>
#include <conio.h>
#include <joystick.h>

int drawbox(int x, int y) {
    int xtemp;
    int ytemp;
    if (x < 2 || y < 2) {
        cprintf("values cannot be less than 2");
        return 1;
    }
    xtemp = x - 2;
    cprintf("%c", 0x14);
    while (xtemp > 0) {
        cprintf("%c", 0x0B);
        xtemp = xtemp - 1;
    }
    xtemp = x - 2;
    cprintf("%c", 0x12);
    cprintf("\n");
    ytemp = y - 2;
    while (ytemp > 0) {
        gotox(wherex() - x);
        cprintf("%c", 0x0E);
        gotox(wherex() + xtemp);
        cprintf("%c", 0x0E);
        cprintf("\n");
        ytemp = ytemp -1;
    }
    gotox(wherex() - x);
    cprintf("%c", 0x11);
    while (xtemp > 0) {
        cprintf("%c", 0x0B);
        xtemp = xtemp - 1;
    }
    xtemp = x - 2;
    cprintf("%c", 0x08);
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
    cprintf("help ii         m\n\r");
    while (screenxtemp > 0) {
        cprintf("%c", 0x0B);
        screenxtemp = screenxtemp - 1;
    }
    gotoy(4);
    drawbox(20, 10);
    gotoxy(17, 10);
    drawbox(5, 5);

    joy_install(joy_static_stddrv);
    while(!joy_read(JOY_1));
    joy_uninstall();
    return EXIT_SUCCESS;
}
