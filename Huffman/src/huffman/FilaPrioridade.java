package huffman;

import ArvoreBinaria.No;
import java.util.ArrayList;

public class FilaPrioridade {

    private ArrayList<No> fila;

    public FilaPrioridade() {
        fila = new ArrayList<>();
    }

    public void inserir(No elemento) {
        for (int i = 0; i < fila.size(); i++) {
            if (fila.get(i).getQuantidadeOcorrencias() > elemento.getQuantidadeOcorrencias()) {
                fila.add(i, elemento);
                return;
            }
        }
        fila.add(elemento);
    }

    public No retirar() {
        return fila.remove(0);
    }

    public int tamanhoFila() {
        return fila.size();
    }
}
