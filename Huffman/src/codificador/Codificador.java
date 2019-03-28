package codificador;

import java.util.Scanner;

public class Codificador {

    static char[] chaar = new char[256];
    static String[] sequenciaBin = new String[256];
    static int n = 0;

    public static void main(String[] args) {

        Scanner entrada = new Scanner(System.in);

        n = entrada.nextInt();

        entrada.nextLine();

        for (int i = 0; i < n; i++) {

            String Linha = entrada.nextLine();

            sequenciaBin[i] = Linha.substring(2);

            chaar[i] = Linha.charAt(0);

        }

        String sequencia = GerarSequenciaBinario();

        while (sequencia.length() % 8 != 0) {

            sequencia += '0';

        }

        int quantidadeBytes = sequencia.length() / 8;

        int[] decimal = new int[quantidadeBytes];

        for (int k = 0; k < quantidadeBytes; k++) {

            decimal[k] = BinarioDecimal(sequencia, quantidadeBytes);
            sequencia = sequencia.substring(8);
            
        }
        
        System.out.printf("\n%d,",n);
        
        for (int k = 0; k < quantidadeBytes; k++) {
            
            if (k == quantidadeBytes - 1) {
                System.out.printf("%d", decimal[k]);
            } else {
                System.out.printf("%d,", decimal[k]);
            }

        }

    }

    public static int BinarioDecimal(String bin, int quantidadeBytes) {

        int i = 0;

        int decimal = 0;

        while (quantidadeBytes != 0) {

            while (i < 8) {

                if (bin.charAt(i) == '1') {

                    if (i == 0) {
                        decimal += 128;
                    }
                    if (i == 1) {
                        decimal += 64;
                    }
                    if (i == 2) {
                        decimal += 32;
                    }
                    if (i == 3) {
                        decimal += 16;
                    }
                    if (i == 4) {
                        decimal += 8;
                    }
                    if (i == 5) {
                        decimal += 4;
                    }
                    if (i == 6) {
                        decimal += 2;
                    }
                    if (i == 7) {
                        decimal += 1;
                    }

                }

                i++;
            }
            quantidadeBytes--;
            
        }

        return decimal;

    }

    public static String GerarSequenciaBinario() {

        System.out.println();
        
        Scanner entrada = new Scanner(System.in);

        String sequencia = "";

        String palavra = entrada.nextLine();

        for (int i = 0; i < palavra.length(); i++) {

            for (int j = 0; j < n; j++) {

                if (palavra.charAt(i) == chaar[j]) {

                    sequencia += sequenciaBin[j];

                }

            }

        }

        return sequencia;
    }

}
