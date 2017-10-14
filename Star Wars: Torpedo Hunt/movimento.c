#include "movimento.h"

double calc_dist(torp n1, torp n2){
	return sqrt(pow((n2.x-n1.x),2)+pow((n2.y-n1.y),2));
} 

void bordasWASD (){

	int i;

	if((posicaoNaveY > (telaLimite-.7)) || posicaoNaveY < -(telaLimite -.7)){ //se chega perto das bordas gameover
		telaGameOver = 1;
		velocidade = 0;
		velocidadeTangencial = 0;
		velocidadeAngular = 0;
	}
	
	if(posicaoNaveX > telaLimite){ //se a nave chegar perto da borda x passa p outro lado 
		Mix_PlayChannel( -1, somPortal, 0 );
		posicaoNaveX = -telaLimite;
		for(i=1; i <= tamSquad; i++){
			squad[i].x = -telaLimite;
			squad[i].y = posicaoNaveY;
		} 
	}

	if(posicaoNaveX < (-telaLimite)){	
		Mix_PlayChannel( -1, somPortal, 0 );
		posicaoNaveX = telaLimite;
		for(i=1; i <= tamSquad; i++){
			squad[i].x = telaLimite;
			squad[i].y = posicaoNaveY;
		}
	}

	if(posicaoObj.x > telaLimite) //se as novas coord do obj foram maiores q 5 passa p outro lado 
	posicaoObj.x = -telaLimite;

	if(posicaoObj.y < (-telaLimite))	//se as novas coord do obj foram menores q -5 passa p outro lado 
	posicaoObj.y = telaLimite;
}

void bordasAD(){

	int i;



	//portal	

 	if(posicaoNaveX>telaLimite)	{
		Mix_PlayChannel( -1, somPortal, 0 );
		posicaoNaveX = -telaLimite;
		for(i=1; i <= tamSquad; i++){
			squad[i].x = -telaLimite;
			squad[i].y = posicaoNaveY;
		}
		
	}

	if(posicaoNaveX<(-telaLimite)){
		Mix_PlayChannel( -1, somPortal, 0 );
		posicaoNaveX = telaLimite;
		for(i=1; i <= tamSquad; i++){
			squad[i].x = telaLimite;
			squad[i].y = posicaoNaveY;
		}
	}

	
	if(posicaoNaveY>telaLimite){
		Mix_PlayChannel( -1, somPortal, 0 );
		posicaoNaveY = -telaLimite;
		for(i=1; i <= tamSquad; i++){
			squad[i].y = -telaLimite;
			squad[i].x = posicaoNaveX;
		}
	}

	if(posicaoNaveY<(-telaLimite)){
		Mix_PlayChannel( -1, somPortal, 0 );
		posicaoNaveY = telaLimite;
		for(i=1; i <= tamSquad; i++){
			squad[i].y = telaLimite;
			squad[i].x = posicaoNaveX;
		}
	}
}


void atualiza(int idx) { //movimento
	
	posicaoAnteriorX = posicaoNaveX;			//sava posiçao para o vetor auxiliar de posiçao do Squad
	posicaoAnteriorY = posicaoNaveY; 

  
	if(telaMenu == 0) {

		if(ModoDeJogo == 0){
		

			if((tecla == 'a' )|| ( tecla == 'd')){ 			//se a teclas correspoderem ao eixo X 

				posicaoNaveX += cos(angulo) * velocidade; 	//só a velocidade 
				posicaoNaveY += 0; 							//eixo Y =0
	
			}
	
			else {		
				posicaoNaveX += 0;
				posicaoNaveY += cos(angulo) * velocidade;
		
			}


			bordasWASD();	 
	
		}

		if(ModoDeJogo == 1){ 	
	
			GLfloat orientacaoEmRadianos = grausParaRadianos(rotacao);
			posicaoNaveX += cos(orientacaoEmRadianos) * velocidadeTangencial;
			posicaoNaveY += sin(orientacaoEmRadianos) * velocidadeTangencial;
			rotacao += velocidadeAngular;
			
			bordasAD();

		}

		int i;
		if(tamSquad > 0){
			float distanciaMinima = 1.2;
			squad[0].x = posicaoNaveX;
			squad[0].y = posicaoNaveY;

			for (i=1; i<=tamSquad; i++){
				double distancia = calc_dist(squad[i-1], squad[i]);
				if(distancia>distanciaMinima){
					float difX, difY;
					difX = squad[i-1].x - squad[i].x;
					difY = squad[i-1].y - squad[i].y;
					difX = (distancia-distanciaMinima) * (difX/distancia);
					difY = (distancia-distanciaMinima) * (difY/distancia);
					squad[i].x += difX;
					squad[i].y += difY;				
					squad[i].rotacao = radianoParaGraus(-difX/(distancia-distanciaMinima));
				}			
	
			}

		}	 

	}
	
	glutPostRedisplay();
    glutTimerFunc(20, atualiza, 0);
}
