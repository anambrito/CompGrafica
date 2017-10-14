#include "texturas.h"

void Textura(void){ //textura espaço, nave, objeto
	
	 texturaMenu = SOIL_load_OGL_texture(
        "menu.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	
	 texturaCredits = SOIL_load_OGL_texture(
        "credits.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	
	 texturaControls = SOIL_load_OGL_texture(
        "controls.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	 texturaSpaceWASD = SOIL_load_OGL_texture(
        "deathstarWASD.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	texturaSpaceAD = SOIL_load_OGL_texture(
        "backgroundAD.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	texturaPause = SOIL_load_OGL_texture(
        "pause.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	texturaReinicia = SOIL_load_OGL_texture(
        "reiniciar.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);


	 texturaObj = SOIL_load_OGL_texture(
        "obj.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);


		texturaNaveWASD = SOIL_load_OGL_texture(
		"falconWASD.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	texturaNaveAD = SOIL_load_OGL_texture(
		"xwing.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	texturaGameOver = SOIL_load_OGL_texture(
		"gameover.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

	texturaESC = SOIL_load_OGL_texture(
		"esc.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);

    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    if (texturaSpaceWASD == 0) {
        printf("Erro do SOIL [space]: '%s'\n", SOIL_last_result());
    }

	 if (texturaSpaceAD == 0) {
        printf("Erro do SOIL [space]: '%s'\n", SOIL_last_result());
    }

	if (texturaObj == 0) {
        printf("Erro do SOIL [objeto]: '%s'\n", SOIL_last_result());
    }

	if (texturaNaveWASD == 0) {
		printf("Erro do SOIL [nave]: '%s'\n", SOIL_last_result());
	}

	if (texturaNaveAD == 0) {
		printf("Erro do SOIL [nave]: '%s'\n", SOIL_last_result());
	}

	if (texturaPause == 0) {
		printf("Erro do SOIL [pause]: '%s'\n", SOIL_last_result());
	}

	if (texturaReinicia == 0) {
		printf("Erro do SOIL [reinicia]: '%s'\n", SOIL_last_result());
	}


	if (texturaGameOver == 0) {
		printf("Erro do SOIL [gameover]: '%s'\n", SOIL_last_result());
	}

	if (texturaESC == 0) {
		printf("Erro do SOIL [esc]: '%s'\n", SOIL_last_result());
	}


}

