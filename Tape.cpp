#include <stdio.h>

	int n;//numeros de testes
	float *l,*t;//quanto tempo a fita tem por completo e quantas músicas devem ser armazenadas
	int i=0;//váriavel que auxiliará na permutação
	int j=0;//váriavel que auxiliará na permutação
	float m[10][20];//matriz dos minutos das musicas
	float s[10][20];//matriz dos segundos das musicas
	int qu[2];//armazena a posição da ultima musica armazenada em um dos lados da fita

void lerArquivo(){
	//metodo que lê o arquivo com as informações sobre os testes
	
	char url[]="test.txt";
	FILE *arq;	
	arq = fopen(url, "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		fscanf(arq,"%d\n", &n);
		
		//aqui são iniciados os vetores com o número de posições necessários
		l= new float[n];
		t = new float[n];
				
		int i=0;
		
		for(;i<n;i++){
		fscanf(arq,"%f %f\n", &l[i], &t[i]);//aqui é lido  quanto tempo a fita tem por completo e quantas músicas devem ser armazenadas
		int j=0;
		for(;j<t[i];j++){
		fscanf(arq,"%f %f\n", &m[i][j], &s[i][j]);//aqui é lido os minutos e segundos de cada música
		}
		fscanf(arq,"\n");	
		}
		
	}
	fclose(arq);
}

void ordenarMusicas(int k, int length) {
	//nesse metodo de Insertion Sort é ordenada as musicas a serem testas de acordo com o seu tempo 
	int i, j; 
	float atual, atual_s;

	for (i = 1; i < length; i++) {
		atual = m[k][i];
		atual_s = s[k][i];
		j = i - 1;

		while ((j >= 0) && (atual < m[k][j])) {
			m[k][j + 1] = m[k][j];
			s[k][j + 1] = s[k][j];
			j = j - 1;
		}

		m[k][j + 1] = atual;
		s[k][j + 1] = atual_s;
	}
	
	for(j=0;j<length;j++){
		}	

}


void testeArmazenamento(int k, float m[][20], float s[][20], float soma){
	
	//verificação, caso chegou o limite de tempo daquele lado ou do número de musicas de teste	
    if( soma+(m[k][i]+(s[k][i]/60))>=l[k]/2  || i>=t[k]-1 || j>=2 ){
      qu[j]=i;
  	}
    else{		
		
		for(;j<2;j++){
			
			//verifica se quando somado aquela musica, ultrapassa a metade de tempo da fita, e caso negaivo, é feito a soma
			if( soma+(m[k][i]+(s[k][i]/60))<=l[k]/2){
		soma=soma+(m[k][i]+(s[k][i]/60));
		i++;
	}
		testeArmazenamento(k, m, s, soma);//executa recursão, baseado que enquanto poder ser adicionadas musicas àquele lado, ela continua
	    soma=0;
	}
}

}

int main(void)
{
	//chamada do metodo de leitura do arquivo base do sistema
	lerArquivo();
	int k;
	
	//são executados os testes
	for(k=0;k<n;k++){
		printf("\n\nTeste %d\n%.0f minutos\n\n", k+1,l[k]);
	ordenarMusicas(k, t[k]);//chamada do metodo de ordenação das musicas daquele teste
	testeArmazenamento(k, m,s,0);//chamada do metodo que executara o teste
	
	if(qu[1]==t[k]){//de acordo com o resultado, caso seja positivo aquele tipo de armazenamento, ele mostrará como fazer isso
		int w;
				
				printf("\nLado A\n");
			    for(w=0;w<qu[0];w++)
				printf("%.0f minutos e %.0f segundos\n", m[k][w],s[k][w]);	
				printf("\nLado B\n");
				for(w=qu[0];w<qu[1];w++)
				printf("%.0f minutos e %.0f segundos\n", m[k][w],s[k][w]);	
	}
	else//caso não seja posivel aquele tipo de armazenamento, ele mostrara que não é possivel
	printf("Impossivel gravar todas as musicas nessa fita\n\n\n\n\n\n");
	j=0;
	i=0;
	
	
}

	printf("\n\n\nPress ENTER key to Continue\n");  
	getchar(); 
	
	
}


