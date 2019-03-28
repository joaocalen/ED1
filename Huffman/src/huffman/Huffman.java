package huffman;

import ArvoreBinaria.*;
import java.util.ArrayList;
//import decodificador.*;
import compactador.*;
import java.io.IOException;

class Prefixo {

    public byte ValorByte;
    public String prefixo;

    public Prefixo(byte b, String p) {
        this.ValorByte = b;
        this.prefixo = p;
    }
}


public class Huffman {

    private static FilaPrioridade fila;
    public static ArrayList<Prefixo> prefixos;
    public static int[] b = new int[222];
    public static int[] f = new int[222];
    public static int n;
    
    public static void main(String[] args) throws IOException {
        
        Compactador.main();
             
        fila = new FilaPrioridade();
        prefixos = new ArrayList<>();

        // ler pares byte:frequencia
        // primeira linha: N (quantidade de pares)
        // próximas N linhas: Bi Fi (Bi é o i-ésimo byte, Fi é a quantidade de ocorrências do byte Bi)
        
        for (int i = 0; i < n; i++) {
            Folha par = new Folha((byte) b[i], f[i]);
            fila.inserir(par);
        }

        // executar o algoritmo de huffman
        while (fila.tamanhoFila() > 1) {
            No x = fila.retirar();
            No y = fila.retirar();
            NoInterno novo = new NoInterno(x, y, x.getQuantidadeOcorrencias() + y.getQuantidadeOcorrencias());
            fila.inserir(novo);
        }

        // extrair da arvore que esta na fila os prefixos para os bytes
        if (fila.tamanhoFila() > 0) {
            percurso(fila.retirar(), "");

        }

        // apresentar a tabela de prefixos
        
        System.out.print("\n\n");
        System.out.print("Apresentando tabela de prefixos: \n");
        
        
       for (Prefixo p : prefixos) {
            System.out.println(((int) p.ValorByte) + " " + p.prefixo);

        }
               
        // Decodificador.main();
        

    }

    private static void percurso(No noAtual, String prefixoAtual) {
        if (noAtual instanceof Folha) {
            Folha folha = (Folha) noAtual;
            Prefixo p = new Prefixo(folha.getValor(), prefixoAtual);
            prefixos.add(p);
        } else {
            NoInterno ramo = (NoInterno) noAtual;
            if (ramo.getRamificacaoEsquerda() != null) {
                percurso(ramo.getRamificacaoEsquerda(), prefixoAtual + "0");
            }
            if (ramo.getRamificacaoDireita() != null) {
                percurso(ramo.getRamificacaoDireita(), prefixoAtual + "1");
            }
        }
    }
}
