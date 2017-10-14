#include "teclado.h"


void menu(unsigned char key){ //tela MENU

	if(telaMenu == 1){  //só ativa as funções se a tela estiver em aberto

			telaPause = 0;
			telaReinicia =0;
			telaESC = 0;
			telaGameOver = 0;

		if(tamSquad != 0){ //se o vetor de torpedos tiver preenchido, zerar todas as variaveis
			
			posicaoNaveX = 0;
			posicaoNaveY = 0;
			velocidade = 0;
			velocidadeTangencial = 0; //velocidade inicial tangencial
			velocidadeAngular = 0;	//velocidade inicial angular
			telaReinicia = 0;
			tamSquad = 0;
		
		}

		if(posicaoNaveX != 0 || posicaoNaveY != 0){ // posição inicial da Nave
			
			posicaoNaveX = 0;
			posicaoNaveY = 0;

		}

		switch (key){

			case 'e': //ativar MODE 0
			case 'E': 
				Mix_PlayChannel( -1, somMenu, 0 );
				velocidade = velocidadeInicial;
				velocidadeTangencial = 0.05;
				velocidadeAngular = 0.5;	
				ModoDeJogo = 0;
				telaMenu = 0;
			break;

			case 'h': //ativar MODE 1
			case 'H': 
				Mix_PlayChannel( -1, somMenu, 0 );
				velocidade = velocidadeInicial;
				velocidadeTangencial = 0.05;	
				velocidadeAngular = 0.5;	
				ModoDeJogo = 1;
				telaMenu = 0;
			break;

			case 'c':
			case 'C':
				Mix_PlayChannel( -1, somMenu, 0 );
				pausar(key);
				telaMenu = 0;
				telaCreditos = 1;

			break;

			case 27:
				Mix_PlayChannel( -1, somMenu, 0 );
				printf("1\n");
				telaCreditos = 0;
				telaComandos = 0;
				telaMenu = 1;
	
			break;

			case 't':
			case 'T':
				Mix_PlayChannel( -1, somMenu, 0 );
				telaMenu = 0;
				telaComandos = 1;				
			break;
		
			case 'q': //sair
			case 'Q':
				Mix_PlayChannel( -1, somMenu, 0 );
				exit(0);
			break;
	

		}


	}


}

void pausar(unsigned char key){

	if(ModoDeJogo == 0){ //pausa o jogo
		pause = velocidade;  
		velocidade = 0;
		
	}

	else{				//pausa o jogo
		
		pause = velocidadeTangencial;
		velocidadeTangencial = 0;
		pause2 = velocidadeAngular;
		velocidadeAngular = 0;
		
	}

}

void despausar(unsigned char key){

	if(ModoDeJogo == 0){

		telaPause = 0;
		telaReinicia = 0;
		telaESC = 0;
		velocidade = pause;
		
	}	

	else{

		velocidadeTangencial = pause;
		velocidadeAngular = pause2; 
		telaPause = 0;
		telaReinicia = 0;
		telaESC = 0;

	}


}


void reiniciar(unsigned char key){ //função q reinicia

	telaPause = 0;

	switch(key){

		case 'r':
		case 'R':
	
		//TELA DE DESEJA REINICIAR? (Y/N)
			Mix_PlayChannel( -1, somMenu, 0 );
			telaReinicia = 1;
			pausar(key);
			
		break;
		
		case 'y':
		case 'Y':
			
			//reinicia o jogo					
			Mix_PlayChannel( -1, somMenu, 0 );
			posicaoNaveX = 0;
			posicaoNaveY = 0;
			velocidade = velocidadeInicial;
			velocidadeTangencial = 0.05; //velocidade inicial tangencial
			velocidadeAngular = 0.5;	//velocidade inicial angular
			telaReinicia = 0;
			tamSquad = 0;

		break;
	
		case 'n':
		case 'N':

			//despausa o jogo 		
		Mix_PlayChannel( -1, somMenu, 0 );
		telaReinicia = 0;
		telaPause = 0;
		despausar(key);
		
		break;
	}


}


void tecladoWASD(unsigned char key){ //MODE 0

	switch(key){

	//direções do jogo 

		case 'a':
			angulo = M_PI;		//angulo para direção
			tecla = 'a';		//direção do eixo	
			rotacao = 90;		//angulo da imagem
		break;

		case 's':
			angulo = -3*M_PI/2;
			tecla = 's';
			rotacao = 180;
		break;

		case 'd':
			angulo = 2*M_PI;	
			tecla = 'd';
			rotacao = 270;
		break;

		case 'w':
			angulo = M_PI/2 ;
			tecla = 'w';
			rotacao = 360;	
		break;

	//velocidades do jogo
	
		case '=':
			Mix_PlayChannel( -1, somMais, 0 );
			velocidade += speed;
		break;

		case '-':
			Mix_PlayChannel( -1, somMenos, 0 );
			velocidade -= speed;
		break;

	//com SHIFT precionada aumenta/diminui em dobro

		case '+':
			Mix_PlayChannel( -1, somMais, 0 );
			Mix_PlayChannel( -1, somMais, 0 );
			velocidade += 2*speed;
		break;

		case '_':
			Mix_PlayChannel( -1, somMenos, 0 );
			Mix_PlayChannel( -1, somMenos, 0 );
			velocidade -= 2*speed;
		break;

	//PAUSE
	
		case 'p':
		case 'P':

			Mix_PlayChannel( -1, somMenu, 0 );			

			if((velocidade != 0)){

				telaPause=1;
				pausar(key);
			}

			else 

				despausar(key);

			break;
	//REINICIA			

		case 'r':
		Mix_PlayChannel( -1, somMenu, 0 );
		telaReinicia = 1;
		break;
		
	}

	//chama a função

	if(telaReinicia == 1)
	reiniciar(key);

}

void tecladoAD(unsigned char key){ //MODE 1
	
	switch(key){

	//direções do jogo 

		case 'a':
			velocidadeAngular += 0.05;
		break;

		case 'd':
			velocidadeAngular -= 0.05;
		break;

		default:
		break;		

	//velocidades do jogo	

		case '=':
			Mix_PlayChannel( -1, somMais, 0 );
			velocidadeTangencial += speed;
		break;

		case '-':
			Mix_PlayChannel( -1, somMenos, 0 );
			velocidadeTangencial -= speed;
		break;

	//com SHIFT precionada aumenta/diminui em dobro

		case '+':
			Mix_PlayChannel( -1, somMais, 0 );
			Mix_PlayChannel( -1, somMais, 0 );
			velocidadeTangencial += 2*speed;
		break;


		case '_':
			Mix_PlayChannel( -1, somMenos, 0 );
			Mix_PlayChannel( -1, somMenos, 0 );
			velocidadeTangencial -= 2*speed;
		break;
	
	//PAUSE

		case 'p':
		case 'P':
	
		Mix_PlayChannel( -1, somMenu, 0 );

		if((velocidadeTangencial != 0)){

			telaPause=1;
			pausar(key);

		}

		else 
			despausar(key);

		break;

	//REINICIA

		case 'r':
			telaReinicia = 1;
		break;


	}

		//Chama a função

		if(telaReinicia == 1)
		reiniciar(key);

	
}

void GameOver(unsigned char key){ //função GAMEOVER

		
	switch(key){

		case 'r':
		case 'R':

			//reinicia todos os valores de posição e movimento
			Mix_PlayChannel( -1, somMenu, 0 );
			posicaoNaveX = 0;
			posicaoNaveY = 0;
			velocidade = velocidadeInicial;
			velocidadeTangencial = 0.05; //velocidade inicial tangencial
			velocidadeAngular = 0.5;	//velocidade inicial angular
			telaPause = 0;
			telaReinicia = 0;
			telaGameOver = 0;
			tamSquad = 0;


		break;

		case 'q':
		case 'Q':
			//sai do jogo 
			Mix_PlayChannel( -1, somMenu, 0 );
			telaGameOver = 0;
			telaMenu = 1;
			
		break;
	}

	

}

void esc(unsigned char key){


	switch(key) {

		case 'n':
		case 'N':
			Mix_PlayChannel( -1, somMenu, 0 );
			telaESC =0;
		break;

		case 'y':
		case 'Y': 
			Mix_PlayChannel( -1, somMenu, 0 );
			telaMenu = 1;
		break;

		default:
		break;

	}


}

void teclado(unsigned char key, int a, int b){ //função principal do teclado

	//ativa as teclas do mode 0

	if(telaMenu == 1)
	menu(key);

	if(ModoDeJogo == 0)
	tecladoWASD(key);
	//ativa as teclas do mode 1	

	if(ModoDeJogo == 1) 		
	tecladoAD(key);

	//ativa a tela GAMEOVER e chama a função

	if(telaGameOver == 1) 
	GameOver(key);

	if((telaCreditos == 1) || (telaComandos ==1 )){

		switch (key) {
	
		case 27:
			Mix_PlayChannel( -1, somMenu, 0 );
			telaCreditos = 0;
			telaComandos = 0;
			telaMenu = 1;
		break;

		}

	}


	if((telaMenu == 0) && (telaComandos == 0) && (telaCreditos == 0)){

		switch (key) {
		
			case 27:
				Mix_PlayChannel( -1, somMenu, 0 );
				telaESC = 1;
			break;
		
			case 'm':
			case 'M':
			
				Mix_PlayChannel( -1, somMenu, 0 );

				if(Mix_PausedMusic() == 1)
				Mix_ResumeMusic();
			
				else
				Mix_PauseMusic();

			break;

		}

		if(telaESC==1){
			esc(key); 
		}
	}
		
}


