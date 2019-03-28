package Decodificador;

import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Decodificador {

    static char[] caracter = new char[222];
    static String[] bits = new String[222];
    static int numLinhas;

    public static void main() throws IOException {

        Scanner ler = new Scanner(System.in);
        numLinhas = ler.nextInt();
        ler.nextLine();
        
        if (numLinhas > 222) {
            System.out.println("Número muito grande");
        } else {
            for (int i = 0; i < numLinhas; i++) {
                String Linha = ler.nextLine();
                bits[i] = Linha.substring(2);
                caracter[i] = Linha.charAt(0);
                for (int j = 0; bits[i].length() > j; j++) {
                    if ((bits[i].charAt(j) == '1') || (bits[i].charAt(j) == '0')) {
                    } else {
                        System.out.println("Digite um número binário por favor");
                        System.exit(0);
                    }
                }
            }
            numerosVirgulas();
        }
    }
    
    private static String DecBin(int x) {
        String bin = "";
        if (x > 0) {
            if (x % 2 == 0) {
                bin = (DecBin(x / 2) + "0");
            } else {
                bin = (DecBin(x / 2) + "1");
            }
        }
        return bin;
    }

    private static void numerosVirgulas() {

        Scanner entrada = new Scanner(System.in);
        String virgula = entrada.nextLine();
        StringTokenizer st = new StringTokenizer(virgula, ",");
        int qtdNum = 0;
        int[] valor = new int[222];
        String[] valorString = new String[222];

        while (st.hasMoreTokens()) {
            valorString[qtdNum] = st.nextToken();
            qtdNum++;
        }
        for (int i = 0; i < qtdNum; i++) {
            valor[i] = Integer.parseInt(valorString[i]);
        }

        String binarioString = "";

        int qtdLetras = valor[0];
        String binarioString1 = "";
        for (int i = 1; i < qtdNum; i++) {

            binarioString1 = DecBin(valor[i]);
            while (binarioString1.length() < 8) {
                binarioString1 = "0" + binarioString1;
            }
            binarioString = binarioString + binarioString1;
        }
        String aux = "";
        int posicaoNaString = 0;
        String palavraFinal = "";

        for (int j = 0; j < qtdLetras; j++) {
            boolean executar = true;
            while (executar) {
                if (binarioString.charAt(posicaoNaString) == '0') {
                    aux = aux + '0';
                } else {
                    aux = aux + '1';
                }
                for (int k = 0; k < numLinhas; k++) {
                    if (aux.equals(bits[k])) {
                        palavraFinal = palavraFinal + caracter[k];
                        binarioString = binarioString.substring(aux.length());
                        aux = "";
                        executar = false;
                    }
                }
                posicaoNaString = aux.length();
            }
        }
        System.out.println(palavraFinal);
    }
}
