import pygame as pg


def main():
    pg.init()
    screen = pg.display.set_mode((640, 480))
    clock = pg.time.Clock()
    button = pg.Rect(100, 100, 50, 50)
    done = False

    while not done:
        for event in pg.event.get():
            if event.type == pg.QUIT:
                done = True

        screen.fill((255, 255, 255))
        button.clamp_ip(screen.get_rect())
        pg.display.flip()
        clock.tick(60)
    pg.quit()


main()
