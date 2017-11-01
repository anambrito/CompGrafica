/*
	Copyright 2017 Fadoa Glauss Vieira

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation
	files, to deal in the Software without restriction, including without limitation the rights to use, copy,
	modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
	is furnished to do so, subject to the following conditions:
	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
	IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*	Caso haja mais dúvidas, dê uma olhada nesse site: http://www.inf.pucrs.br/~manssour/OpenGL/Programando3D.html */

#include "desenhar.h"
#include "globals.h"
#include "glm.h"

//carregando os obj
void inicializaObj(){
   
	mesa = glmReadOBJ("obj/mesa.obj");
	mesaList = glmList(mesa, GLM_SMOOTH);
	
    cama = glmReadOBJ("obj/cama.obj");
	camaList = glmList(cama, GLM_SMOOTH);

	caneca = glmReadOBJ("obj/Krujka-Me.obj"); //caneca
	canecaList = glmList(caneca, GLM_SMOOTH);

	carro= glmReadOBJ("obj/Car.obj");
	carroList = glmList(carro, GLM_SMOOTH);

}

void desenhaMesa(){ 
	glPushMatrix();
		glColor3f(0.3, 0.3, 0.9);
		glTranslatef(-23,-47,55);
		glScalef(25,28,15);
		glCallList(mesaList);
	glPopMatrix();
}

void desenhaCama(){ 
	glPushMatrix();
		glTranslatef(25,-51,55);
		glScalef(25,25,25);
		glCallList(camaList);
	glPopMatrix();
}

void desenhaCaneca(){ 
	glPushMatrix();
		glTranslatef(-23,-21,55);
		glScalef(50,50,50);
		glCallList(canecaList);
	glPopMatrix();
}

void desenhaCarro(){ 
	glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(+300,-50,55);
		glScalef(50,50,50);
		glCallList(carroList);
	glPopMatrix();
}

void display(void){


	GLfloat lightDif[4] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat lightSpec[4] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lightPos[4] = { 0.0, 50.0, 50.0, 1.0 };


	// Define os parâmetros da luz de número 0.
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(camera.eyeX, camera.eyeY, camera.eyeZ-100,
              camera.eyeX, camera.eyeY, camera.eyeZ,
              0, 1, 0);
	glPushMatrix();
		glRotatef(camera.xAngle, 1.0, 0.0, 0.0); //Rotação no eixo x.
        glRotatef(camera.yAngle, 0.0, 1.0, 0.0); //Rotação no eixo y.
        glRotatef(camera.zAngle, 0.0, 0.0, 1.0); //Rotação no eixo z.

		desenhaPlano(3000, -250, 3000, txSolo); //x,y,z
		desenhaSkyBox(3000);

		glPushMatrix();
		glScalef(5,5,5); //aumenta o tamanho
			
			desenhaTelhado();	
			desenhaPorta(0.1);
			desenhaPorta(-0.1);
			desenhaCaneca();
			desenhaCama();
			desenhaCarro();
			desenhaMesa();
			desenhaPorta(-0.1);	
			desenhaCubo(50, txParede);
			desenhaPiramide(30);
		glPopMatrix();

	glPopMatrix();
	//Executa os comandos OpenGL.
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 27:
			exit(0);
		//Movimenta o personagem.
		case 'a': camera.eyeX = camera.eyeX+10;
			break;
		case 'd': camera.eyeX = camera.eyeX-10;
			break;
		case 's': camera.eyeZ = camera.eyeZ-10;
			break;
		case 'w': camera.eyeZ= camera.eyeZ+10;
			break;
		case 'q': camera.eyeY = camera.eyeY-10;
			break;
		case 'e': camera.eyeY = camera.eyeY+10;
			break;
		//Rotaciona a camêra em y.
		case 'Y':
			camera.yAngle++;
			if(camera.yAngle > 360.0) camera.yAngle-=360;
			break;
		case 'y':
			camera.yAngle--;
			if(camera.yAngle < 0.0) camera.yAngle+=360;
			break;
		//Rotaciona a camêra em x.
		case 'X':
			camera.xAngle++;
			if(camera.xAngle > 360.0) camera.xAngle-=360;
			break;
		case 'x':
			camera.xAngle--;
			if(camera.xAngle < 0.0) camera.xAngle+=360;
			break;
		//Rotaciona a camêra em z.
		case 'Z':
			camera.zAngle++;
			if(camera.zAngle > 360.0) camera.zAngle-=360;
			break;
		case 'z':
			camera.zAngle--;
			if(camera.zAngle < 0.0) camera.zAngle+=360;
			break;
	}
	glutPostRedisplay();
}

void setup(void){
	// Capacidade de brilho do material
	GLfloat spec[4]={ 0, 0, 0, 1.0};
	GLint specMaterial = 60;
	//Inicializa obj
	inicializaObj();
	//Define a refletência do material.
	glMaterialfv(GL_FRONT,GL_SPECULAR, spec);
	// Define a concentração do brilho.
	glMateriali(GL_FRONT,GL_SHININESS, specMaterial);
	//Ativa o uso da luz ambiente.
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb);
	//Especifica a cor de fundo da janela.
	glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
	//Habilita o modelo de colorização de Gouraud.
	glShadeModel(GL_SMOOTH);
	//Habilita o depth-buffering.
	glEnable(GL_DEPTH_TEST);
	//Habilita a definição da cor do material a partir da cor corrente.
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação.
	glEnable(GL_LIGHTING);
    //Desabilita a visualização das faces internas.
//glCullFace(GL_BACK);

glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);
    //Desabilitar o ponteiro do mouse dentro da janela.
    //glutSetCursor(GLUT_CURSOR_NONE);

    //Define a posição inicial do olho.
    camera.eyeX = 0.0;
    camera.eyeY = 0.0;
    camera.eyeZ = -500.0;
    camera.xAngle = 0.0;
    camera.yAngle = 0.0;
    camera.zAngle = 0.0;
}

//Callback de redimensionamento.
void reshape(int w, int h){
	if ( h == 0 ) h = 1;
	w_window = w;
	h_window = h;

	glViewport(0, 0 , w, h);
	glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    /* 	void gluPerspective(GLdouble fovy,		//Especifica o ângulo de visão na direção de y, em graus.
	 						GLdouble aspect,	//Especifica a relação de entre largura e altura que determina o campo de visão na direção x.
	 						GLdouble zNear,		//Especifica a distância da câmera para o plano mais próximo de visão.
	 						GLdouble zFar);		//Especifica a distância da câmera para o plano mais longe de visão.
    */
    gluPerspective(60.0, (float)w/(float)h, 1.0, 20000.0);
    glMatrixMode(GL_MODELVIEW);
}

void inputs(void){
	printf("\n\t\tAjuda:");
	printf("\n\tAperte x/X para rotacionar (aumentar/diminuir) o angulo em x.");
	printf("\n\tAperte y/Y para rotacionar (aumentar/diminuir) o angulo em y.");
	printf("\n\tAperte z/Z para rotacionar (aumentar/diminuir) o angulo em z.");
	printf("\n\tAperte a/w/s/d para aumentar/diminuir as posições nos eixos x e z.");
	printf("\n\tAperte q/e para aumentar/diminuir a posição no eixo y.\n\n");
}

int main(int argc, char *argv[]){
	//Inicializa o GLUT e define a versão do OpenGL.

	glutInit(&argc, argv);
	glutInitContextVersion(1, 1);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	//Configuração inicial da janela.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(w_window, h_window);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Casa");

	glutDisplayFunc(display);
	inicializarTexturas();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	inputs();
	//Define as configurações iniciais do OpenGL.

	setup();
	glutMainLoop();
}
