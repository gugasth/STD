package engtelecom.std.entities;

import lombok.AllArgsConstructor;
import lombok.Data;
/**
 * Classe que representa uma pessoa
 */
@Data
@AllArgsConstructor
public class Pessoa {

    /** id da pessoa */
    private Long id;

    /** nome da pessoa */
    private String nome;

    /** email da pessoa */
    private String email;
    
    
}
