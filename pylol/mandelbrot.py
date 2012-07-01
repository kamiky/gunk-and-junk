#!/usr/bin/python2
import sys,math,time
import pygame,pygame.gfxdraw

WIN_X = 800
WIN_Y = 800
X1 = -1.4 #-2.1
X2 = 0.6 #0.6
Y1 = -0.2 #-1.2
Y2 = 1.2 #1.2
ZOOM=3000
ITER = 70
RENDER_STEP=25

def check_events():
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit(0)

def put_pixel(window, x, y, c):
    pygame.gfxdraw.pixel(window, x, y, c)

def proceed_point(x, y):
    #center coordinates
    #tx = -(WIN_X/2-x)
    #ty = -(WIN_Y/2-y)
    a = (float(x) / ZOOM)+X1
    b = (float(y) / ZOOM)+Y1
    Xn = 0
    Xn_sq = 0
    Yn = 0
    Yn_sq = 0
    i = 0
    for i in range(ITER):
        Yn = 2*Xn*Yn+b
        Xn = Xn_sq-Yn_sq+a
        Yn_sq = Yn*Yn
        Xn_sq = Xn*Xn
        if Xn_sq+Yn_sq>4:
  #         return (0, i*255/ITER, 0)
            return (0, i*255/ITER, 0)
            #put_pixel(window,x,y,0,i*255/ITER,0)
            #put_pixel(window,x,y,i*255/ITER,i*255/ITER,i*255/ITER)
            #return
    #if Xn*Xn+Yn*Yn<4: #is in the set
    #put_pixel(window,x,y)
    return (255, 255, 255)

def draw(window):
    for y in range(0, WIN_Y, 2):
        if ((y % RENDER_STEP) == 0):
            pygame.display.flip()
            check_events()
        for x in range(0, WIN_X, 2):
            c = proceed_point(x, y)
            put_pixel(window, x,     y,     c)
            put_pixel(window, x + 1, y,     c)
            put_pixel(window, x,     y + 1, c)
            put_pixel(window, x + 1, y + 1, c)
    for y in xrange(0, WIN_Y, 2):
        if ((y % RENDER_STEP) == 0):
            pygame.display.flip()
            check_events()

        for x in range(0, WIN_X, 2):
            put_pixel(window, x + 1, y,     proceed_point(x + 1, y))
            put_pixel(window, x,     y + 1, proceed_point(x,     y + 1))
            put_pixel(window, x + 1, y + 1, proceed_point(x + 1, y + 1))

if __name__ == "__main__":    
    pygame.init()
    window = pygame.display.set_mode((WIN_X,WIN_Y))
    draw(window)
    pygame.display.flip()
    while True:
        check_events()
        time.sleep(0.5)
