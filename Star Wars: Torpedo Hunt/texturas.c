#include "texturas.h"

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

void Textura(void){
		
		texturaObj = carregaTextura("imagens/obj.png");
		texturaNaveWASD = carregaTextura("imagens/falconWASD.png");
		texturaNaveAD = carregaTextura("imagens/xwing.png");
		texturaGameOver = carregaTextura("imagens/gameover.png");
		texturaESC = carregaTextura("imagens/esc.png");
	
			texturaMenu = carregaTextura("imagens/menu.png");
			texturaCredits = carregaTextura("imagens/credits.png");
			texturaControls = carregaTextura("imagens/controls.png");
			texturaSpaceWASD = carregaTextura("imagens/deathstarWASD.png");
			texturaSpaceAD = carregaTextura("imagens/backgroundAD.png");
			texturaPause = carregaTextura("imagens/pause.png");
			texturaReinicia = carregaTextura("imagens/reiniciar.png");
		
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

}

