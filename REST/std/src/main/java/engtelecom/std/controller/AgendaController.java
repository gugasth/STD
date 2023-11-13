package engtelecom.std.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.bind.annotation.RestController;

import engtelecom.std.entities.Pessoa;
import engtelecom.std.exeptions.PessoaNaoEncontradaException;
import engtelecom.std.service.PessoaService;

@RestController
@RequestMapping("/pessoas")
public class AgendaController {

    @Autowired
    private PessoaService pessoaService;

    @GetMapping
    public List<Pessoa> buscarTodas(){
        return this.pessoaService.buscarTodas();
    }

    @GetMapping("/{id}")
    public Pessoa buscarPessoaPorId(@PathVariable Long id){
        Pessoa p = pessoaService.buscarPorId(id);
        
        if (p != null){
            return p;
        }

        throw new PessoaNaoEncontradaException(id);
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public Pessoa adicionarPessoa(@RequestBody Pessoa p){
        return this.pessoaService.cadastrarPessoa(p);
    }

    @PutMapping
    @ResponseStatus(HttpStatus.OK)
    public Pessoa atualizarPessoa(@RequestBody Pessoa pessoa){
        Pessoa p = this.pessoaService.atualizar(pessoa);
        if (p != null){
            return p;
        }
        throw new PessoaNaoEncontradaException(pessoa.getId());
    }

    @DeleteMapping("/{id}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void excluirPessoa(@PathVariable long id){
        if (!this.pessoaService.excluir(id)){
            throw new PessoaNaoEncontradaException(id);
        }
    }
    
}
