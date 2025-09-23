/******************************************************************************
PROJETO DE AUTOMATOS - Prof. Roberto (Bob) Cássio de Araújo

Bruno Germanetti Ramalho         RA10426491
Miguel Piñeiro Coratolo Simões   RA10427085
Thais Ferreira Canguçu           RA10403283

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char* scanner(char* palavra) {
    int index = 0;
	char c;
	
	inicial_q0:
		c = palavra[index++];
	    if (isdigit(c) && c != '0') goto inteiro_q2;
		else if (c == '0') goto zero_unico_q11;
        else if (c == '+' || c == '-') goto sinal_q1;
		else return "<REJEITADO>";

	sinal_q1:
		c = palavra[index++];
		if (isdigit(c) && c != '0') goto inteiro_com_sinal_q6;
		else if (c != '0') goto zero_pos_sinal_inteiro_q10;
        else return "<REJEITADO>";
	
	inteiro_q2:
    	c = palavra[index++];
		if (c == '\0') return "<INTEIRO>";
	    else if (isdigit(c)) goto inteiro_q2;
        else if (c == ',') goto virgula_q4;
        else return "<REJEITADO>";

	flutuante_q3:
	    c = palavra[index++];
	    if (c == '\0') return "<P.FLUTUANTE>";
        else if (c == '0') goto zero_flutuante_q5;
	    else if (isdigit(c) && c != '0') goto flutuante_q3;
		else return "<REJEITADO>";
	    
	virgula_q4:
	    c = palavra[index++];
	    if (c == '0') goto zero_flutuante_q5;
	    else if (isdigit(c) && c != '0')  goto flutuante_q3;
	    else return "<REJEITADO>";
	
	zero_flutuante_q5:
	    c = palavra[index++];
	    if (c == '0') goto zero_flutuante_q5;
	    else if (isdigit(c) && c != '0')  goto flutuante_q3;
		else return "<REJEITADO>";
		
		
	inteiro_com_sinal_q6:
    	c = palavra[index++];
		if (c == '\0') return "<INTEIRO COM SINAL>";
	    if (isdigit(c)) goto inteiro_com_sinal_q6;
        else if (c == ',') goto virgula_com_sinal_q8;
        else return "<REJEITADO>";

	    
	flutuante_com_sinal_q7:
	    c = palavra[index++];
	    if (c == '\0') return "<P.FLUTUANTE COM SINAL>";
        else if (c == '0') goto zero_flutuante_com_sinal_q9;
	    else if (isdigit(c) && c != '0') goto flutuante_com_sinal_q7;
		else return "<REJEITADO>";
	    
	virgula_com_sinal_q8:
	    c = palavra[index++];
	    if (c == '0') goto zero_flutuante_com_sinal_q9;
	    else if (isdigit(c) && c != '0')  goto flutuante_com_sinal_q7;
	    else return "<REJEITADO>";
	
	zero_flutuante_com_sinal_q9:
	    c = palavra[index++];
	    if (c == '0') goto zero_flutuante_com_sinal_q9;
	    else if (isdigit(c) && c != '0')  goto flutuante_com_sinal_q7;
		else return "<REJEITADO>";
	
	zero_pos_sinal_inteiro_q10:
	    c = palavra[index++];
	    if (c == '0') goto zero_pos_sinal_inteiro_q10;
	    else if (c == ',') goto virgula_com_sinal_q8;
	    else if (isdigit(c) && c != '0')  goto inteiro_com_sinal_q6;
		else return "<REJEITADO>";
	
	zero_unico_q11:
		c = palavra[index++];
			if (c == '\0') return "<INTEIRO>";
			else if (isdigit(c) && c != '0') goto inteiro_q2;
			else if (c == '0') goto zeros_sequencia_q12;
 			else if (c == ',') goto virgula_q4;
			else return "<REJEITADO>";
				
	zeros_sequencia_q12:
		c = palavra[index++];
			if (c == '\0') return "<REJEITADO>";
			else if (isdigit(c) && c != '0') goto inteiro_q2;
			else if (c == '0') goto zeros_sequencia_q12; 
			else if (c == ',') goto virgula_q4;
			else return "<REJEITADO>";
}


int main()
{   
    char* palavras[] = {
    "00000000", "+0", "-0", "0,0", "0.0", "0,00000", "1.23", "+1.23", "-1.23", "++++","-----", "+,-",
    "++,-001", "0+0,01", "1,+234", "+2-3,08", "+1,23", "1", "25", "123456789", "+123456789", "-123456789",
    "+1234,5678", "-1234,5678", "21", "-21", "021", "000150", "+0,34", "2,1", "0005,5678",
    "-2,1", "-45,67", "01234", "0002,3", "21,0", "-05,0", "-5,0", "05,5670", ",1", "21,", "1,2,3"
	};

    int num_palavras = sizeof(palavras) / sizeof(palavras[0]);
    for (int i = 0; i < num_palavras; i++) {
        printf("\nPalavra: %16s | Resultado: ", palavras[i]);
        printf("%s", scanner(palavras[i]) );
    }
    return 0;
}
