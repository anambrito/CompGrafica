#include "callbacksGerais.h"
#include "draw.h"

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
	init();
	Mix_PlayMusic(musica, 1);

    glutCreateWindow("STAR WARS: Torpedo Hunt .io");

   
    glutDisplayFunc(desenhaCena);
	Textura();   
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutTimerFunc(0, atualiza, 0);
    inicializa();

    glutMainLoop();
    return 0;
}
