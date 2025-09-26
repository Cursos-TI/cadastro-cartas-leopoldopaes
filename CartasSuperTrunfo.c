#include <stdio.h>
#include <string.h>
// Função para registro de carta
int registerCard(
		char *estado,
		char codigo[3],
		char cidade[50],
		unsigned long int *população,
		float *area,
		float *pib,
		int *pontosturisticos)
{
	printf("Digite seu estado, escolhendo UMA letra de A até H:\n");
	scanf(" %c", estado);

	printf("Digite código de sua carta, número de 01 à 04:\n");
	scanf("%s", codigo);
	// O código acima, após o enter deixa um espaço vazio em Buffer
	// Com isso utilizei o getchar() para 'pegar' esse espaço vazio, sendo possível assim colocar o nome da cidade na próxima linha
	getchar();

	printf("Digite o nome da Cidade:\n");
	fgets(cidade, 50, stdin);
	// Removendo a quebra de linha no final da string
	cidade[strcspn(cidade, "\n")] = 0;

	printf("Digite sua população:\n");
	scanf("%lu", população);

	printf("Digite sua Área (em km²):\n");
	scanf("%f", area);

	printf("Digite seu PIB:\n");
	scanf("%f", pib);

	printf("Quantos pontos turísticos ela possui?:\n");
	scanf("%d", pontosturisticos);

	return 0;
}
// Função para cálculo de densidade populacional fazendo casting de unsigned long int para float.
float calculodensidade(unsigned long int *população, float *area)
{
	return (float)*população / *area;
}
// Função para cálculo de PIB per Capita transformando bilhões em unidades de reais par ter o valor em reais por pessoa
float pibPerCapitaCalculation(float *pib, unsigned long int *população)
{
	return (*pib * 1000000000) / (float)*população;
}
// Função para cálculo do super poder
float calculatesuperpoder(
		unsigned long int *população,
		float *area,
		float *pib,
		int *pontosturisticos,
		float *pibPerCapita,
		float reverseDensity)
{
	return (float)*população + *area + *pib + (float)*pontosturisticos + *pibPerCapita + reverseDensity;
}
// Funções de comparação para tipo de dados específicos
int compareUnsignedLongInts(unsigned long int value1, unsigned long int value2)
{
	return value1 > value2;
}

int compareFloats(float value1, float value2)
{
	return value1 > value2;
}

int compareDensities(float value1, float value2)
{
	return value1 < value2;
}
// Funções de comparação para tipo de dados específicos

// Função de retorna o ganhador levando em conta resultado da comparação (sempre carta 1 sobre carta 2)
const char *getResult(int compareResult)
{
	if (compareResult == 1)
	{
		return "Carta 1 venceu";
	}
	return "Carta 2 venceu";
}

int main()
{
	char estado1, estado2;
	char codigo1[3], codigo2[3];
	char cidade1[50], cidade2[50];
	unsigned long int população1, população2;
	float area1, area2;
	float pib1, pib2;
	int pontosturisticos1, pontosturisticos2;
	float populaçãoDensid1, populaçãoDensid2;
	float pibPerCapita1, pibPerCapita2;
	float superpoder1, superpoder2;

	printf("CADASTRO DA CARTA 1...\n");

	registerCard(&estado1, codigo1, cidade1, &população1, &area1, &pib1, &pontosturisticos1);
	// Cálculo para Densidade populacional e PIB per capita Carta 1
	populaçãoDensid1 = calculodensidade(&população1, &area1);
	pibPerCapita1 = pibPerCapitaCalculation(&pib1, &população1);
	superpoder1 = calculatesuperpoder(&população1, &area1, &pib1, &pontosturisticos1, &pibPerCapita1, (1 / populaçãoDensid1));

	printf("------------CADASTRO DA CARTA 2------------\n");

	registerCard(&estado2, codigo2, cidade2, &população2, &area2, &pib2, &pontosturisticos2);
	// Cálculo para Densidade populacional e PIB per capita Carta 2
	populaçãoDensid2 = calculodensidade(&população2, &area2);
	pibPerCapita2 = pibPerCapitaCalculation(&pib2, &população2);
	superpoder2 = calculatesuperpoder(&população2, &area2, &pib2, &pontosturisticos2, &pibPerCapita2, (1 / população2));

	printf("-----EXIBIÇÃO DAS CARTAS-----\n");

	printf("Carta 1:\n");
	printf("Estado: %c\n", estado1);
	printf("Código: %c%s\n", estado1, codigo1);
	printf("Nome da Cidade: %s\n", cidade1);
	printf("População: %lu\n", população1);
	printf("Área: %.2f km²\n", area1);
	printf("PIB: %.2f bilhões de reais\n", pib1);
	printf("Número de Pontos Turísticos: %d\n", pontosturisticos1);
	printf("Densidade Populacional: %.2f hab/km²\n", populaçãoDensid1);
	printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

	printf("\n");

	printf("Carta 2:\n");
	printf("Estado: %c\n", estado2);
	printf("Código: %c%s\n", estado2, codigo2);
	printf("Nome da Cidade: %s\n", cidade2);
	printf("População: %lu\n", população2);
	printf("Área: %.2f km²\n", area2);
	printf("PIB: %.2f bilhões de reais\n", pib2);
	printf("Número de Pontos Turísticos: %d\n", pontosturisticos2);
	printf("Densidade Populacional: %.2f hab/km²\n", populaçãoDensid2);
	printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

	printf("\n");
	printf("-----Resultado do duelo entre as cartas-----\n");
	printf("\n");
	// Declaração de variáveis para serem alteradas mais na frente
	const char *populaçãoResult;
	const char *areaResult;
	const char *pibResult;
	const char *pontosturisticosResult;
	const char *densidResult;
	const char *pibPerCapitaResult;
	const char *superpoderResult;

	populaçãoResult = getResult(compareUnsignedLongInts(população1, população2));
	areaResult = getResult(compareFloats(area1, area2));
	pibResult = getResult(compareFloats(pib1, pib2));
	pontosturisticosResult = getResult(compareFloats((float)pontosturisticos1, (float)pontosturisticos2));
	densidResult = getResult(compareDensities(populaçãoDensid1, populaçãoDensid2));
	pibPerCapitaResult = getResult(compareFloats(pibPerCapita1, pibPerCapita2));
	superpoderResult = getResult(compareFloats(superpoder1, superpoder2));

	printf("População: %s (%d)\n", populaçãoResult, compareUnsignedLongInts(população1, população2));
	printf("Área: %s (%d)\n", areaResult, compareFloats(area1, area2));
	printf("PIB: %s (%d)\n", pibResult, compareFloats(pib1, pib2));
	printf("Pontos Turísticos: %s (%d)\n", pontosturisticosResult, compareFloats((float)pontosturisticos1, (float)pontosturisticos2));
	printf("Densidade Populacional: %s (%d)\n", densidResult, compareDensities(populaçãoDensid1, populaçãoDensid2));
	printf("PIB per Capita: %s (%d)\n", pibPerCapitaResult, compareFloats(pibPerCapita1, pibPerCapita2));
	printf("Super Poder: %s (%d)\n", superpoderResult, compareFloats(superpoder1, superpoder2));

	printf("\n");
	printf("------Comparação de Cartas (Atributo: Área):\n");
	printf("\n");
	printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
	printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);

	if (area1 > area2)
	{
		printf("Resultado: Carta 1 (%s) venceu!", cidade1);
	} else {
		printf("Resultado: Carta 2 (%s) venceu!", cidade2);






	}
}

   return 0;
}
