#include "desenhar.h"

int carregaTextura(char* nome) {

	int idTextura = SOIL_load_OGL_texture(
        nome,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

    if (idTextura == 0) {
        printf("Erro do SOIL [%s]: '%s'\n", nome, SOIL_last_result());
    }

	return idTextura;
}

void inicializarTexturas(void){

	txSky = carregaTextura("skybox/sk.bmp");
	txSky3 = carregaTextura("skybox/sk3.bmp");
	txSky4 = carregaTextura("skybox/sk4.bmp");
	txSky5 = carregaTextura("skybox/sk5.bmp");
	txSky6 = carregaTextura("skybox/sk6.bmp");
	
	txSolo = carregaTextura("imagens/solo.png");
	txMadeira = carregaTextura("imagens/madeira.png");
	txTelhado = carregaTextura("imagens/telhado.png");
	txPorta = carregaTextura("imagens/porta.png");
	txChao = carregaTextura("imagens/cchao.png");
	txJanelaFora = carregaTextura("imagens/paredeFora.png");
	txParede = carregaTextura("imagens/tj.png");

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

}

void desenhaTelhado(){

	int coord=50;
	int alt = 10;
	glColor3f(1,1,1); //DEFINE A COR: BRANCA
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txMadeira);
		glBegin(GL_TRIANGLE_FAN);

			//tringulo
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord, -alt+60, -coord);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 0,  alt+60, -coord);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( coord, -alt+60, -coord);

		glEnd();

		glBegin(GL_TRIANGLE_FAN);

			//triangulo
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord, -alt+60, -coord+150);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 0,  alt+60, -coord+150);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( coord, -alt+60, -coord+150);

		glEnd();
	glDisable(GL_TEXTURE_2D);


	double dimen = 10;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txTelhado);
		glBegin(GL_QUADS);

			//lateral erquerda
			glTexCoord2f(1.0f, 0.0f); glVertex3f( coord+15, -dimen+60-6, -coord-15);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( coord-50,  dimen+60, -coord-15);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( coord-50,  dimen+60,  coord+15+50);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( coord+15, -dimen+60-6,  coord+15+50);

			//lateral direita
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord-15, -dimen+60-6, -coord-15);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord-15, -dimen+60-6,  coord+15+50);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord+50,  dimen+60,  coord+15+50);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-coord+50,  dimen+60, -coord-15);

		glEnd();
	glDisable(GL_TEXTURE_2D);



}

void desenhaPorta(double a){

	int cporta, hporta;

		cporta = 20;
		hporta = 30;

		glColor3f(1,1,1); //DEFINE A COR: BRANCA
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, txPorta);
			glBegin(GL_QUADS);


			glTexCoord2f(1.0f, 0.0f); glVertex3f( -cporta, -hporta-20, -50+a);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( cporta,  -hporta-20, -50+a);
			glTexCoord2f(0.0f, 1.0f); glVertex3f( cporta,  hporta,  -50+a);
			glTexCoord2f(0.0f, 0.0f); glVertex3f( -cporta, hporta,  -50+a);

		glEnd();
		glDisable(GL_TEXTURE_2D);


}

void desenhaPiramide(double coord){

	glColor3f(1,1,1);

	glBegin(GL_TRIANGLE_FAN);

		//frontal
		glColor3f(0,1,0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord-200, -coord-20, -coord+200);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( -200,  coord-20, 200);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord-200, -coord-20, -coord+200);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

		//posterior
		glColor3f(0,1,1);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord-200, -coord-20,  coord+200);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( coord-200, -coord-20,  coord+200);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( -200,  coord-20,  200);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

		//lateral esquerdo
		glColor3f(0,0,1);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( coord-200, -coord-20, -coord+200);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( -200,  coord-20,  200);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord-200, -coord-20,  coord+200);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

		//lateral direito
		glColor3f(1,0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord-200, -coord-20, -coord+200);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord-200, -coord-20,  coord+200);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-200,  coord-20,  200);

	glEnd();

}


void desenhaPlano(double dX, double dY, double dZ, int tx){

	glColor3f(1,1,1); //DEFINE A COR: BRANCA
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tx);
	glBegin(GL_TRIANGLE_FAN);

		glTexCoord2f(0, 0); glVertex3f(-dX, dY, -dZ);
		glTexCoord2f(1, 0); glVertex3f(-dX, dY,  dZ);
		glTexCoord2f(0, 1); glVertex3f( dX, dY,  dZ);
		glTexCoord2f(1, 1); glVertex3f( dX, dY, -dZ);

	glEnd();
	glDisable(GL_TEXTURE_2D);


}

void desenhaCubo(double coord, int tx1){

	glColor3f(1,1,1); //DEFINE A COR: BRANCA
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tx1);
	glBegin(GL_QUADS);

		// Face frontal
		//glColor3f(0,1,0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord, -coord, -coord);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord,  coord, -coord);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( coord,  coord, -coord);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord, -coord, -coord);

		// Face inferior
		//glColor3f(0,1,1);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord, -coord+0.1, -coord);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( coord, -coord+0.1, -coord);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord, -coord+0.1,  coord);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord, -coord+0.1,  coord);


	glEnd();
	glDisable(GL_TEXTURE_2D);	


	glColor3f(1,1,1); //DEFINE A COR: BRANCA
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txJanelaFora);
	glBegin(GL_QUADS);

	//Face Posterior
		//glColor3f(1,0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord, -coord,  coord+50);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( coord, -coord,  coord+50);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( coord,  coord,  coord+50);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-coord,  coord,  coord+50);

	glEnd();
	glDisable(GL_TEXTURE_2D);	

							//CHÃO

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txChao);
	glBegin(GL_QUADS);

		glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord, -coord+0.2, -coord);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( coord, -coord+0.2, -coord);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord, -coord+0.2,  coord+50);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord, -coord+0.2,  coord+50);

	glEnd();
	glDisable(GL_TEXTURE_2D);

		
									//PAREDES
				
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txParede);
	glBegin(GL_QUADS);
	
		// Face lateral direita
		//glColor3f(1,1,0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord+0.1, -coord, -coord);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord+0.1, -coord,  coord+50);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord+0.1,  coord,  coord+50);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-coord+0.1,  coord, -coord);
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
												

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txJanelaFora);
	glBegin(GL_QUADS);
	
		// Face lateral esquerda
		//glColor3f(1,0,1);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( coord, -coord, -coord);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( coord,  coord, -coord);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( coord,  coord,  coord+50);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord, -coord,  coord+50);
	
	
	glEnd();
	glDisable(GL_TEXTURE_2D);
	

}

void desenhaSkyBox(double coord){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txSky6);
	glBegin(GL_QUADS);

		//superior
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-coord,  coord, -coord);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord,  coord,  coord);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( coord,  coord,  coord);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( coord,  coord, -coord);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txSky);
	glBegin(GL_QUADS);
		// Face frontal
		//glColor3f(0,1,0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord, -coord, -coord);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord,  coord, -coord);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( coord,  coord, -coord);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord, -coord, -coord);

	glEnd();
	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txSky5);
	glBegin(GL_QUADS);
		
		// Face lateral esquerda
		//glColor3f(1,0,1);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( coord, -coord, -coord);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( coord,  coord, -coord);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( coord,  coord,  coord);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( coord, -coord,  coord);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, txSky4);
	glBegin(GL_QUADS);

		// Face lateral direita
		//glColor3f(1,1,0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord, -coord, -coord);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-coord, -coord,  coord);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-coord,  coord,  coord);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-coord,  coord, -coord);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glColor3f(1,1,1); //DEFINE A COR: BRANCA
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, txSky3);
		glBegin(GL_QUADS);

			//Face Posterior
			//glColor3f(1,0,0);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-coord, -coord,  coord);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( coord, -coord,  coord);
			glTexCoord2f(1.0f, 1.0f); glVertex3f( coord,  coord,  coord);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-coord,  coord,  coord);

	glEnd();
	glDisable(GL_TEXTURE_2D);

}