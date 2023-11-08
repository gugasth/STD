package engtelecom.std.service;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicLong;

import org.springframework.stereotype.Component;

import engtelecom.std.entities.Pessoa;

/**
 * Classe com a idéia de representar um banco de dados em memória
 */
@Component
public class PessoaService {
    private ArrayList<Pessoa> agenda;
    private AtomicLong contador;

    public PessoaService(){
        this.agenda = new ArrayList<>();
        this.contador = new AtomicLong();

        this.cadastrarPessoa(new Pessoa(null, "Juca", "juca@example.org"));
        this.cadastrarPessoa(new Pessoa(null, "Ana", "ana@example.org"));
    }

    /**
     * Método que lista todas as pessoas
     */
    public List<Pessoa> buscarTodas(){
        return this.agenda;
    }

    public Pessoa cadastrarPessoa(Pessoa p){
        p.setId(this.contador.incrementAndGet()); // funciona bem pra concorrência

        this.agenda.add(p);
        
        return p;
    }
}
