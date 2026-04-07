#include <graphics.h>
#include <stdio.h>
#include <math.h>
void drawLineDDA(int x1, int y1, int x2, int y2) {
    float dx, dy, steps, x_inc, y_inc, x, y;
    int i;
    dx = x2 - x1;
    dy = y2 - y1;
    if (fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }
    x_inc = dx / steps;
    y_inc = dy / steps;
    x = x1;
    y = y1;
    putpixel(round(x), round(y), WHITE);
    for (i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
    }
}
int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    printf("Prepared by: Abin Rajkarnikar\n");
    printf("Roll No: 04/080(A)\n");
    printf("DDA Line Generation Algorithm (Graphical)\n");
    printf("Enter the coordinates of the first point (x1 y1): ");
    if (scanf("%d %d", &x1, &y1) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter the coordinates of the second point (x2 y2): ");
    if (scanf("%d %d", &x2, &y2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }
    initgraph(&gd, &gm, (char*)"C:\\MinGW\\lib\\libbgi.a");
    if (graphresult() != grOk) {
        printf("Graphics error: %s\n", grapherrormsg(graphresult()));
        printf("Please ensure 'graphics.h' and 'libbgi.a' are correctly set up.\n");
        return 1;
    }
    drawLineDDA(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}