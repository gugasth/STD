package engtelecom.std.controller;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

import engtelecom.std.entities.Saudacao;


/**
 * Controller vai ficar direcionando pedidos de um lugar pra outro
 * sufixo da classe deve ser Controller, por boas práticas.
 * 
 */
@RestController
public class SaudacaoController {
    
    @GetMapping("/ola")
    public String olaMundo(){
        return "Olá mundo";
    }

    @GetMapping("/saudacao")
    public Saudacao saudacao(
        @RequestParam(value = "nome", defaultValue= "mundo") String nome){
            
        Saudacao s = new Saudacao(1L, nome);

        return s;
    }


}
