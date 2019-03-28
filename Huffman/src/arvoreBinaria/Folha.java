package ArvoreBinaria;

public class Folha extends No {
    private byte valor;

    public Folha(byte valor, int quantidadeOcorrencias) {
        super(quantidadeOcorrencias);
        this.valor = valor;
    }  

    public byte getValor() {
        return valor;
    }
   
    public void setValor(byte valor) {
        this.valor = valor;
    }  
    
}
