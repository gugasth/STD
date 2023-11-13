package engtelecom.std.exeptions;

public class PessoaNaoEncontradaException extends RuntimeException {

    public PessoaNaoEncontradaException(Long id){

        super("Pessoa nao encontrada com o id: " + id.toString());
    }

    
}
