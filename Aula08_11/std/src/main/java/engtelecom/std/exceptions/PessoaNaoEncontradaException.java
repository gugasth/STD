package engtelecom.std.exceptions;

public class PessoaNaoEncontradaException extends RuntimeException{
    public PessoaNaoEncontradaException(Long id){
        
        super ("Pessoa não encontrada com o id: " + id.toString());
    }
}
