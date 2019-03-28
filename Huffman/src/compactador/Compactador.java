package compactador;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import huffman.Huffman;

public class Compactador {

    private static double aux;
    public static int bytesOcorridos = 0;
    public static void main() throws IOException {
        
        Huffman huffman = new Huffman();

        System.out.print("Informe o nome do arquivo: ");
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        String nomeArquivo = entrada.readLine();
        FileInputStream arquivo = new FileInputStream(new File(nomeArquivo));

        int[] ocorrencias = new int[256];
        int valorByte;
        while ((valorByte = arquivo.read()) >= 0) {
            ocorrencias[valorByte]++;
        }
        arquivo.close();

        
        for (int i = 0; i < 256; i++) {
            if (ocorrencias[i] != 0) {
                bytesOcorridos++;
            }
        }

        // apresentação dos dados na saída
        System.out.println(bytesOcorridos);
        huffman.n = bytesOcorridos;
        int j = 0;
        for (valorByte = 0; valorByte < 256; valorByte++) {
            if (ocorrencias[valorByte] != 0) {
                System.out.printf("%d %d\n", valorByte, ocorrencias[valorByte]);
                huffman.b[j] = valorByte;
                huffman.f[j] = ocorrencias[valorByte];
                j++;
            }
            
        }
        
        
        
        FileOutputStream saida = new FileOutputStream(new File(nomeArquivo + ".hfn"));

        //(1 byte) escrever a quantidade de bytes ocorridos no arquivo original (-1)
        saida.write(bytesOcorridos - 1);
        // (1 byte) escrever a quantidade de bytes para representar ocorrências
        int max = 0;
        for (int i = 0; i < 256; i++) {
            if (ocorrencias[i] > max) {
                max = ocorrencias[i];
            }
        }
        int numBytes = (int) Math.ceil(((1 + Math.log(aux) / Math.log(2))) / 8.0);
        saida.write(numBytes);
        // para cada byte ocorrido no arquivo original:
        int x = 0;
        
              
        for (int ocorrencia : ocorrencias) {
            
            if (ocorrencia > 0) {
                // - escrever o byte
                saida.write(x);
                // - escrever a quantidade de ocorrências
                
                int[] bytes = new int[numBytes];
                for (int i = numBytes - 1; i >= 0; i--) {
                    bytes[i] = ocorrencia % 256;
                    ocorrencia = ocorrencia / 256;
                    
                }
                
                for (int i = 0; i < numBytes; i++) {
                    saida.write(bytes[i]);
                }

            }
            x++;
        }

        // - escrever a quantidade de ocorrências
        // 66000 = 00000000 00000001 00000001 11010000
        // 66000 /(256*256*256) = 0  ; 66000 %(256*256*256) = 66000
        // 66000 /(256*256) = 1      ; 66000 % (256*256) = 464
        // 464/256 = 1
        // 208 % 256 = 208
               
               
    }
               
}   