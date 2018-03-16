/*
	Este código simula el popular juego de las DAMAS INGLESAS
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define T 8

char tablero[T][T];
int turno = 0;
char n=220;
char b=223;
char e=' ';
char B=184;
char N=169;
int auxl=0;

//Prototipo de las funciones que usaremos en este proyecto:

void SetColor(int Color);
void posob(int x,int y);
void pintarlimites(void);
void imprimirtablero(void);
void llenartablero(void);
void moverpieza(int x,int y,int direccion);
void moverdama(int x,int y, int direccion, int desplazamiento);
void recuento(void);
void jugar(void);
void guardar(void);
void reanudar(void);

// Función para añadir color:

void SetColor(int Color){
	WORD wColor;

 	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	 CONSOLE_SCREEN_BUFFER_INFO csbi;
                                                               
 	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 	{
   		wColor = (csbi.wAttributes & 0xF0) + (Color & 0x0F);
      	SetConsoleTextAttribute(hStdOut, wColor);
 	}
 return;
}

// Función gotoxy (seleccionar coordenadas):

 void posob(int x,int y){
	HANDLE hprueba;
	hprueba= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cpos;
	Cpos.X=x;
	Cpos.Y=y;
	SetConsoleCursorPosition(hprueba,Cpos);
}

// Función para pintar las rayas del tablero:

 void pintarlimites(){
 	
 	int i,j;
 	
 	                              
 	SetColor(15);
 	
 	for(i=6;i<53;i++){                                         //A continuación imprimimos en pantalla los símbolos ASCII requeridos
 		if(i==11||i==17||i==23||i==29||i==35||i==41||i==47){   //para imprimir las casillas el tablero, para ello utilizamos la función posob(i,j)    
 			 posob(i,3);printf("%c",203);                      
 			 posob(i,19);printf("%c",202);
		 }
		
		else{
			 posob(i,3);printf("%c",205);
 			 posob(i,19);printf("%c",205);
		} 
	 }
 	
 	

	 	for(j=4;j<19;j++){
 		if(j%2==0){
 		 posob(5,j);printf("%c",186);
 			 posob(53,j);printf("%c",186);
		 }
		
		else{
			 posob(5,j);printf("%c",204);
 			 posob(53,j);printf("%c",185);
		} 
	 }
	
	 for(i=6;i<53;i++){
	 	for(j=4;j<19;j++){
	 		if(j%2!=0){
	 			 posob(i,j);printf("%c",205);
	 			
			 }
			 
		 }
	 }
	
	for(j=4;j<19;j++){
	 	for(i=6;i<53;i++){
	 		if(i==11||i==17||i==23||i==29||i==35||i==41||i==47){
 			 posob(i,j);printf("%c",186);
		 }
	 		
			 
		 }
	 }
	 
	 for(j=4;j<19;j++){
	 	if(j%2!=0){
	 		for(i=6;i<53;i++){
	 			if(i==11||i==17||i==23||i==29||i==35||i==41||i==47){
	 				 posob(i,j);printf("%c",206);
	 				
				 }
			 }
	 		
		 }
	 	
	 }
	 
	 
	
	 posob(5,3);printf("%c",201);
	 posob(5,19);printf("%c",200);
	 posob(53,3);printf("%c",187);
	 posob(53,19);printf("%c",188);
}

// Función para imprimir las fichas en la consola:

void imprimirtablero(){
	
    int m,n;
  	
  	printf("\n\n");
  	printf("   ");
  	
  	
  		for(n=0;n<8;n++){
  			 
  			printf("     %i",n);    
		  }                         
  	
		  printf("\n\n");           //Las variables m,n las utilizamos para imprimir en pantalla los números de 
		  printf("  ");             //las casillas del tablero,mediantes bucles for.
		  
		for(m=0;m<8;m++){
			 
			printf(" %i",m);
			printf("\n\n  ");
		} 

    pintarlimites();

	int i,j;              //Los bucles siguientes los empleamos para rellenar el tablero 
	int x,y;              //con las fichas, según la matriz tablero[x][y]
	
	for(x=0,i=8;x<T,i<53;x++,i=i+6){
		for(y=0,j=4;y<T,j<19;y++,j=j+2){
			if(tablero[x][y]==b||tablero[x][y]==B){
				
			    //posob(i,j);
				SetColor(12);printf("%c",tablero[x][y]);SetColor(15);
			}
			                                                                         
			else{
				
				
				//posob(i,j);SetColor(9);
				printf("%c",tablero[x][y]);SetColor(15);
			}
			
			
			
		}
	}
	printf("\n\n\n");
}  

// Función para poner las fichas en el tablero:  
  
void llenartablero(){
 	
 	int x,y;  //Recorremos la matriz mediante los valores de las variables x e y, y de esta forma incializamos el tablero con las posiciones iniciales de las fichas
 	
 	for(x=0;x<T;x++){
 		for(y=0;y<T;y++){
 			if(y<3){
 				
 				if((x+y)%2==0){
 					
 					tablero[x][y]=n;
 					
				 }
				
				else {
					tablero[x][y]=e;
					
				} 
			 }
			
			else if(y>4){
				
				if((x+y)%2==0){
					
					
					tablero[x][y]=b;
					
					
				}
				
				else{
					tablero[x][y]=e;
					
				} 
			}
			
			else{
					tablero[x][y]=e;
					
				}  
		 }
	 }

}  

//Función para mover la pieza por el tablero:
 
 void moverpieza(int x,int y,int direccion){
 	
 	
 	if(turno==0){
 		
 		
 		
 		if(tablero[x][y]!=b){
 			        printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar(); //Vuelve a repetirse (turno==0)
		 }
		
		else if(tablero[x][y]==b){
			
			
			if(direccion==1){
			
				
				if((x-1)>=0&&(y-1)>=0){
					
			    
				
				if (tablero[x-1][y-1]==e){
					
					tablero[x][y]=e;
					tablero[x-1][y-1]=b;
					system("cls");
					
					if(y-1==0){
        	        tablero[x-1][y-1]=B;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		}
					
					 
				}
				
					
				  
				else if(tablero[x-1][y-1]==n||tablero[x-1][y-1]==N){
				  	
				  	
				  	if((x-2)>=0&&(y-2)>=0){
				  	
					
					if(tablero[x-2][y-2]==e){
						
					  	tablero[x][y]=e;
						tablero[x-1][y-1]=e;
						tablero[x-2][y-2]=b;
						system("cls");
						imprimirtablero();
						printf("Has comido una ficha en (%d,%d).\n",x,y);
						system("pause");
						
						system("cls");
						
						if(y-2==0){
        	        tablero[x-2][y-2]=B;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		} 
						
					}
					
					else if(tablero[x-2][y-2]!=e){
					printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
				  	
				  	
				  }
				
				  
					
					
				}
				
				else if(tablero[x-1][y-1]==b||tablero[x-1][y-1]==B){
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }
				
			}
			
			else if((x-1)<0||(y-1)<0){
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				    
			    	
				}
				
			}
			
			
			else if(direccion==2){
				
				if((x+1)<8&&(y-1)>=0){
			
				
				 if (tablero[x+1][y-1]==e){
					
					tablero[x][y]= e;
					tablero[x+1][y-1]=b;
					system("cls");
					
					if(y-1==0){
        	        tablero[x+1][y-1]=B;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		}
					 
				}
				
					
				  
				else if(tablero[x+1][y-1]==n||tablero[x][y]==N){
				  	
				  	
				  	if((x+2)<8&&(y-2)>=0){
				  	
					
					if(tablero[x+2][y-2]==e){
						
					  	tablero[x][y]= e;
						tablero[x+1][y-1]=e;
						tablero[x+2][y-2]=b;
						system("cls");
						imprimirtablero();
						printf("Has comido una ficha en (%d,%d).\n",x,y);
						system("pause");
						
						system("cls");
						 
						if(y-2==0){
        	        tablero[x+2][y-2]=B;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		}
						
					}
					
					else if(tablero[x+2][y-2]!=e){
					printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
				  	
				  	
				  }
				
				  
					
					
				}
				
				else if(tablero[x+1][y-1]==b||tablero[x-1][y-1]==B){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }
				
			}
			
			else if((x+1)>=8||(y-1)<0){
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
			
			 
		
			
			
 	
 }
 
    
    
	   
        turno = 1;
 }  
    else if(turno==1){
    	
    	if(tablero[x][y]!=n){
    		
 			printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
		 }
		
		else if(tablero[x][y]==n){
			
			if(direccion==1){
				
				if((x-1)>=0&&(y+1)<8){
			
				
				 if (tablero[x-1][y+1]==e){
					
					tablero[x][y]= e;
					tablero[x-1][y+1]=n;
					system("cls");
					
					if(y+1==7){
        	        tablero[x-1][y+1]=N;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		}
					 
				}
				
					
				  
			   	else if(tablero[x-1][y+1]==b||tablero[x-1][y+1]==B){
				  	
				  	
				  	if((x-2)>=0&&(y+2)<8){
				  	
					
					if(tablero[x-2][y+2]==e){
						
					  	tablero[x][y]= e;
						
						tablero[x-1][y+1]=e;
						tablero[x-2][y+2]=n;
						system("cls");
						imprimirtablero();
						printf("Has comido una ficha en (%d,%d).\n",x,y);
						system("pause");
				     	system("cls");
						
						if(y+2==7){
        	        tablero[x-2][y+2]=N;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		}
						 
					}
					
					else if(tablero[x-2][y+2]!=e){
						
					printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
				  	
				  	
				  }
				
				  
					
					
				}
				
				else if(tablero[x-1][y+1]==n||tablero[x-1][y+1]==N){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }
				
			}
			
			else if((x-1)<0||(y+1)>=8){
				
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
			
			
			else if(direccion==2){
				
				if((x+1)<8&&(y+1)<8){
			
				
				 if (tablero[x+1][y+1]==e){
					
					tablero[x][y]= e;
					tablero[x+1][y+1]=n;
					system("cls");
					
					if(y+1==7){
        	        tablero[x+1][y+1]=N;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		}
					 
				}
				
					
				  
				else if(tablero[x+1][y+1]==b||tablero[x+1][y+1]==B){
				  	
				  	
				  	if((x+2)<8&&(y+2)<8){
				  	
					
					if(tablero[x+2][y+2]==e){
						
					  	tablero[x][y]= e;
						tablero[x+1][y+1]=e;
						tablero[x+2][y+2]=n;
						system("cls");
						imprimirtablero();
						printf("Has comido una ficha en (%d,%d).\n",x,y);
						system("pause");
				     	system("cls");
						
						if(y+2==7){
        	        tablero[x+2][y+2]=N;
		            system("cls");
		            imprimirtablero();
		            printf("\t¡TU ficha ES AHORA UN DAMA!\n");
		            system("pause");
		            system("cls");
       	
        	
		}
						 
						
					}
					
					else if(tablero[x+2][y+2]!=e){
					printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
				  	
				  	
				  }
				
				  
					
					
				}
				
				else if(tablero[x+1][y+1]==n||tablero[x+1][y+1]==N){
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }
				
			}
			
			else if((x+1)>=8||(y+1)>=8){
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
			
			 
			
			
			
 	
 }
       
        turno = 0;
    	
	}
 
 
  
 }
 
//Función para mover una dama: 
 
void moverdama(int x,int y, int direccion, int desplazamiento){
	
	if(turno==0){
		
		if(tablero[x][y]!=B){
    		
 			printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
 			 
 			
 			
		 }
		
		else if(tablero[x][y]==B){
		
		
		if(direccion==1){
			
			if(desplazamiento==1){
				
				if((x-1)<8&&(y+1)>=0){
					
					if(tablero[x-1][y+1]==e){
					
					 tablero[x][y]= e;
					 tablero[x-1][y+1]=B;
					 system("cls");
				}
					
				    else if(tablero[x-1][y+1]==n||tablero[x-1][y+1]==N){
				  	
				  	
				  	    if((x-2)<8&&(y+2)>=0){
				  	
					
					     if(tablero[x-2][y+2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x-1][y+1]=e;
						 tablero[x-2][y+2]=B;
						 system("cls");
						 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x-2][y+2]!=e){
						
						printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x-2)<0||(y+2)>8){
				    printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			
			    	
				}
				
			}
	                   
					 else if(tablero[x-1][y+1]==b||tablero[x-1][y+1]==B){
				  	
				  printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x-1)<0||(y+1)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				    
			    	
				}
		
			else if(desplazamiento==2){
				
				if((x-1)<8&&(y-1)>=0){
					
					if(tablero[x-1][y-1]==e){
					
					 tablero[x][y]= e;
					 tablero[x-1][y-1]=B;
					 system("cls");
				}
					
				    else if(tablero[x-1][y-1]==n||tablero[x-1][y-1]==N){
				  	
				  	
				  	    if((x-2)<8&&(y-2)>=0){
				  	
					
					     if(tablero[x-2][y-2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x-1][y-1]=e;
						 tablero[x-2][y-2]=B;
						 system("cls");
						 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x-2][y-2]!=e){
						
						 printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x-2)<0||(y-2)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				   
			    	
				}
				
			}
	                   
					 else if(tablero[x-1][y-1]==b||tablero[x-1][y-1]==B){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x-1)<=0||(y-1)<=0){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				    
			    	
				}
				
			}
			
		
		
		else if(direccion==2){
			
			if(desplazamiento==1){
				
				if((x+1)<8&&(y+1)>=0){
					
					if(tablero[x+1][y+1]==e){
					
					 tablero[x][y]= e;
					 tablero[x+1][y+1]=B;
					 system("cls");
				}
					
				    else if(tablero[x+1][y+1]==n||tablero[x+1][y+1]==N){
				  	
				  	
				  	    if((x+2)<8&&(y+2)>=0){
				  	
					
					     if(tablero[x+2][y+2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x+1][y+1]=e;
						 tablero[x+2][y+2]=B;
						 system("cls");
						 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x+2][y+2]!=e){
						
					printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x+2)<0||(y+2)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
	                   
					 else if(tablero[x+1][y+1]==b||tablero[x+1][y+1]==B){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x+1)>8||(y+1)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
			
			else if(desplazamiento==2){
				
				if((x+1)<8&&(y-1)>=0){
					
					if(tablero[x+1][y-1]==e){
					
					 tablero[x][y]= e;
					 tablero[x+1][y-1]=B;
					 system("cls");
				}
					
				    else if(tablero[x+1][y-1]==n||tablero[x+1][y-1]==N){
				  	
				  	
				  	    if((x+2)<8&&(y-2)>=0){
				  	
					
					     if(tablero[x+2][y-2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x+1][y-1]=e;
						 tablero[x+2][y-2]=B;
						 system("cls");
						 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x+2][y-2]!=e){
						
						 printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x+2)<0||(y-2)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
	                   
					 else if(tablero[x+1][y-1]==b||tablero[x+1][y-1]==B){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x+1)>8||(y-1)<=0){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
			
		}
	}
		
	}
	}
	

	turno=1;
	
}
	else if(turno==1){
		
		if(tablero[x][y]!=N){
    		
 		printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
 		
		 }
		
		else if(tablero[x][y]==N){
		
		
		if(direccion==1){
			
			if(desplazamiento==1){
				
				if((x-1)<8&&(y+1)>=0){
					
					if(tablero[x-1][y+1]==e){
					
					 tablero[x][y]= e;
					 tablero[x-1][y+1]=N;
					 system("cls");
				}
					
				    else if(tablero[x-1][y+1]==b||tablero[x-1][y+1]==B){
				  	
				  	
				  	    if((x-2)<8&&(y+2)>=0){
				  	
					
					     if(tablero[x-2][y+2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x-1][y+1]=e;
						 tablero[x-2][y+2]=N;
						 system("cls");
					   	 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x-2][y+2]!=e){
						
						 printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x-2)<0||(y+2)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
			    	
				}
				
			}
	                   
					 else if(tablero[x-1][y+1]==n||tablero[x-1][y+1]==N){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x-1)<0||(y+1)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
	}
			else if(desplazamiento==2){
				
				if((x-1)<8&&(y-1)>=0){
					
					if(tablero[x-1][y-1]==e){
					
					 tablero[x][y]= e;
					 tablero[x-1][y-1]=N;
					 system("cls");
				}
					
				    else if(tablero[x-1][y-1]==b||tablero[x-1][y-1]==B){
				  	
				  	
				  	    if((x-2)<8&&(y-2)>=0){
				  	
					
					     if(tablero[x-2][y-2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x-1][y-1]=e;
						 tablero[x-2][y-2]=N;
						 system("cls");
						 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x-2][y-2]!=e){
						
						 printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x-2)<0||(y-2)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				}
				
			}
	                   
					 else if(tablero[x-1][y-1]==n||tablero[x-1][y-1]==N){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x-1)<=0||(y-1)<=0){
			    
			    printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
	
	}
		
		else if(direccion==2){
			
			if(desplazamiento==1){
				
				if((x+1)<8&&(y+1)>=0){
					
					if(tablero[x+1][y+1]==e){
					
					 tablero[x][y]= e;
					 tablero[x+1][y+1]=N;
					 system("cls");
				}
					
				    else if(tablero[x+1][y+1]==b||tablero[x+1][y+1]==B){
				  	
				  	
				  	    if((x+2)<8&&(y+2)>=0){
				  	
					
					     if(tablero[x+2][y+2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x+1][y+1]=e;
						 tablero[x+2][y+2]=N;
						 system("cls");
						 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x+2][y+2]!=e){
						
						 printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x+2)<0||(y+2)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
	                   
					 else if(tablero[x+1][y+1]==n||tablero[x+1][y+1]==N){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x+1)>8||(y+1)>8){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
			
			else if(desplazamiento==2){
				
				if((x+1)<8&&(y-1)>=0){
					
					if(tablero[x+1][y-1]==e){
					
					 tablero[x][y]= e;
					 tablero[x+1][y-1]=N;
					 system("cls");
				}
					
				    else if(tablero[x+1][y-1]==b||tablero[x+1][y-1]==B){
				  	
				  	
				  	    if((x+2)<8&&(y-2)>=0){
				  	
					
					     if(tablero[x+2][y-2]==e){
						
					  	 tablero[x][y]= e;
						 tablero[x+1][y-1]=e;
						 tablero[x+2][y-2]=N;
						 system("cls");
						 imprimirtablero();
						 printf("Has comido una ficha en (%d,%d).\n",x,y);
						 system("pause");
				     	 system("cls");
					}
					
					     else if(tablero[x+2][y-2]!=e){
						
						 printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
						
					}
					
				}
				
				
				       else if((x+2)<0||(y-2)>8){
			    
			    printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
				}
				
			}
	                   
					 else if(tablero[x+1][y-1]==n||tablero[x+1][y-1]==N){
				  	
				  	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
				  	
				  }  
					   		
	 	}
	 	
	 	           else if((x+1)>8||(y-1)<=0){
			    	
			    	printf("MOVIMIENTO NO VALIDO, REPITE LA JUGADA.\n");
			    	system("pause");
			    	system("cls");
			    	
			    	jugar();
			    	
			    	
				}
				
			}
			
		}
	
		
	
	}
		
		turno=0;
		
}
 
}

//Función para ganar por ausencia de fichas:

void recuento(){
	
	int cont0=0,cont1=0;
	int x,y;
	for(x=0;x<T;x++){
		for(y=0;y<T;y++){
			
			if(tablero[x][y]==n||tablero[x][y]==N){
				
				cont1++;
			}
			
			else if(tablero[x][y]==b||tablero[x][y]==B){
				cont0++;
			}
		}
	}
	
	if(cont1==0){
		system("cls");
		
		printf("\n\t*****  *****  ** **  *****    *****  *   *  *****  *****\n");
		printf("\t*      *****  *****  *        *   *  *   *  *      *   *\n");
		printf("\t* ***  *   *  *****  ***      *   *  *   *  ***    *****\n");
		printf("\t*  **  *****  ** **  *        *   *   * *   *      * *  \n");
		printf("\t*****  *   *  ** **  *****    *****    *    *****  *  **\n\n");
		
		printf("\t\tHAN GANADO LOS BLANCOS!\n");
		system("pause");
		
		auxl=1;
	
		
	}
	
	else if(cont0==0){
		system("cls");
		
		printf("\t\t*****  *****  ** **  *****    *****  *   *  *****  *****\n");
		printf("\t\t*      *****  *****  *        *   *  *   *  *      *   *\n");
		printf("\t\t* ***  *   *  *****  ***      *   *  *   *  ***    *****\n");
		printf("\t\t*  **  *****  ** **  *        *   *   * *   *      * *  \n");
		printf("\t\t*****  *   *  ** **  *****    *****    *    *****  *  **\n\n");
		
		printf("\t\tHAN GANADO LOS NEGROS!\n");
		system("pause");
		
		
		
		auxl=1;
		
	}
	
	else{
		
		
	}
	
	
	
}

//Función para recibir el movimiento de la pieza:

void jugar(){
  	
   int x, y, direccion, desplazamiento;
   int salir,g;
   
   
   
   volver:
   
   imprimirtablero();
   printf("\t\t  Para salir presione 8...\n");
   if(turno==1)
   {
      printf("\tSeleccione la ficha AZUL que desea mover...\n");
       
   }
   else if(turno==0)
   {
      printf("\tSeleccione la ficha ROJA que desea mover...\n");
       
   }
   
   
   printf("\t\tIntroduzca la columna:");
   scanf("%d",&x);
   printf("\t\tIntroduzca la fila:");
   scanf("%d",&y);
   
   
   
   if(x==8||y==8){
   	system("cls");
   	printf("\tSeguro que quieres abandonar la partida?\n\t\t[1]SI\n\t\t[2]NO\n");
   	scanf("%d",&salir);
   	switch(salir){
   		case 1:{
   			system("cls");
   			printf("\tQuieres guardar la partida antes de salir?\n\t\t[1]SI\n\t\t[2]NO\n");
   			scanf("%d",&g);
   			
   			if(g==1){
   				guardar();
   					
			   }
			    system("cls");
   				printf("Gracias por jugar a las DAMAS en C\n");
   				exit(8);
   			
			break;
		   }
		case 2:{
			system("cls");
			goto volver;
			break;
		} 
		default:{
			system("cls");
			goto volver;
			break;
		}  
	   }
   }
   //Distinguimos el movimiento entre fichas normales y damas
   
   if(tablero[x][y]==B){
   	
   	if (turno==0){
   		
   	printf("\tElija el tipo de desplazamiento:\n\t1)Abajo\n\t2)Arriba\n");
   	scanf("%d",&desplazamiento);
   	printf("\tElija la direccion del movimiento,\n\t1)Izquierda\n\t2)Derecha\n");
    scanf("%d",&direccion);
   	
   	
   	system("pause");
    moverdama(x,y,direccion,desplazamiento);
    
   }
   	
   
   else if(turno==1){
   	
   	printf("Movimiento no valido.\n");
   	turno=0;
    
   }
   	
   }
   
   else if(tablero[x][y]==N){
   	
   	  if (turno==0){
   	
   	  printf("Movimiento no valido.\n");
   	  turno=1;
   	  
    
   }
   	
   
      else if(turno==1){
      	
   	 printf("\tElija el tipo de desplazamiento:\n\t1)Abajo\n\t2)Arriba\n");
   	 scanf("%d",&desplazamiento);
   	 printf("\tElija la direccion del movimiento,\n\t1)Izquierda\n\t2)Derecha\n");
     scanf("%d",&direccion);
   	 
   	
   	 system("pause");
     moverdama(x,y,direccion,desplazamiento);
   	 printf("Movimiento no valido.\n");
    
   }
   
  
   	
   }
   
   
   else{
   
   printf("\t\tElija la direccion del movimiento,\n\t1)Izquierda\n\t2)Derecha\n");
   scanf("%d",&direccion);
   
   system("pause");
   moverpieza(x, y, direccion);
}
   recuento();
   
   
   
}

// Función para guardar la partida:

void guardar(){
	
	int x,y;
	
	FILE *fich;		// creamos un fichero
	
	fich = fopen("JuegoDamas.txt", "w");	//abre el fichero con formato .txt modo lectura/escritura

	if (fich==NULL)						//Si no se creo el fichero manda un mensaje de error
	{
			printf("\n\t\tEl fichero no se ha abierto!!\n");  
		}

	
	fseek(fich, 0, SEEK_SET);		//puntero que va al principio del fichero

	const short	int	numChars = sizeof(tablero);
		
		char buffer[numChars];  //se crea un buffer para almacenar datos	 
			
			for (x = 0; x < T; x++) {
				for (y = 0; y < T; y++) {
					buffer[x+y]=tablero[x][y];		//guarda los caracteres contenidos en el buffer																	
				}
			}		fwrite(buffer,numChars,numChars,fich); //almacena los datos del buffer en el archivo .txt
	fclose(fich);
		}
	
//Función para reanudar la partida:
		
void reanudar(){
	
	int x, y;

	FILE *fich;
	
	fich = fopen("JuegoDamas.txt", "r");  //abre un fichero .txt modo lectura
		if(fich==NULL)//si no existe el fichero 
			{
			SetColor(12);printf("\n\n\t\tNo existe ninguna partida guardada!!");SetColor(15); //imprime mensaje de error
			}else {				//si existe, entonces:
		
	fseek(fich, 0, SEEK_SET);		//puntero que va al principio del fichero

	fseek(fich, 0, SEEK_END);		//recorre hasta el final

	const short int numChars = ftell(fich);	//devuelve un offset (desplazamiento), que va a ser el tamaño del archivo

	char buffer[numChars];		//se le asigna al buffer el tamaño del fichero

	 fseek(fich, 0, SEEK_SET); //deja el puntero al principio del fichero
	
		while (!feof(fich))	{	//mientras no llegue al final del fichero

		fread(buffer, numChars, 1, fich); // lee los datos contenidos en el fichero
		
	
			for (x = 0; x < T; x++) {
				for (y = 0; y < T; y++) {	
					tablero[x][y]=buffer[x+y]; 		// le asigna a la matriz tablero, los datos leidos 
					}							  // del fichero contenidos en el buffer
				}
			}
				SetColor(12);printf("\t\t - - Partida Reanudada - -");SetColor(15);
				jugar();		// llamada a la funcion jugar para continuar con la partida reanudada

	}
	fclose(fich);
}  
		
// Función principal:

int main(){
 	
 	int opcion,aux=0;
 	
 	
 	volver:
 		
 	
 	// Menú:
 	do{
	 
 	
	SetColor(15);printf("\n\t\t\tBIENVENIDO AL JUEGO:\n\n");
	SetColor(10);printf("\t\t****  \t******\t**  **\t******\t******\n");SetColor(15);
	SetColor(11);printf("\t\t*  ** \t**  **\t******\t**  **\t**    \n");SetColor(15);
	SetColor(12);printf("\t\t*  ***\t**  **\t**  **\t**  **\t******\n");SetColor(15);
	SetColor(13);printf("\t\t*  ** \t******\t**  **\t******\t    **\n");SetColor(15);
	SetColor(14);printf("\t\t****  \t**  **\t**  **\t**  **\t******\n\n");SetColor(15);
	

	printf("\tMENU:\n 1)Partida nueva\n 2)Cargar partida\n 3)Salir\n\n");
	
	
	scanf("%d",&opcion);
	
	
	system("pause");
	system("cls");
	
	
	switch(opcion){
		case 1:{
			
			llenartablero();
 	        while(auxl!=1){
 	        	jugar();
			 }
 	    	aux=1;
 	    	system("cls");
			break;
		}
		
		case 2:{
			reanudar();
			aux=1;
			break;
		}
		
		case 3:{
			system("cls");
		    printf("Gracias por jugar a las DAMAS en C\n");
		    system("pause");
		    exit(1);
		    aux=1;
			break;
		}
		
		default:{
			
			break;
		}
	}
	
}while(aux!=1);
	// Finaliza menú.
	 
    if(aux==1){
    	
    	int recargar;
    	
    	while(recargar!=2&&recargar!=1){
		system("cls");
    	printf("\tQuieres volver a jugar?\n\t\t[1]SI\n\t\t[2]NO\n");
    	scanf("%d",&recargar);
    	system("cls");
    	}
    	if(recargar==1){
    		auxl=0;
    		aux=0;
    		if(turno==1)turno=0;
    		else turno=1;
    		
    		goto volver;
		}
		
		else if(recargar==2){
			
			system("cls");
		    printf("Gracias por jugar a las DAMAS en C\n");
		    system("pause");
			
		}
    	
	} 	
 
 }

