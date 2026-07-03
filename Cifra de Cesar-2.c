        char Alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        char AlfabetoMaiusculo[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
        #include <ctype.h>
        #include <stdbool.h>
        #include <math.h>
        #include <locale.h>

        int Buscar(char letra)
        {
            if (isupper(letra))
            {
                char *pos = strchr(AlfabetoMaiusculo, letra);
                int posicao = pos - AlfabetoMaiusculo;
                return posicao;
            }
            else
            {
                char *pos = strchr(Alfabeto, letra);
                int posicao = pos - Alfabeto;
                return posicao;
            }
            return -1;}
            char Criptografar(bool checkUpper, int posicaoinputalfabeto, int pular)
            {
                if (pular < 0)
                {
                    pular = 26 + pular;
                }
                if (checkUpper)
                {
                    return AlfabetoMaiusculo[abs(((posicaoinputalfabeto + pular) % 26))];
                }
                else
                {
                    return Alfabeto[abs((posicaoinputalfabeto + pular) % 26)];
                }


            }
            int main()
            {
                setlocale(LC_ALL, "Portuguese");
                char input[100];
                char criptografado[100];
                int pular;
                int posicaoinputalfabeto;
                bool checkUpper;
                printf("Digite a mensagem que deseja criptografar: ");
                fgets(input, sizeof(input), stdin);
                printf("Quantas letras quer pular?(Caso queira pular para trás, digite um número negativo): ");
                scanf("%d", &pular);
                for (size_t i = 0; i < strlen(input); i++)
                {
                    char x = input[i];
                    if (x == ' ' || x == '\n' || isalpha(x) == 0)
                    {
                        criptografado[i] = input[i];
                        continue;
                    }
                    if (isupper(input[i]))
                    {
                        posicaoinputalfabeto = Buscar(input[i]);
                        checkUpper = true;
                        criptografado[i] = Criptografar(checkUpper,posicaoinputalfabeto, pular);
                    }
                    else
                    {
                        posicaoinputalfabeto = Buscar(input[i]);
                        checkUpper = false;
                        criptografado[i] = Criptografar(checkUpper,posicaoinputalfabeto, pular);
                    }
                }
                printf("Mensagem criptografada: %s\n", criptografado);

                return 0;
            }
