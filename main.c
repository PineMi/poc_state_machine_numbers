/******************************************************************************
PROJETO DE AUTOMATOS - Prof. Roberto (Bob) Cássio de Araújo

Bruno Germanetti Ramalho         RA10426491
Miguel Piñeiro Coratolo Simões   RA10427085
Thais Ferreira Canguçu           RA10403283

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// O alfabeto é [0-9,+,-,.,,]
char* scanner(char* palavra) {
    int index = 0;
	char c;
	
	inicial_q0:
		c = palavra[index++];
	    if (isdigit(c) && c != '0') goto inteiro_q2;  // n diferente de 0
		else if (c == '0') goto zero_unico_q11;       // 0
        else if (c == '+' || c == '-') goto sinal_q1; // sinais
		else if (c == ',') goto poco;                 // vírgula 
		if (c == '\0') return "<REJEITADO>";          // Não é estado final
		else goto poco;

	sinal_q1:
		c = palavra[index++];
		if (isdigit(c) && c != '0') goto inteiro_com_sinal_q6; // n diferente de 0
		else if (c == '0') goto zero_pos_sinal_inteiro_q10;    // zero
		else if (c == ',' || c == '+' || c == '-') goto poco;  // Simbolo ou virgula
		if (c == '\0') return "<REJEITADO>";                   // Não é estado final
        else goto poco;                    
	
	inteiro_q2:
    	c = palavra[index++];              
		if (c == '\0') return "<INTEIRO>";          // Final
	    else if (isdigit(c)) goto inteiro_q2;       // Qualquer dígito
        else if (c == ',') goto virgula_q4;         // Vírgula
		else if (c == '+' || c == '-') goto poco;   // Simbolo ou virgula
        else goto poco;          

	flutuante_q3:
	    c = palavra[index++];                       
	    if (c == '\0') return "<P.FLUTUANTE>";                // Final 
        else if (c == '0') goto zero_flutuante_q5;            // Zero
	    else if (isdigit(c) && c != '0') goto flutuante_q3;   // n diferente de 0
		else if (c == ',' || c == '+' || c == '-') goto poco; // virgula e simbolos
		else goto poco;
	    
	virgula_q4:
	    c = palavra[index++];
	    if (c == '0') goto zero_flutuante_q5;                  // Zero
	    else if (isdigit(c) && c != '0')  goto flutuante_q3;   // n diferente de 0
		else if (c == ',' || c == '+' || c == '-') goto poco;  // virgulas e simbolos
		else if (c == '\0') return "<REJEITADO>";                   // Não é estado final
	    else goto poco;
	
	zero_flutuante_q5:
	    c = palavra[index++];
	    if (c == '0') goto zero_flutuante_q5;                  // Zero
	    else if (isdigit(c) && c != '0')  goto flutuante_q3;   // n diferente de 0
		else if (c == ',' || c == '+' || c == '-') goto poco;  // virgulas e simbolos	
		else if (c == '\0') return "<REJEITADO>";                   // Não é estado final
		else goto poco;
		
		
	inteiro_com_sinal_q6:
    	c = palavra[index++];
		if (c == '\0') return "<INTEIRO COM SINAL>";         // Final
	    else if (isdigit(c)) goto inteiro_com_sinal_q6;           // Qualquer n
        else if (c == ',') goto virgula_com_sinal_q8;        // vírgula 
		else if (c == '+' || c == '-') goto poco;  			// simbolos	
        else goto poco;

	    
	flutuante_com_sinal_q7:
	    c = palavra[index++];
	    if (c == '\0') return "<P.FLUTUANTE COM SINAL>";			  // Final
        else if (c == '0') goto zero_flutuante_com_sinal_q9;          // zero
	    else if (isdigit(c) && c != '0') goto flutuante_com_sinal_q7; // n diferente de 0
		else if (c == ',' || c == '+' || c == '-') goto poco;         // virgulas e simbolos	
		else goto poco;
	    
	virgula_com_sinal_q8:
	    c = palavra[index++];											
	    if (c == '0') goto zero_flutuante_com_sinal_q9;					// Zero
	    else if (isdigit(c) && c != '0')  goto flutuante_com_sinal_q7;  // n diferente de 0
	    else if (c == ',' || c == '+' || c == '-') goto poco;  			// virgulas e simbolos
		else if (c == '\0') return "<REJEITADO>";                       // Não é estado final
		else goto poco;
	
	zero_flutuante_com_sinal_q9:
	    c = palavra[index++];
	    if (c == '0') goto zero_flutuante_com_sinal_q9;                  // Zero
	    else if (isdigit(c) && c != '0')  goto flutuante_com_sinal_q7;   // n diferente de 0
		else if (c == ',' || c == '+' || c == '-') goto poco;  			 // virgulas e simbolos
		else if (c == '\0') return "<REJEITADO>";                        // Não é estado final
		else goto poco;
	
	zero_pos_sinal_inteiro_q10:
	    c = palavra[index++];
	    if (c == '0') goto zero_pos_sinal_inteiro_q10;                   // Zero
	    else if (c == ',') goto virgula_com_sinal_q8;                    // Vírgula
	    else if (isdigit(c) && c != '0')  goto inteiro_com_sinal_q6;     // n diferente de 0
		else if (c == '+' || c == '-') goto poco;  			             // Simbolos
		else if (c == '\0') return "<REJEITADO>";                        // Não é estado final
		else goto poco;
	
	zero_unico_q11:
		c = palavra[index++];
		if (c == '\0') return "<INTEIRO>";                  // Final
		else if (isdigit(c) && c != '0') goto inteiro_q2;   // n diferente de 0
		else if (c == '0') goto zeros_sequencia_q12;        // 0  
		else if (c == ',') goto virgula_q4;                 // virgula
		else if (c == '+' || c == '-') goto poco;  			// Simbolos
		else goto poco;
				
	zeros_sequencia_q12:
		c = palavra[index++];
		if (c == '\0') return "<REJEITADO>";			  // Não é final
		else if (isdigit(c) && c != '0') goto inteiro_q2; // n diferente de 0
		else if (c == '0') goto zeros_sequencia_q12;      // 0
		else if (c == ',') goto virgula_q4;               // vírgula 
		else if (c == '+' || c == '-') goto poco;  		  // Simbolos
		else goto poco;
	
	poco: 
		c = palavra[index++];
		if (isdigit(c) || c == '+' || c == '-' || c == ',') goto poco;
		else if (c == '\0') return "<REJEITADO>";
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
