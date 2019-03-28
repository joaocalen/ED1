package ArvoreBinaria;

public class NoInterno extends No {
    private No ramificacaoEsquerda;
    private No ramificacaoDireita;

    public NoInterno(No ramificacaoEsquerda, No ramificacaoDireita, int quantidadeOcorrencias) {
        super(quantidadeOcorrencias);
        this.ramificacaoEsquerda = ramificacaoEsquerda;
        this.ramificacaoDireita = ramificacaoDireita;
    } 

    public No getRamificacaoEsquerda() {
        return ramificacaoEsquerda;
    }

    public void setRamificacaoEsquerda(No ramificacaoEsquerda) {
        this.ramificacaoEsquerda = ramificacaoEsquerda;
    }
    
    public No getRamificacaoDireita() {
        return ramificacaoDireita;
    }

    public void setRamificacaoDireita(No ramificacaoDireita) {
        this.ramificacaoDireita = ramificacaoDireita;
    }
}
