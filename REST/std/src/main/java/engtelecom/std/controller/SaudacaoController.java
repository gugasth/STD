package engtelecom.std.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import engtelecom.std.entities.Saudacao;

@RestController
public class SaudacaoController {

    @GetMapping("/ola")
    public String olaMundo(){
        return "Ola mundo";
    }

    @GetMapping("/saudacao")
    public Saudacao saudacao(@RequestParam(value = "nome", defaultValue = "mundo") String nome){

        Saudacao s = new Saudacao(1L , nome);

        return s;
    }
    
}
